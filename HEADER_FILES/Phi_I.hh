double Phi_I( ){

  int         i,j,k,s;
  double      Q;
  
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	eff_wI[i][j][k] = w[2][i][j][k] + w_e[i][j][k];
	qI[i][j][k] = exp(-eff_wI[i][j][k]/NA); 
      }
    }
  }

  // Here we are doing the sum to get the single chain partition function
  Q=0.0;
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	Q+=qI[i][j][k]*dxyz[0]*dxyz[1]*dxyz[2];
      }
    }
  }
  // Normalizing with respect to the volume of the box
  Q/=((dxyz[0]*Nx)*(dxyz[1]*Ny)*(dxyz[2]*Nz));
  
  // Here we do the concentration calculation
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	
	phi[2][i][j][k]=(pIave/Q)*qI[i][j][k];
       
      }
    }
  }
  
  return Q;

};
