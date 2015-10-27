using namespace std;

void Mod0(){
  
  int M = 200;
  int i;
  double fE_homo;
  double dPhi = 1.0/double(M);

  double *p, *f;

  p=create_1d_double_array(M,"p");
  f=create_1d_double_array(M,"f");

  Allocate(1);
  Parameters( );

  pAave = 0.00001;
  pBave = 1.0-pAave;
  pIave = pAave*PA;

  std::ofstream outputFile("./RESULTS/HomfE.dat");

  for(i=0; i<M; i++){
    
    fE_homo=homogenousfE( );

    outputFile<<pAave<<" "<<fE_homo<<endl;
    cout<<pAave<<" "<<fE_homo<<endl;

    p[i]=pAave;
    f[i]=fE_homo;

    pAave += dPhi;
    pBave = 1.0-pAave;
    pIave = pAave*PA;
    
  }
  outputFile.close();

  std::ofstream outputFile2("./RESULTS/HomfE_2.dat");
  for(i=0;i<(M-1);i++){
    outputFile2<<p[i]<<" "<<(f[i+1]-f[i])/(p[i+1]-p[i])<<endl;
  }
  outputFile2.close();

  destroy_1d_double_array(p);
  destroy_1d_double_array(f);

  Allocate(-1);
 
}
