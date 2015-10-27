reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/RESULTS/" # Mac
#path= "/1/home/dehgha2/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/Homopolymer_Polyelectrolyte_Blend/RESULTS/"

set autoscale
set key r c


plot   path."HomfE_2.dat" using 1:2 title "A" w lp


pause(-1)

reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/RESULTS/" # Mac
#path= "/1/home/dehgha2/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/Homopolymer_Polyelectrolyte_Blend/RESULTS/"

set autoscale
set key r c


plot   path."HomfE.dat" using 1:2 title "A" w lp

pause(-1)
