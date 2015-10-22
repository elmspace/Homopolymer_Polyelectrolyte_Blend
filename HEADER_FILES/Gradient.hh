/*
  In this function, we will calculate the gradient of an input function
  the gradient is the return using the last variable
  direction -> 0=x, 1=y, 2=z 
*/

void Gradient(double ***input_func, int direction, double  *dxyz, double ***gradient){

 
  int i,j,k;

 
  if(direction==0){

    for(i=1;i<(Nx-1);i++){
      for(j=0;j<Ny;j++){
	for(k=0;k<Nz;k++){
	  gradient[i][j][k]=(input_func[i+1][j][k]-input_func[i-1][j][k])/(2.0*dxyz[0]);
	}
      }
    }
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	gradient[0][j][k]=(input_func[1][j][k]-input_func[0][j][k])/dxyz[0];
	gradient[Nx-1][j][k]=(input_func[Nx-1][j][k]-input_func[Nx-2][j][k])/dxyz[0];
      }
    }

  }else if(direction==1){

    for(i=0;i<Nx;i++){
      for(j=1;j<(Ny-1);j++){
	for(k=0;k<Nz;k++){
	  gradient[i][j][k]=(input_func[i][j+1][k]-input_func[i][j-1][k])/(2.0*dxyz[1]);
	}
      }
    }
    for(i=0;i<Nx;i++){
      for(k=0;k<Nz;k++){
	gradient[i][0][k]=(input_func[i][1][k]-input_func[i][0][k])/dxyz[1];
	gradient[i][Ny-1][k]=(input_func[i][Ny-1][k]-input_func[i][Ny-2][k])/dxyz[1];
      }
    }

  }else if(direction==2){
    
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	for(k=1;k<(Nz-1);k++){
	  gradient[i][j][k]=(input_func[i][j][k+1]-input_func[i][j][k-1])/(2.0*dxyz[2]);
	}
      }
    }
    for(i=0;i<Nx;i++){
      for(j=0;j<Ny;j++){
	gradient[i][j][0]=(input_func[i][j][1]-input_func[i][j][0])/dxyz[2];
	gradient[i][j][Nz-1]=(input_func[i][j][Ny-1]-input_func[i][j][Nz-2])/dxyz[2];
      }
    }

  }else{
    std::cout<<"The input to Gradient.hh is not correct!";
    exit(1);
  }

};
