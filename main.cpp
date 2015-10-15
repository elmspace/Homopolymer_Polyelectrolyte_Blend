
#include "./global.hh"                                                        // Status= OK
#include "./HEADER_FILES/Parameters.hh"                                       // Status= 
#include "./HEADER_FILES/Wave_Vectors.hh"                                     // Status= 
#include "./HEADER_FILES/Omega.hh"                                            // Status= 
#include "./HEADER_FILES/Solve_Diffusion_Equation.hh"                         // Status= 
#include "./HEADER_FILES/Solve_PB_Equation.hh"                                // Status= 
#include "./HEADER_FILES/Phi_A.hh"                                            // Status= 
#include "./HEADER_FILES/Phi_B.hh"                                            // Status= 
#include "./HEADER_FILES/Phi_I.hh"                                            // Status= 
#include "./HEADER_FILES/Homogenous_Free_Energy.hh"                           // Status= 
#include "./HEADER_FILES/Incompressibility.hh"                                // Status= 
#include "./HEADER_FILES/Box_Minimization_Free_Energy.hh"                     // Status= 
#include "./HEADER_FILES/Box_Minimization.hh"                                 // Status= 
#include "./HEADER_FILES/Free_Energy.hh"                                      // Status= 

using namespace std;


int main(){



  Allocate(1);
  Parameters( );
 
  omega( );

  FreeEnergy( );
  

  return 0;
}
