using namespace std;

void Mod0(){
  
  int M = 2001;
  int mid = (M-1)/2;
  int i;
  double slope_diff, slope_diff_old, eps_val = 1.0e-4;
  double fE_homo;
  double dPhi = 1.0/double(M);

  double *p, *f, *df;

  p=create_1d_double_array(M,"p");
  f=create_1d_double_array(M,"f");
  df=create_1d_double_array(M,"df");

  Allocate(1);
  Parameters( );

  pAave = 1.0e-20;
  pBave = 1.0-pAave;
  pIave = pAave*PA;

  std::ofstream outputFile("./RESULTS/HomfE.dat");

  for(i=0; i<M; i++){
    
    fE_homo=homogenousfE( );

    outputFile<<pAave<<" "<<fE_homo<<endl;
    //cout<<pAave<<" "<<fE_homo<<endl;

    p[i]=pAave;
    f[i]=fE_homo;

    pAave += dPhi;
    pBave = 1.0-pAave;
    pIave = pAave*PA;
    
  }
  outputFile.close();


  for(i=1;i<(M-1);i++){ 
    df[i]=(f[i+1]-f[i-1])/(2.0*dPhi);
  }
  df[0]=(f[1]-f[0])/dPhi;
  df[M-1]=(f[Nx-1]-f[Nx-2])/dPhi;
  

  
  std::ofstream outputFile2("./RESULTS/HomfE_2.dat");
  slope_diff_old = 1.0e20;
  for(i=0;i<mid;i++){
    slope_diff = df[i]-df[(M-1)-i];
    outputFile2<<i<<" "<<abs(slope_diff)<<endl;


    if(abs(slope_diff_old)<abs(slope_diff)){
      cout<<p[i]<<" "<<p[(M-1)-i]<<endl;
      break;
    }else{
      slope_diff_old = slope_diff;
    }
 
   
  }
  outputFile2.close();
 
  destroy_1d_double_array(p);
  destroy_1d_double_array(f);
  destroy_1d_double_array(df);

  Allocate(-1);
 
}
