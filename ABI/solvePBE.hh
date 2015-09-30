void SolvePBE(double ****phi, double ***psi, double ***k_vector){

  int i,j,k;
  int ss;

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	input_PB[ss][0]=(-NA/diel_cons)*(PA*zA*phi[0][i][j][k]+zI*phi[2][i][j][k]);
	input_PB[ss][1]=0.0;
      }
    }
  }
  fftw_execute(forward_plan_PB);

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	if(k_vector[i][j][k]==0.0){
	  transformed_PB[ss][0]=0; 
	  transformed_PB[ss][1]=0;
	}else{
	  transformed_PB[ss][0]/=-k_vector[i][j][k]; 
	  transformed_PB[ss][1]/=-k_vector[i][j][k]; 
	}
      }
    }
  }
  fftw_execute(inverse_plan_PB);

  
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	psi[i][j][k]=(final_PB[ss][0]/(Nx*Ny*Nz));
      }
    }
  }
  

};
