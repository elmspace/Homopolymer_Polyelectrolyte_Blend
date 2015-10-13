double FreeEnergy_Box_Edition(double ****w_temp, double ****phi, double ***eta, double *Ns, double ds, double ***k_vector, double *chi, double *dxyz_temp, double **chiMatrix){

  double  QA,QB,QI; 
  double  fES,currentfE; 

  WaveVectors(k_vector,dxyz_temp);
  
  
  
  QA=ConcA(phi,w_temp,Ns,ds,k_vector,dxyz_temp);
  QB=ConcB(phi,w_temp,Ns,ds,k_vector,dxyz_temp);
  QI=ConcI(phi,w_temp,Ns,dxyz_temp);
  
  
  fES=pAave*log(QA)+(pBave*log(QB)/fB)+(pIave*NA*log(QI))-(pAave*log(pAave))-(pBave*log(pBave)/fB)-(pIave*NA*log(pIave));
  currentfE=-fES;
  
  return currentfE;
  
};
