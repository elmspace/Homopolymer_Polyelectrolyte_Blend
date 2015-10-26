
#include "./global.hh" //Ok
#include "./HEADER_FILES/Memory.hh" //Ok
#include "./HEADER_FILES/Allocate.hh" //Ok     
#include "./HEADER_FILES/Parameters.hh" //Ok
#include "./HEADER_FILES/Wave_Vectors.hh" //Ok
#include "./HEADER_FILES/Omega.hh" // Ok
#include "./HEADER_FILES/Solve_Diffusion_Equation.hh" // Ok
#include "./HEADER_FILES/Solve_PB_Equation.hh" // Ok
#include "./HEADER_FILES/Phi_A.hh" // Ok
#include "./HEADER_FILES/Phi_B.hh" // Ok
#include "./HEADER_FILES/Phi_I.hh" // Ok
#include "./HEADER_FILES/Phi_e.hh" // Ok
#include "./HEADER_FILES/Homogenous_Free_Energy.hh" // Ok
#include "./HEADER_FILES/Incompressibility.hh" // Ok
#include "./HEADER_FILES/Box_Minimization_Free_Energy.hh" 
#include "./HEADER_FILES/Box_Minimization.hh"
#include "./HEADER_FILES/Gradient.hh"
#include "./HEADER_FILES/Save_Data.hh"
#include "./HEADER_FILES/Free_Energy.hh" 

using namespace std;

int main(){
  
  Allocate(1);
  Parameters( );
  omega( );
  FreeEnergy( );
  Allocate(-1);
  
  return 0;
}
