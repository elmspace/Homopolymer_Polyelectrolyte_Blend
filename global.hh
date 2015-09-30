#include <stdio.h>     //Include the standard input/output libraries
#include <iostream>  //Cout and Cin etc.
#include <fstream>
#include <complex>
#include <stdlib.h>    //Include standard fucntion libraries
#include <math.h>      //Use the math function libraries
#include <time.h>      //Call system time libraries to define the integer seed for random numbers
#include "./include/smemory.hh"  //Use my custom memory handling class
#include </opt/sharcnet/fftw/3.3.2/intel/include/fftw3.h>

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
double diel_cons;        //Dielectric constant

fftw_plan forward_plan, inverse_plan;
fftw_complex *input_q, *transformed_q, *final_q;

fftw_plan forward_plan_PB,inverse_plan_PB;
fftw_complex *input_PB, *transformed_PB, *final_PB;

double pAave, pBave, pIave;


