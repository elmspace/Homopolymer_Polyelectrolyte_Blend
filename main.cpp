
#include "./global.hh"
#include "./ABI/parametersABI.hh"
#include "./ABI/WaveVectors.hh"
#include "./ABI/omega.hh"
#include "./ABI/solvediffeq.hh"
#include "./ABI/solvePBE.hh"
#include "./ABI/ConcA.hh"
#include "./ABI/ConcB.hh"
#include "./ABI/ConcI.hh"
#include "./ABI/fEhomo.hh"
#include "./ABI/Incomp.hh"
#include "./ABI/FreeEnergy_Box_Edition.hh"
#include "./ABI/size_adjust.hh"
#include "./ABI/FreeEnergy.hh"

using namespace std;


int main(){

  double ****w;
  double ****phi;

  double ***psi;

  double ***eta;

  double *chi;
  double **chiMatrix;
  double *f;
  double ds;
  double *Ns;
  double ***k_vector;
  double *dxyz;

  
  w=create_4d_double_array(ChainType,Nx,Ny,Nz,"w");
  phi=create_4d_double_array(ChainType,Nx,Ny,Nz,"phi");

  psi=create_3d_double_array(Nx,Ny,Nz,"psi");

  eta=create_3d_double_array(Nx,Ny,Nz,"eta");

  chi=create_1d_double_array(3,"chi");            // here we have 3 different interactions
  f=create_1d_double_array(ChainType,"f");
  Ns=create_1d_double_array(ChainType,"Ns");
  k_vector=create_3d_double_array(Nx,Ny,Nz,"k_vector");
  dxyz=create_1d_double_array(3,"dxyz");
  chiMatrix=create_2d_double_array(ChainType,ChainType,"chiMatrix");

  long iseed;
  time_t t;
  iseed=time(&t);
  srand48(iseed);

  // Setting up the FFTW for MDE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  input_q=(fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
  transformed_q=(fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
  final_q=(fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);

  forward_plan=fftw_plan_dft_3d(Nx,Ny,Nz,input_q,transformed_q,FFTW_FORWARD,FFTW_MEASURE);
  inverse_plan=fftw_plan_dft_3d(Nx,Ny,Nz,transformed_q,final_q,FFTW_BACKWARD,FFTW_MEASURE);
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  // Setting up FFTW for PBE 
  input_PB=(fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
  transformed_PB=(fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);
  final_PB=(fftw_complex *)fftw_malloc(sizeof(fftw_complex)*Nx*Ny*Nz);

  forward_plan_PB=fftw_plan_dft_3d(Nx,Ny,Nz,input_PB,transformed_PB,FFTW_FORWARD,FFTW_MEASURE);
  inverse_plan_PB=fftw_plan_dft_3d(Nx,Ny,Nz,transformed_PB,final_PB,FFTW_BACKWARD,FFTW_MEASURE);
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  parametersAB(chi,f,ds,Ns,dxyz,chiMatrix);
 
  omega(w);

  FreeEnergy(w,phi,psi,eta,Ns,ds,k_vector,chi,dxyz,chiMatrix);
  


  //Destroy memory allocations------------
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
  destroy_3d_double_array(psi);
  destroy_3d_double_array(eta);
  destroy_4d_double_array(phi);
  destroy_1d_double_array(chi);
  destroy_1d_double_array(Ns);
  destroy_1d_double_array(f);
  destroy_3d_double_array(k_vector);
  destroy_1d_double_array(dxyz);
  destroy_2d_double_array(chiMatrix);
  //-------------------------------------


  return 0;
}
