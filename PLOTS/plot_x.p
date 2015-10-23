reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/Homopolymer_Polyelectrolyte_Blend/PHI/" # Mac

set autoscale
set key r c


plot   path."phi_x.dat" using 1:2 title "A" w lp,\
path."phi_x.dat" using 1:3 title "B" w lp,\
path."phi_x.dat" using 1:4 title "I" w lp



