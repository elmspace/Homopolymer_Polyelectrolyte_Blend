void omega(double ****w){

  int i,j,k;
 
 
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	//++++++++++++++++++++++++++++++++++

	
	w[0][i][j][k]=-1.0*cos(2.0*Pi*i/Nx);
	w[1][i][j][k]=-1.0*(drand48()-0.50);
	w[2][i][j][k]=-1.0*(drand48()-0.50);
	
	//+++++++++++++++++++++++++++++++++++
      }
    }
  }




};
