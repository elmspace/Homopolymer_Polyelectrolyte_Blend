void WaveVectors(double ***k_vector, double *dxyz){

  int             i,j,k;
  double          lx,ly,lz;
  double          *Kx,*Ky,*Kz;

  Kx=create_1d_double_array(Nx,"Kx");
  Ky=create_1d_double_array(Ny,"Ky");
  Kz=create_1d_double_array(Nz,"Kz");

  lx=dxyz[0]*Nx;
  ly=dxyz[1]*Ny;
  lz=dxyz[2]*Nz;

  for(i=0;i<(int)(Nx/2);i++){Kx[i]=(2.*Pi*i)/lx;}
  for(i=(int)(Nx/2);i<Nx;i++){Kx[i]=(2.*Pi*(Nx-i))/lx;}

  for(i=0;i<(int)(Ny/2);i++){Ky[i]=(2.*Pi*i)/ly;}
  for(i=(int)(Ny/2);i<Ny;i++){Ky[i]=(2.*Pi*(Ny-i))/ly;}

  for(i=0;i<(int)(Nz/2);i++){Kz[i]=(2.*Pi*i)/lz;}
  for(i=(int)(Nz/2);i<Nz;i++){Kz[i]=(2.*Pi*(Nz-i))/lz;}
  
  
  for(i=0;i<Nx;i++){Kx[i]*=Kx[i];}
  for(i=0;i<Ny;i++){Ky[i]*=Ky[i];}
  for(i=0;i<Nz;i++){Kz[i]*=Kz[i];}

  for(i=0;i<Nx;i++){
    for(j=0;j<Ny;j++){
      for(k=0;k<Nz;k++){
	k_vector[i][j][k]=Kx[i]+Ky[j]+Kz[k];
      }
    }
  }

  
  destroy_1d_double_array(Kx);
  destroy_1d_double_array(Ky);
  destroy_1d_double_array(Kz);

};
