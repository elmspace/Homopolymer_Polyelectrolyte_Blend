/*
   Global.hh conatins variables which will be used all throughout the program
   The path for fftw libraries for the devices which this code will be used on is included
 */

//#include </usr/local/include/fftw3.h>                                // This is for My Mac Pro
//#include </opt/sharcnet/fftw/3.3.2/intel/include/fftw3.h>          // This is for Sharcnet
#include </usr/include/fftw3.h>                                    // This is for use on Landua
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Box resolution
#define Nx 20
#define Ny 20
#define Nz 20

#define ChainType 3
#define Pi 3.14159

// Box minimization on/off
int Box_min = 0;

// Print during run time
int RunTimePrint= 1;

// Setting Parameters
double NA = 100;
double NB = NA;
double NI = 1;
double PA = 0.0000000001;
double tau = 100.0;
double epsilon = 6.5;
double xAB = 3.0;
double xAI = 0.0;
double xBI = 0.0;
double Lx = 4.0;
double Ly = 4.0;
double Lz = 4.0;
double epsilon_w = 0.01;
double epsilon_p = 0.01;
double precision=1.0e-3; 
double del_Box=0.1;

double pAave = 0.5;
double pBave = 1.0-pAave;
double pIave = pAave*PA;
double ds = 1.0/NA;
double kappa = NB/NA;

double ****w, ****phi;
double ***w_e, ***phi_e;
double ***eff_wA, ***eff_wI;
double ***V;
double ***Gradient_V_x;
double ***Gradient_V_y;
double ***Gradient_V_z;
double ***eta;
double *chi;
double **chiMatrix;
int *Ns;
double ***k_vector;
double *dxyz;
double *Kx,*Ky,*Kz;
double ***delphi;
double ****delW;
double ****newW;
double *dxyz_temp;
double *box_x,*box_y,*box_z;
double *box_fE;
double ****w_temp;

double ****qA;
double ****qB;
double ***qI;
double ***qint;

double ***wds, ***kds;

int Iomega;
int LAM, HEX, BCC;

// FFTW Parameters
fftw_plan forward_plan, inverse_plan;
fftw_complex *input_q, *transformed_q, *final_q;
fftw_plan forward_plan_PB,inverse_plan_PB;
fftw_complex *input_PB, *transformed_PB, *final_PB;



