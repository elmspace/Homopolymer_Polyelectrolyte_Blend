using namespace std;

void Mod0(){
  
  int M = 200001;
  int mid = (M-1)/2;
  int i,j,k;
  int done;
  double m,b,y;
  double p_left, p_right;
  double slope_diff, eps_val = 1.0e-4;
  double fE_homo;
  double dPhi = 1.0/double(M);

  double *p, *f, *df;

  p=create_1d_double_array(M,"p");
  f=create_1d_double_array(M,"f");
  df=create_1d_double_array(M,"df");

  Allocate(1);

  std::ofstream outputFile3("./RESULTS/Spinodal.dat");

  // Run over some parameter
  do{
    
    
    //___________________________________________________________________________
    Parameters( );
    pAave = 1.0e-20;
    pBave = 1.0-pAave;
    pIave = pAave*PA;
    
    // Calculating the homogenous free energy **********
    std::ofstream outputFile("./RESULTS/HomfE.dat");
    for(i=0; i<M; i++){
      fE_homo=homogenousfE( );
      outputFile<<pAave<<" "<<fE_homo<<endl;
      p[i]=pAave;
      f[i]=fE_homo;
      pAave += dPhi;
      pBave = 1.0-pAave;
      pIave = pAave*PA;
    }
    outputFile.close();
    // **************************************************
    
    // Calculating the slope of free energy *************
    for(i=1;i<(M-1);i++){ 
      df[i]=(f[i+1]-f[i-1])/(2.0*dPhi);
    }
    df[0]=(f[1]-f[0])/dPhi;
    df[M-1]=(f[M-1]-f[M-2])/dPhi;
    // **************************************************
    
    done = 0;
    for(i=0;i<M;i++){
      for(j=M-1;j>i;j--){
	slope_diff = df[i] - df[j];
	if(abs(slope_diff)<eps_val){
	  m = (f[i]-f[j])/(p[i]-p[j]);
	  b = f[i] - m*p[i];
	  for(k=i+1;k<j;k++){
	    y = m*p[k]+b;
	    if(f[k]<y){
	      break;
	    }else{
	      p_left = p[i];
	      p_right = p[j];
	      done = 1;
	    }
	  }
	}
	if(done==1){break;}
      }
    }
    cout<<xAB<<" "<<p_left<<" "<<p_right<<endl;
    outputFile3<<xAB<<" "<<p_left<<" "<<p_right<<endl;


    //_________________________________________________________________________________
    xAB+=0.1;
  }while(xAB<20.0);

  outputFile3.close();

  destroy_1d_double_array(p);
  destroy_1d_double_array(f);
  destroy_1d_double_array(df);
  Allocate(-1);
 
}
