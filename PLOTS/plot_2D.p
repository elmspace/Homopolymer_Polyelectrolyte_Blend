reset

#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/PHI/"
path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/PHI/"
#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/PHI/" # Elmspace
path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/PHI/" # Mac

set pm3d
set iso 10
set samp 10
set palette model RGB
set dgrid3d 64,64,1
set pm3d flush begin ftriangles scansforward interpolate 10,5
   
unset key
unset sur
set hidden3d
set view map 
set autoscale
set size square

   splot path."phi2D.dat" using 1:2:($3+$4+$5+$6+$7)
