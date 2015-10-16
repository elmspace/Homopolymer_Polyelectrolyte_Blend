void Allocate (int task){


  if(task==1){
    w = create_4d_double_array(ChainType,Nx,Ny,Nz,"w");
    phi = create_4d_double_array(ChainType,Nx,Ny,Nz,"phi");
    w_e = create_3d_double_array(Nx,Ny,Nz,"w_e");
    eff_wA = create_3d_double_array(Nx,Ny,Nz,"eff_wA");
    eff_wI = create_3d_double_array(Nx,Ny,Nz,"eff_wI");
    phi_e = create_3d_double_array(Nx,Ny,Nz,"phi_e");
    V = create_3d_double_array(Nx,Ny,Nz,"V");
    Gradient_V = create_3d_double_array(Nx,Ny,Nz,"Gradient_V");
    eta = create_3d_double_array(Nx,Ny,Nz,"eta");
    chi = create_1d_double_array(ChainType,"chi");
    Ns = create_1d_double_array(ChainType,"Ns");
    k_vector = create_3d_double_array(Nx,Ny,Nz,"k_vector");
    dxyz = create_1d_double_array(3,"dxyz");
    chiMatrix = create_2d_double_array(ChainType,ChainType,"chiMatrix");
    Kx=create_1d_double_array(Nx,"Kx");
    Ky=create_1d_double_array(Ny,"Ky");
    Kz=create_1d_double_array(Nz,"Kz");
    delW=create_4d_double_array(ChainType,Nx,Ny,Nz,"delW");
    delphi=create_3d_double_array(Nx,Ny,Nz,"delphi");
    newW=create_4d_double_array(ChainType,Nx,Ny,Nz,"newW");
    dxyz_temp=create_1d_double_array(3,"dxyz_temp");
    w_temp=create_4d_double_array(ChainType,Nx,Ny,Nz,"w_temp");
    box_x=create_1d_double_array(27,"box_x");
    box_y=create_1d_double_array(27,"box_y");
    box_z=create_1d_double_array(27,"box_z");
    box_fE=create_1d_double_array(27,"box_fE");
    // Setting up the FFTW for MDE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    input_q = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
    transformed_q = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
    final_q = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
    // Setting the FFTW plans
    forward_plan = fftw_plan_dft_3d(Nx,Ny,Nz,input_q,transformed_q,FFTW_FORWARD,FFTW_MEASURE);
    inverse_plan = fftw_plan_dft_3d(Nx,Ny,Nz,transformed_q,final_q,FFTW_BACKWARD,FFTW_MEASURE);
    // Setting up FFTW for PBE  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    input_PB = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
    transformed_PB = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
    final_PB = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
    // Setting the FFTW plans
    forward_plan_PB = fftw_plan_dft_3d(Nx,Ny,Nz,input_PB,transformed_PB,FFTW_FORWARD,FFTW_MEASURE);
    inverse_plan_PB = fftw_plan_dft_3d(Nx,Ny,Nz,transformed_PB,final_PB,FFTW_BACKWARD,FFTW_MEASURE);
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    qA = create_4d_double_array(Nx,Ny,Nz,((int)Ns[0]+1),"qA");
    qB = create_4d_double_array(Nx,Ny,Nz,((int)Ns[1]+1),"qB");
    qI = create_3d_double_array(Nx,Ny,Nz,"qI");
    qint = create_3d_double_array(Nx,Ny,Nz,"qint");
  }else if(task==-1){
    destroy_4d_double_array(qA); 
    destroy_4d_double_array(qB);
    destroy_3d_double_array(qI);
    destroy_3d_double_array(qint);
    fftw_free(input_q);
    fftw_free(transformed_q);
    fftw_free(final_q);
    fftw_destroy_plan(forward_plan);
    fftw_destroy_plan(inverse_plan);
    fftw_free(input_PB);
    fftw_free(transformed_PB);
    fftw_free(final_PB);
    fftw_destroy_plan(forward_plan_PB);
    fftw_destroy_plan(inverse_plan_PB);
    destroy_4d_double_array(w);
    destroy_3d_double_array(eff_wA);
    destroy_3d_double_array(eff_wI);
    destroy_3d_double_array(w_e);
    destroy_3d_double_array(V);
    destroy_3d_double_array(Gradient_V);
    destroy_3d_double_array(eta);
    destroy_4d_double_array(phi);
    destroy_3d_double_array(phi_e);
    destroy_1d_double_array(chi);
    destroy_1d_double_array(Ns);
    destroy_3d_double_array(k_vector);
    destroy_1d_double_array(dxyz);
    destroy_2d_double_array(chiMatrix);
    destroy_1d_double_array(Kx);
    destroy_1d_double_array(Ky);
    destroy_1d_double_array(Kz);
    destroy_3d_double_array(delphi);
    destroy_4d_double_array(delW);
    destroy_4d_double_array(newW);
    destroy_1d_double_array(dxyz_temp);
    destroy_1d_double_array(box_x);
    destroy_1d_double_array(box_y);
    destroy_1d_double_array(box_z);
    destroy_1d_double_array(box_fE);
    destroy_4d_double_array(w_temp);
  }

};
