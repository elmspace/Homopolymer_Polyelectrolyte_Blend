
#include "./global.hh"
#include "./HEADER_FILES/Memory.hh"
#include "./HEADER_FILES/Allocate.hh"             
#include "./HEADER_FILES/Parameters.hh"      
#include "./HEADER_FILES/Wave_Vectors.hh"    
#include "./HEADER_FILES/Omega.hh"           
#include "./HEADER_FILES/Solve_Diffusion_Equation.hh"
#include "./HEADER_FILES/Solve_PB_Equation.hh"        
#include "./HEADER_FILES/Phi_A.hh"                    
#include "./HEADER_FILES/Phi_B.hh"                    
#include "./HEADER_FILES/Phi_I.hh"
#include "./HEADER_FILES/Phi_e.hh"          
#include "./HEADER_FILES/Homogenous_Free_Energy.hh" 
#include "./HEADER_FILES/Incompressibility.hh"
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
