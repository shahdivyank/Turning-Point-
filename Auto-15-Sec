//5 Point Autonomous Mode ( 2 Points Cap, 1 Point Low Flag, 2 Points Middle Flag)
//http://cdn.robotc.net/pdfs/natural-language/Natural_Language_Cortex.pdf
//Time and Speed Have to Be Calibrated Accordingly 
//Port 1 and Port 2 Are Desginated for Wheels 
//Port 1 = Left Back Wheel (Looking From Front View)
//Port 2 = Right Back Wheel (Looking From Front View)

task main() {
  startMotor(port1, 63);  //Moves Straight to Aim for Cap of Opposite Color 
  startMotor(port2, 63);
  wait1Msec(2000);
  stopMotor(port1);
  stopMotor(port2);
  
  motorflip();            //Puts Cap On Right Color 
  
  startMotor(port1, -63);  //Turns Robot 180 Degrees and Places it in Front of the Pole 
  startMotor(port2, 63);
  wait1Msec(2000);
  stopMotor(port1);
  stopMotor(port2);
  
  liftup();               //Lifts the Slides
  
  startMotor(port1, 63);  //Moves Straight Towards Pole  
  startMotor(port2, 63);
  wait1Msec(3000);
  stopMotor(port1);
  stopMotor(port2);
  
  liftdown();             //Brings Down the Lift
  
  startMotor(port1, 45);  //Places Robot Aligned with Flag Poles With Back Facing It
  startMotor(port2, -45);
  wait1Msec(1000);
  stopMotor(port1);
  stopMotor(port2);
  
  flywheel();             //Hits the Middle or High Flag with the Preload
  
  startMotor(port1, 63);  //Hits the Lowest Level Flag
  startMotor(port2, 63);
  
]
