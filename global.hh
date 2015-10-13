#include </usr/local/include/fftw3.h>                                // This is for My Mac Pro
//#include </opt/sharcnet/fftw/3.3.2/intel/include/fftw3.h>          // This is for Sharcnet
//#include </usr/include/fftw3.h>                                    // This is for use on Landua
//#include </usr/local/include/fftw3.h>                              // This is for elmspace2
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <stdio.h>     
#include <iostream>  
#include <fstream>
#include <complex>
#include <stdlib.h>   
#include <math.h>     
#include <time.h>     
#include "./MISCELLANEOUS/smemory.hh" 


#define Nx 32
#define Ny 32
#define Nz 32

#define ChainType 3
#define Pi 3.14159

double Iomega;
double LAM, HEX, BCC;

double NA;
double fB;

double zA,zI,PA;
double diel_cons;      

fftw_plan forward_plan, inverse_plan;
fftw_complex *input_q, *transformed_q, *final_q;

fftw_plan forward_plan_PB,inverse_plan_PB;
fftw_complex *input_PB, *transformed_PB, *final_PB;

double pAave, pBave, pIave;


