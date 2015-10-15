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



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define Nx 32
#define Ny 32
#define Nz 32

#define ChainType 3
#define Pi 3.14159

// Setting Parameters

double NA = 100;
double NB = NA;
double NI = 1;
double PA = 0.001;
double tau = 100.0;
double epsilon = 4.6;
double xAB = 20.0;
double xAI = 0.0;
double xBI = 0.0;
double Lx = 5.0;
double Ly = 5.0;
double Lz = 5.0;
double epsilon_w = 0.05;
double epsilon_p = 0.05;
double precision=1.0e-3; 

double pAave = 0.5;
double pBave = 1.0-pAave;
double pIave = pAave*PA;
double ds = 1.0/NA;
double kappa = NA/NB;

double ****w, ****phi;
double ***w_e, ***phi_e;
double ***eff_wA, ***eff_wI;
double ***V;
double ***Gradient_V;
double ***eta;
double *chi;
double **chiMatrix;
double *Ns;
double ***k_vector;
double *dxyz;
double *Kx,*Ky,*Kz;
double  ***delphi;
double  ****delW;
double  ****newW;


double ****qA;
double ****qB;
double ***qI;
double ***qint;



int Iomega;
int LAM, HEX, BCC;


fftw_plan forward_plan, inverse_plan;
fftw_complex *input_q, *transformed_q, *final_q;

fftw_plan forward_plan_PB,inverse_plan_PB;
fftw_complex *input_PB, *transformed_PB, *final_PB;




