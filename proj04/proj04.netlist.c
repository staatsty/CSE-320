
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Replace with code for your Pulsers
  Pulser ((SD("2a"), "Initial "),  Init, 'i', 1000);
  Pulser ((SD("3a"), "Clock"), Clock, 'c', 1000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );
  
  // Replace with code for your Probes
  Probe ( (SD("1f"), "w"), w );
  Probe ( (SD("2f"), "x"), x );
  Probe ( (SD("3f"), "y"), y );
  Probe ( (SD("4f"), "z"), z );
  
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Replace with declarations for any auxiliary Signals
  Signal W, X, Y, Z, not_w, not_x, not_y, not_z, and_gate_1, and_gate_2, and_gate_3, and_gate_4, and_gate_5;
  
  
  // Replace with code for your DFFs
  Dff (SD(sd,"1d"), (Init, W, Clock, Zero), w);
  Dff (SD(sd,"2d"), (Zero, X, Clock, Init), x);
  Dff (SD(sd,"3d"), (Init, Y, Clock, Zero), y);
  Dff (SD(sd,"4d"), (Zero, Z, Clock, Init), z);

  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd, "1a"), w, not_w );
  Not ( SD(sd, "2a"), x, not_x );
  Not ( SD(sd, "3a"), y, not_y );
  Not ( SD(sd, "4a"), z, not_z );
  
  
  And ( SD(sd, "1b"), (y,z), and_gate_1 );   // and gates
  And ( SD(sd, "2b"), (x, not_z), and_gate_2);
  And ( SD(sd, "3b"), (not_x, not_z), X);
  And ( SD(sd, "4b"), (x, not_z), and_gate_3);
  And ( SD(sd, "5b"), (not_w, not_x, not_y, z), and_gate_4);
  And ( SD(sd, "6b"), (not_w, z), and_gate_5 );
  
  
  Or ( SD(sd, "1b"), (and_gate_1, and_gate_2), W );    // or gates
  Or ( SD(sd, "2b"), (and_gate_3, and_gate_4), Y );
  Or ( SD(sd, "3b"), (y, and_gate_5), Z );
  
  
}
