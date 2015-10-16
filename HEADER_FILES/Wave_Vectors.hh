void Wave_Vectors(int toDo){

  int             i,j,k;
  double          lx,ly,lz;

  if(toDo == 0){
    lx=dxyz[0]*Nx;
    ly=dxyz[1]*Ny;
    lz=dxyz[2]*Nz;
  }else if (toDo == 1){
    lx=dxyz_temp[0]*Nx;
    ly=dxyz_temp[1]*Ny;
    lz=dxyz_temp[2]*Nz;
  }else{
    std::cout<<"Wrong toDo option in Wave_Vectors!"<<std::endl;
    exit(0);
  }

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

};
