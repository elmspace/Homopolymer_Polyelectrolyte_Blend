void FreeEnergy( ){

  int maxIter=1000; 
  int i,j,k,iter,chain,ii,jj;
  int msg;

  double currentfE, oldfE, deltafE; 
  double QA,QB,QI; 
  double fEW, fEchi, fES, fE_charge; 
  double deltaW;
  double fE_homo;
  

  msg=1;
  oldfE=1.0e2;
  std::ofstream outputFile("./fE.dat");
  do{
   
    Wave_Vectors(0);   //
    currentfE=0.0;
    deltafE=0.0;
  
    iter=0;  
    
    do{
      iter++;
    
      fEW=0.0;
      fEchi=0.0;
      fES=0.0;
      
      QA=Phi_A( );
      QB=Phi_B( );
      QI=Phi_I( );
      Phi_e();
      Solve_PB_Equation( );
      Incompressibility( );
    
      fEW=0.0;
      fEchi=0.0;
      deltaW=0.0;           
      fE_charge=0.0;


      // Calculating the gradient of the electrostatic potential
      Gradient(V,0,dxyz,Gradient_V_x);
      Gradient(V,1,dxyz,Gradient_V_y);
      Gradient(V,2,dxyz,Gradient_V_z);

      // Calculating the contribution to the free energy from electrostatics
      fE_charge=0.0;
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(k=0;k<Nz;k++){
	    fE_charge -= ((12.0*Pi*epsilon)/tau)*(pow(Gradient_V_x[i][j][k],2)+pow(Gradient_V_y[i][j][k],2)+pow(Gradient_V_z[i][j][k],2))*(dxyz[0]*dxyz[1]*dxyz[2]);
	    fE_charge += (NA*phi_e[i][j][k]*V[i][j][k])*(dxyz[0]*dxyz[1]*dxyz[2]);
	  }
	}
      }
      fE_charge/=((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2]));
     
      // Calculaing the new omega fields and other contributions to the free energy
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(k=0;k<Nz;k++){
	    for(ii=0;ii<ChainType;ii++){
	      newW[ii][i][j][k] = 0.0;  
	      for(jj=0;jj<ChainType;jj++){
		newW[ii][i][j][k] += ((chiMatrix[ii][jj]*phi[jj][i][j][k]));
		fEchi += phi[ii][i][j][k]*chiMatrix[ii][jj]*phi[jj][i][j][k]*dxyz[0]*dxyz[1]*dxyz[2];
	      }
	      if(ii==0){newW[ii][i][j][k] += eta[i][j][k]-(((12.0*Pi*epsilon)/(tau))*(pow(Gradient_V_x[i][j][k],2)+pow(Gradient_V_y[i][j][k],2)+pow(Gradient_V_z[i][j][k],2)));}  //A
	      if(ii==1){newW[ii][i][j][k] += eta[i][j][k]-(((12.0*Pi*epsilon)/(tau))*(pow(Gradient_V_x[i][j][k],2)+pow(Gradient_V_y[i][j][k],2)+pow(Gradient_V_z[i][j][k],2)));}  //B
	      fEW += (newW[ii][i][j][k]*phi[ii][i][j][k]*dxyz[0]*dxyz[1]*dxyz[2]);
	      delW[ii][i][j][k] = newW[ii][i][j][k]-w[ii][i][j][k];
	      deltaW += fabs(delW[ii][i][j][k]);
	    }
	    w_e[i][j][k] = NA*V[i][j][k];
	  }
	}
      }
      fES=pAave*log(QA)+(pBave*log(QB)/kappa)+(pIave*NA*log(QI));

      deltaW/=(Nx*Ny*Nz);
      fEchi/=(2.0*((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])));
      fEW/=(((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])));
       
      //fE_homo=homogenousfE(chiMatrix);

      currentfE=-fES-fEW+fEchi-fE_charge;
 
      deltafE=fabs(currentfE-oldfE);

      std::cout<<iter<<" "<<currentfE<< " " << deltaW<<" "<<delphi[Nx/2][Ny/2][Nz/2]<<std::endl;
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(k=0;k<Nz;k++){
	    for(chain=0;chain<ChainType;chain++){
	      w[chain][i][j][k]+=(epsilon_w*delW[chain][i][j][k]-epsilon_phi*delphi[i][j][k]);
	    }
	  }
	}
      }
    
    }while(deltaW>precision);
   
    outputFile <<dxyz[0]*Nx<<" "<<dxyz[1]*Ny<<" "<<dxyz[2]*Nz<<" "<<currentfE<<" "<<chi[4]<<std::endl;     
    size_adjust(w,phi,eta,Ns,ds,k_vector,chi,dxyz,chiMatrix);
    
    
    if(oldfE<currentfE){
      msg=0;
    }
    if(msg!=0){
      oldfE=currentfE;
    }
   
  }while(msg>0.5);

  outputFile <<"Done"<<std::endl;
  outputFile.close();

  
  
};
