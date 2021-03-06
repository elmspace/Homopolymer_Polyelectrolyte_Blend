//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                                Solving The Modified Diffusion Equation
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void solveModDiffEqn_FFT(double ****q, double ***w, double ***qint, double ds, int Ns, int sign, double ***k, double *dxyz){
  
  int i,j,l,s,ss; 
  unsigned long  ijl;

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(l=0;l<Nz;l++){
	kds[i][j][l]=exp(-ds*k[i][j][l]);
	wds[i][j][l]=exp(-0.5*ds*w[i][j][l]);
      }
    }
  }
  if(sign==1){
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	for(l=0;l<Nz;l++){
	  q[i][j][l][0]=qint[i][j][l];
	}
      }
    }
    for(s=0;s<((int)Ns);s++){
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(l=0;l<Nz;l++){
	    ss=l+Nz*(j+Ny*i);
	    input_q[ss][0]=q[i][j][l][s]*wds[i][j][l];
	    input_q[ss][1]=0.0;
	  }
	}
      }
      fftw_execute(forward_plan);
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(l=0;l<Nz;l++){
	    ss=l+Nz*(j+Ny*i);
	    transformed_q[ss][0]*=kds[i][j][l];
	    transformed_q[ss][1]*=kds[i][j][l];
	  }
	}
      }
      fftw_execute(inverse_plan);
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(l=0;l<Nz;l++){
	    ss=l+Nz*(j+Ny*i);
	    q[i][j][l][s+1]=((final_q[ss][0]*wds[i][j][l])/(Nx*Ny*Nz));
	  }
	}
      }
    }
  }else{
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	for(l=0;l<Nz;l++){
	  q[i][j][l][0]=qint[i][j][l];
	}
      }
    }
    for(s=0;s<(Ns);s++){ 
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(l=0;l<Nz;l++){
	    ss=l+Nz*(j+Ny*i);
	    input_q[ss][0]=q[i][j][l][s]*wds[i][j][l];
	    input_q[ss][1]=0.0;
	  }
	}
      }
      fftw_execute(forward_plan);
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(l=0;l<Nz;l++){
	    ss=l+Nz*(j+Ny*i);
	    transformed_q[ss][0]*=kds[i][j][l];
	    transformed_q[ss][1]*=kds[i][j][l];
	  }
	}
      }
      fftw_execute(inverse_plan);
      for(i=0;i<Nx;i++){
	for(j=0;j<Ny;j++){
	  for(l=0;l<Nz;l++){
	    ss=l+Nz*(j+Ny*i);
	    q[i][j][l][s+1]=((final_q[ss][0]*wds[i][j][l])/(Nx*Ny*Nz));
	  }
	}
      }
    }
  }



};
