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


  /*
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files (2D phi out put, in the r-z plane)
  std::ofstream outputFile3("./PHI/phi2D.dat");
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      outputFile3 <<i*drz[0]<<" "<<j*drz[1]<<" "<<phi[0][i][j]<<" "<<phi[1][i][j]<<" "<<phi[2][i][j]<<" "<<phi[3][i][j]<<" "<<phi[4][i][j]<<" "<<phi[5][i][j]<<std::endl;
    }
  }
  outputFile3.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files (Omega output mainly used for input, for next generation calculations)
  std::ofstream outputFile4("./OMEGA/omega.dat");
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      outputFile4 <<w[0][i][j]<<" "<<w[1][i][j]<<" "<<w[2][i][j]<<" "<<w[3][i][j]<<" "<<w[4][i][j]<<" "<<w[5][i][j]<<std::endl;
    }
  }
  outputFile4.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files (Phi output mainly used for input, for next generation calculations)
  std::ofstream outputFile5("./OMEGA/phi.dat");
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      outputFile5 <<phi[0][i][j]<<" "<<phi[1][i][j]<<" "<<phi[2][i][j]<<" "<<phi[3][i][j]<<" "<<phi[4][i][j]<<" "<<phi[5][i][j]<<std::endl;
    }
  }
  outputFile5.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   Writting Phi for Matlab plotting
  // The following create data files in the format that can be read by the Matlab script
  // This creates a 3D sctructire.
  double theta=0.0;
  double delta_theta=(3.0*Pi/2.0)/(NBox-1);
  
  std::ofstream outputFile6("./MATLAB/xyz.dat");
  for (i=0;i<NBox;i++){
    outputFile6 << i*delta_theta<<" "<< i*drz[0]<<" "<< i*drz[1]<<std::endl;
  }
  outputFile6.close();  
  std::ofstream outputFile7("./MATLAB/ABCD.dat"); // order-> ABA AB C
  for (i=0;i<NBox;i++){
    for(k=0;k<NBox;k++){
      for(j=0;j<NBox;j++){
	outputFile7<<phi[0][i][j]<<" "<<phi[1][i][j]<<" "<<phi[2][i][j]<<" "<<phi[3][i][j]<<" "<<phi[4][i][j]<<" "<<phi[5][i][j]<<std::endl;
      }
    }
  }
  outputFile7.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
  */


 
};



