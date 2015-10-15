void Incompressibility( ){

  int     i,j,k;
  int     chain; 
  double  ptot;

  ptot=0.0;

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	
	ptot=0.0;
	delphi[i][j][k]=0.0;
    
	ptot=phi[0][i][j][k]+phi[1][i][j][k];	

	delphi[i][j][k]=1.0-ptot;
	eta[i][j][k]-=delphi[i][j][k];

      }
    }
  }
 
};
