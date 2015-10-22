double FreeEnergy_Box_Edition(double ****w_temp, double ****phi, double ***eta, double *Ns, double ds, double ***k_vector, double *chi, double *dxyz_temp, double **chiMatrix){

  double  QA,QB,QI; 
  double  fES,currentfE; 

  Wave_Vectors(1);
  
  QA=Phi_A(w_temp,dxyz_temp);
  QB=Phi_B(w_temp,dxyz_temp);
  QI=Phi_I(w_temp,dxyz_temp);
  
  fES=pAave*log(QA)+(pBave*log(QB)/kappa)+(pIave*NA*log(QI));
  currentfE=-fES;
  
  return currentfE;
  
};
