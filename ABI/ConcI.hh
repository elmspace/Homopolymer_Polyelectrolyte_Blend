double ConcI(double ****phi, double ****w, double *Ns,double *dxyz){

  int         i,j,k,s;
  double      Q;
  double      ***qI;
  
  qI=create_3d_double_array(Nx,Ny,Nz,"qI");
 
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	qI[i][j][k]=exp(-w[2][i][j][k]/NA);
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
  
  //clearing the memory
  destroy_3d_double_array(qI);  

  return Q;


};
