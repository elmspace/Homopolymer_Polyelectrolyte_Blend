
reset
set autoscale
unset key

f(x)=-24.55

plot   "/work/dehghan/whale/real_space_ABCDE/Polyelectrolyte_Systems/Charged_Neutral_Homopolymers/A_B_I/out.log" using 1:2 with linespoints lt 1,\
   "/work/dehghan/whale/real_space_ABCDE/Polyelectrolyte_Systems/Charged_Neutral_Homopolymers/A_B_I_2/out.log" using 1:2 with linespoints lt 2,\
      f(x)
 
  