void Solve_PB_Equation( ){

  int i,j,k;
  int ss;

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	input_PB[ss][0]=(-(NA*tau)/(epsilon*24.0*Pi))*(phi_e[i][j][k]);
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
	  transformed_PB[ss][0]/=k_vector[i][j][k]; 
	  transformed_PB[ss][1]/=k_vector[i][j][k]; 
	}
      }
    }
  }
  fftw_execute(inverse_plan_PB);

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	ss=k+Nz*(j+Ny*i);
	V[i][j][k]=(final_PB[ss][0]/(Nx*Ny*Nz));
      }
    }
  }
  

};
