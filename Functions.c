//Disclaimer: All Motor Speeds are Half and the Timings are Simply Guessesd. Calibration is Required. 
/*Functions Include:
	Flywheel Slowing Down (Line 11)
	Flywheel Speeding Up (Line 19)
	Chain Lift Moving Up (Line 27)
	Chain Lift Moving Down (Line 36)
	Swinging the Claw Up (Line 45)
	Swinging the Claw Down (Line 62) */

//Flywheel Slowing Down 
void FlywheelSlowDown(){
	while(motor[port5] > 10){			//Condition for Motor To Slow Down 
		motor[port5] = motor[port5] - 4;	//Slows Motor Down By 4 Units 	
		wait1MSec(800);
		}
}

//Flywheel Speeding Up 
void FlywheelSpeedUp(){
	motor[port5] = 127;
	if(vexRT[Btn6D] == 0){		//Once Button 6 Down is Released, the Flywheel Begins to Slow Down 
		FlywheelSlowDown();
		}
}

//Chain Lift Moving Up 
void LiftUp(){
	motor[port3] = 63;
	motor[port4] = 63; 
	wait1Msec(5000);	//Potentiometer? Will be Able to Find Max Height and Stop At Max Height to Avoid Strain  
	motor[port3] = 0;
	motor[port4] = 0;
}

//Chain Lift Moving Down 
void LiftDown(){
	motor[port3] = -63;
	motor[port4] = -63; 
	wait1Msec(5000);	//Potentiometer? Will be Able to Find Max Height and Stop to Avoid Strain  
	motor[port3] = 0;
	motor[port4] = 0;
}

//Claw Moving Down 
int FlipCapDown(LocationClaw){
	if(LocationClaw == 0){			//Condition to Make Sure the Claw Does Not Move in the Same Direction Twice (1 = Up, 0 = Down)
		motor[port6] = 63;		//Turns the Claw 90 Degrees to Flip the Cap
		wait1Msec(1000);
		motor[port6] = 0;
		return 1;			//Helps Keep Track of Claw Position 
		
	}
	else{
		motor[port6] = -63; 		//Turns Claw Back to Original Position 
		wait1Msec(1000);
		motor[port6] = 0;
		return 0;
	}
}

//Claw Moving Up 
int FlipCap(LocationClaw){		 
	if(LocationClaw == 1){			//Condition to Make Sure the Claw Does Not Move in the Same Direction Twice (1 = Up, 0 = Down)
		FlipCapDown()			//Turns Claw Back to Original Position
		return 0;
	}
	else{
		motor[port6] = 63;		//Turns the Claw 90 Degrees to Flip the Cap
		wait1Msec(1000);
		motor[port6] = 0;
		return 1;
	}
}
