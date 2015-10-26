/*
  Calculating the total charge at position r
*/
void Phi_e( ){

  int i, j, k;

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	phi_e[i][j][k] = phi[2][i][j][k] - PA*phi[0][i][j][k];
      }
    }
  }
    

};
