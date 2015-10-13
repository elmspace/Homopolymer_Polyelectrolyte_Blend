void FreeEnergy(double ****w,double ****phi, double ***psi, double ***eta, double *Ns, double ds, double ***k_vector, double *chi, double *dxyz, double **chiMatrix){

  
  double  currentfE, oldfE, deltafE; 
  int     maxIter=1000; 
  int     i,j,k,iter,chain,ii,jj; 
  double  precision=1.0e-3; 
  double  QA,QB,QI; 
  double  fEW, fEchi, fES, fE_charge; 
  double  epsilon, gamma;
  double  ***delphi;
  double  ****delW;
  double  ****newW;
  double  deltaW;
  double  fE_homo;
  double  box,msg;


  delW=create_4d_double_array(ChainType,Nx,Ny,Nz,"delW");
  delphi=create_3d_double_array(Nx,Ny,Nz,"delphi");
  newW=create_4d_double_array(ChainType,Nx,Ny,Nz,"newW");

  msg=1.0;
  oldfE=1.0e2;
  std::ofstream outputFile("./fE.dat");
  do{
   
    WaveVectors(k_vector,dxyz);   //
    currentfE=0.0;
    deltafE=0.0;
  
    epsilon=0.05;
    gamma=0.05;
  
    iter=0;  
    
    do{
      iter++;
    
      fEW=0.0;
      fEchi=0.0;
      fES=0.0;
      
      QA=ConcA(phi,w,Ns,ds,k_vector,dxyz);
      QB=ConcB(phi,w,Ns,ds,k_vector,dxyz);
      QI=ConcI(phi,w,Ns,dxyz);
      
      SolvePBE(phi,psi,k_vector);

      Incomp(eta,phi,delphi);
    
      fEW=0.0;
      fEchi=0.0;
      
      deltaW=0.0;       
    
      // Some output for checking the progress
      std::ofstream outputFile7("./phi.dat");
      for(i=0;i<Nx;i++){
	outputFile7 <<i<<" "<<phi[0][i][Ny/2][Nz/2]<<" "<<phi[1][i][Ny/2][Nz/2]<<" "<<phi[2][i][Ny/2][Nz/2]<<" "<<psi[i][Ny/2][Nz/2]<<std::endl;
      }
      outputFile7.close();     
   
      // Some output for checking the progress
      std::ofstream outputFile17("./phi2D.dat");
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  outputFile17 <<i*dxyz[0]<<" "<<j*dxyz[1]<<" "<<phi[0][i][j][Nz/2]<<" "<<phi[1][i][j][Nz/2]<<" "<<phi[2][i][j][Nz/2]<<std::endl;
	}}
      outputFile17.close();     
      
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   Free Energy   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      fE_charge=0.0;
      for(i=0;i<(Nx-1);i++){
	for(j=0;j<(Ny-1);j++){
	  for(k=0;k<(Nz-1);k++){
	    fE_charge+=pow(((psi[i][j][k]-psi[i+1][j][k])/dxyz[0]),2)*dxyz[0]*dxyz[1]*dxyz[2];
	    fE_charge+=pow(((psi[i][j][k]-psi[i][j+1][k])/dxyz[1]),2)*dxyz[0]*dxyz[1]*dxyz[2];
	    fE_charge+=pow(((psi[i][j][k]-psi[i][j][k+1])/dxyz[2]),2)*dxyz[0]*dxyz[1]*dxyz[2];
	  }
	}
      }
      fE_charge*=(diel_cons)/(2.0*Nx*Ny*Nz);

      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(k=0;k<Nz;k++){
	    for(ii=0;ii<ChainType;ii++){
	      newW[ii][i][j][k]=0.0;  
	    }
	  }
	}
      }
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(k=0;k<Nz;k++){

	    for(ii=0;ii<ChainType;ii++){
	      for(jj=0;jj<ChainType;jj++){

		newW[ii][i][j][k]+=((chiMatrix[ii][jj]*phi[jj][i][j][k]));
		fEchi+=phi[ii][i][j][k]*chiMatrix[ii][jj]*phi[jj][i][j][k]*dxyz[0]*dxyz[1]*dxyz[2];

	      }
	      
	      if(ii==0){newW[ii][i][j][k]+=eta[i][j][k]+zA*NA*PA*psi[i][j][k];}    //A
	      if(ii==1){newW[ii][i][j][k]+=eta[i][j][k];}  //B
	      if(ii==2){newW[ii][i][j][k]+=zI*NA*psi[i][j][k];}    //I

	      fEW+=(newW[ii][i][j][k]*phi[ii][i][j][k]*dxyz[0]*dxyz[1]*dxyz[2]);
	      delW[ii][i][j][k]=newW[ii][i][j][k]-w[ii][i][j][k];
	      deltaW+=fabs(delW[ii][i][j][k]);
	    }
	  }
	}
      }

      deltaW/=(Nx*Ny*Nz);
      fEchi/=(2.0*((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])));
      fEW/=(((Nx*dxyz[0])*(Ny*dxyz[1])*(Nz*dxyz[2])));
    
      fES=pAave*log(QA)+(pBave*log(QB)/fB)+(pIave*NA*log(QI))-(pAave*log(pAave))-(pBave*log(pBave)/fB)-(pIave*NA*log(pIave));
   
      //fE_homo=homogenousfE(chiMatrix);

      currentfE=-fES-fEW+fEchi-fE_charge;
 
      deltafE=fabs(currentfE-oldfE);

      std::cout<<iter<<" "<<currentfE<< " " << deltaW<<" "<<delphi[Nx/2][Ny/2][Nz/2]<<std::endl;
      
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(k=0;k<Nz;k++){

	    for(chain=0;chain<ChainType;chain++){
	      w[chain][i][j][k]+=(gamma*delW[chain][i][j][k]-epsilon*delphi[i][j][k]);
	    }
	    
	  }
	}
      }
    
   
    }while(deltaW>precision);
   

    
    //+++++++++++++++++++++++++++++ This output is setup for the matlab plotting +++++++++++++++++++
    std::ofstream outputFile7("./xyz.dat");
    for (i=0;i<Nx;i++){
      outputFile7<<i*dxyz[0]<<" "<<i*dxyz[1]<<" "<<i*dxyz[2]<<std::endl;
    }
    outputFile7.close();  
    std::ofstream outputFile8("./ABCD.dat");
    for (i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	for(k=0;k<Nz;k++){
	  outputFile8<<phi[0][i][j][k]<<" "<<phi[1][i][j][k]<<" "<<phi[2][i][j][k]<<std::endl;
	}}}
    outputFile8.close();
    //+++++++++++++++++++++++++++++++++++++  Omega Fields  +++++++++++++++++++++++++++++++++++++++++
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // Writting to data files
    std::ofstream outputFile6("./omega.dat");
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	for(k=0;k<Nz;k++){
	  outputFile6 <<i<<" "<<j<<" "<<k<< " "<<w[0][i][j][k]<<" "<<w[1][i][j][k]<<" "<<w[2][i][j][k]<<std::endl;
	}
      }
    }
    outputFile6.close();
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    outputFile <<dxyz[0]*Nx<<" "<<dxyz[1]*Ny<<" "<<dxyz[2]*Nz<<" "<<currentfE<<" "<<chi[4]<<std::endl;     
    box=size_adjust(w,phi,eta,Ns,ds,k_vector,chi,dxyz,chiMatrix);
    
    
    if(oldfE<currentfE){
      msg=0.0;
    }
    if(msg>0.5){
      oldfE=currentfE;
    }
   


  }while(msg>0.5);

  outputFile <<"Done"<<std::endl;
  outputFile.close();

  
  destroy_3d_double_array(delphi);
  destroy_4d_double_array(delW);
  destroy_4d_double_array(newW);
  
};
