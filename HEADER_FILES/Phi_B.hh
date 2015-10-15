double Phi_B( ){

  int         i,j,l,s;
  double      Q;
 
  // Here is the for loop for doing the qint, setting it to 1.0
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){
	qint[i][j][l]=1.0;
      }
    }
  }
  
  // Here we will solve the diffusion question
  solveModDiffEqn_FFT(qB,w[1],qint,ds,(int)Ns[1],1,k_vector,dxyz);

  // Here we are doing the sum to get the single chain partition function
  Q=0.0;
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){
	Q+=qB[i][j][l][(int)Ns[1]]*dxyz[0]*dxyz[1]*dxyz[2];
      }
    }
  }
  // Normalizing with respect to the volume of the box
  Q/=((dxyz[0]*Nx)*(dxyz[1]*Ny)*(dxyz[2]*Nz));
  
  // Here we do the concentration calculation
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){

	phi[1][i][j][l]=0.0;

	for(s=0;s<(Ns[1]+1);s++){
	  if(s==0 || s==(int)Ns[1]){
	    phi[1][i][j][l]+=0.5*qB[i][j][l][s]*qB[i][j][l][(int)Ns[1]-s]*ds;
	  }else{
	    phi[1][i][j][l]+=qB[i][j][l][s]*qB[i][j][l][(int)Ns[1]-s]*ds;
	  }
	}

	phi[1][i][j][l]*=(pBave/(Q*kappa));

      }
    }
  }
 
  return Q;

};
