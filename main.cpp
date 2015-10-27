
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
#include "./HEADER_FILES/Box_Minimization_Free_Energy.hh" // Ok 
#include "./HEADER_FILES/Box_Minimization.hh" // Ok (Needs varification for results)
#include "./HEADER_FILES/Gradient.hh" // Ok (Tested using dummy function, and it works)
#include "./HEADER_FILES/Save_Data.hh" // Ok
#include "./HEADER_FILES/Free_Energy.hh" // Ok

#include "./MODS/Mod0.hh"
#include "./MODS/Mod1.hh"

using namespace std;

int main(){
  

  Mod0();

  
  return 0;
}
