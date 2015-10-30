reset

#path= "/Users/ashkandehghan/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/RESULTS/" # Mac
path= "/1/home/dehgha2/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/Homopolymer_Polyelectrolyte_Blend/RESULTS/"

set autoscale
set key r c

set xr [0.0 : 1.0]

plot path."Spinodal.dat" using 2:1 title "A" pt 6 lc 3 w p,\
 path."Spinodal.dat" using 3:1 title "A" pt 6 lc 3 w p


pause(-1)

reset

#path= "/Users/ashkandehghan/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/RESULTS/" # Mac
path= "/1/home/dehgha2/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/Homopolymer_Polyelectrolyte_Blend/RESULTS/"

set autoscale
set key r c
set xr [0.0 : 1.0]

plot   path."HomfE.dat" using 1:2 title "A" w lp

pause(-1)
