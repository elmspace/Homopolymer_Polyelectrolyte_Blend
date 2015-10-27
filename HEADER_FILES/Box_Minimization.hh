/*
  In this function, we will change the box size in x, y and z direction
  to minimize the free energy of the system as function of box size
*/
void Box_Minimization( ){

  int     i,j,k,l,ii,jj,ll,kk;
  double  delx,dely,delz;

  delx=del_Box/Nx;
  dely=del_Box/Ny;
  delz=del_Box/Nz;
  
  l=0;
  for(i=-1;i<2;i++){
    for(j=-1;j<2;j++){
      for(k=-1;k<2;k++){
    
	box_x[l]=i*delx;
	box_y[l]=j*dely;
	box_z[l]=k*delz;

	dxyz_temp[0]=dxyz[0];
	dxyz_temp[1]=dxyz[1];
	dxyz_temp[2]=dxyz[2];

	for(ii=0;ii<Nx;ii++){
	  for(jj=0;jj<Ny;jj++){
	    for(kk=0;kk<Nz;kk++){
	      for(ll=0;ll<ChainType;ll++){
		w_temp[ll][ii][jj][kk]=w[ll][ii][jj][kk];
	      }
	    }
	  }
	}
	
	dxyz_temp[0]+=box_x[l];
	dxyz_temp[1]+=box_y[l];
	dxyz_temp[2]+=box_z[l];
	
	box_fE[l]=FreeEnergy_Box_Edition( );
	
	l=l+1;
	
      }
    }
  }
  
  
  for(i=0;i<26;i++){
    ii=0;
    for(j=i+1;j<27;j++){
      if(box_fE[i]<box_fE[j]){
	ii=ii+1;
      }
    }
    if(ii==(27-(i+1))){
      break;
    }
  }

  dxyz[0]=dxyz[0]+box_x[i];
  dxyz[1]=dxyz[1]+box_y[i];
  dxyz[2]=dxyz[2]+box_z[i];
 
};

