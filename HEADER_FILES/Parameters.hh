void parametersAB(double *chi,double *f,double &ds,double *Ns,double *dxyz,double **chiMatrix){
  
  int Ds;

  
  zA=-1.0;
  zI=1.0;
  PA=0.01;
  diel_cons=2.0;

  //set to 1 to read from restart file
  //set to 0 to set manually
  Iomega=1;
  
  //set the morphology 1=on 0=off
  LAM=1;
  HEX=0;
  BCC=0;
  
  dxyz[0]=(5.2)/Nx;
  dxyz[1]=(2.0)/Ny;
  dxyz[2]=(2.0)/Nz;

  Ns[0]=1000;               // A
  Ns[1]=1000;               // B
  Ns[2]=1;                // I
  NA=Ns[0];

  Ds=Ns[0];
 
  f[0]=Ns[0]/Ns[0];           // fA
  f[1]=Ns[1]/Ns[0];           // fB
  fB=f[1];

  chi[0]=11.0;  //xAB
  chi[1]=0.0;   //xAI
  chi[2]=0.0;   //xBI

  pAave=0.5;
  pBave=1.0-pAave;
  pIave=PA*pAave; //I


  ds=1.0/Ds;


  // Setting up the matrix

  chiMatrix[0][0]=0.0;     // xAA
  chiMatrix[0][1]=chi[0];     // xAB
  chiMatrix[0][2]=chi[1];     // xAI
 
  chiMatrix[1][0]=chi[0];     // xAB
  chiMatrix[1][1]=0.0;     // xBB
  chiMatrix[1][2]=chi[2];     // xBI
 
  chiMatrix[2][0]=chi[1];     // xAI
  chiMatrix[2][1]=chi[2];     // xBI
  chiMatrix[2][2]=0.0;     // xII


 
};
