double Phi_A( ){

  int         i,j,l,s;
  double      Q;
 
  // Here is the for loop for doing the qint, setting it to 1.0
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){
	qint[i][j][l] = 1.0;
	eff_wA[i][j][k] = w[0][i][j][k] - PA*w_e[i][j][k];
      }
    }
  }
  
  // Here we will solve the diffusion question
  solveModDiffEqn_FFT(qA,eff_wA,qint,ds,(int)Ns[0],1,k_vector,dxyz);

  // Here we are doing the sum to get the single chain partition function
  Q=0.0;
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){
	Q+=qA[i][j][l][(int)Ns[0]]*dxyz[0]*dxyz[1]*dxyz[2];
      }
    }
  }
  // Normalizing with respect to the volume of the box
  Q/=((dxyz[0]*Nx)*(dxyz[1]*Ny)*(dxyz[2]*Nz));
  
  
  // Here we do the concentration calculation
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){

	phi[0][i][j][l]=0.0;
     
	for(s=0;s<(Ns[0]+1);s++){
	  if(s==0 || s==(int)Ns[0]){
	    phi[0][i][j][l]+=0.5*qA[i][j][l][s]*qA[i][j][l][(int)Ns[0]-s]*ds;
	  }else{
	    phi[0][i][j][l]+=qA[i][j][l][s]*qA[i][j][l][(int)Ns[0]-s]*ds;
	  }
	}

	phi[0][i][j][l]*=(pAave/Q);
      }
    }
  }

  return Q;

};
