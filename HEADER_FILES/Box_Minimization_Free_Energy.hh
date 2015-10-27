/*
  In this function, which is being called by Box_Minimization function
  will calculate the entropy of the system for a small change in box size
*/
double FreeEnergy_Box_Edition( ){

  double  QA,QB,QI; 
  double  fES,currentfE; 

  Wave_Vectors(dxyz_temp);
  
  QA=Phi_A(w_temp,dxyz_temp);
  QB=Phi_B(w_temp,dxyz_temp);
  QI=Phi_I(w_temp,dxyz_temp);
  
  fES=pAave*log(QA)+(pBave*log(QB)/kappa)+(pIave*NA*log(QI));
  currentfE=-fES;
  
  return currentfE;
  
};
