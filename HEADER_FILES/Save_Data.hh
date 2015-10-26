/*
 In this file we save data to either be used for next generation calculation,
 or for visualization purposes. Plotting scripts can be found in PLOT and MATLAB files.
*/
void saveData( ){

  int i, j ,k;
  int J, I, K;

  std::cout<<"Saving data . . ."<<std::endl;
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files (1D phi output in the r-direction)
  std::ofstream outputFile1("./PHI/phi_x.dat");
  J=Ny/2;
  K=Nz/2;
  for(i=0;i<Nx;i++){
    outputFile1 <<i*dxyz[0]<<" "<<phi[0][i][J][K]<<" "<<phi[1][i][J][K]<<" "<<phi[2][i][J][K]<<std::endl;
  }
  outputFile1.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files (2D phi out put, in the x-y plane)
  std::ofstream outputFile2("./PHI/phi_xy.dat");
  K=Nz/2;
  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      outputFile2 <<i*dxyz[0]<<" "<<j*dxyz[1]<<" "<<phi[0][i][j][K]<<" "<<phi[1][i][j][K]<<" "<<phi[2][i][j][K]<<std::endl;
    }
  }
  outputFile2.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 
};



