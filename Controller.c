//Shaft Encoder Motor Needs to Be Reversed

//Flywheel Slowing Down 
void FlywheelSlowDown(){
	while(motor[port5] > 10 && motor[port6] > 10){			//Condition for Motor To Slow Down 
		motor[port5] = motor[port5] - 8;	//Slows Motor Down By 8 Units 	
		motor[port6] = motor[port6] - 8;
		motor[port7] = motor[port7] - 8;
		wait1MSec(800);
		if(motor[port7] > 0 && motor[port7] < 10){
			break;
		}
		if(motor[port5] > 0 && motor[port5] < 10 && motor[port6] > 0 && motor[port6] < 10){
			break;
		}
		if(vexRt[Btn6U] == 1){
			break;
		}
		}
		motor[port5] = 0;
		motor[port6] = 0;
		motor[port7] = 0;
}

//Flywheel Speeding Up 
void FlywheelSpeedUp(){
	motor[port5] = 127;
	motor[port6] = 127;
	motor[port7] = 127;
	if(vexRT[Btn6D] == 0){		//Once Button 6 Down is Released, the Flywheel Begins to Slow Down 
		FlywheelSlowDown();
		}
}

//Chain Lift Moving to High Pole 
void LiftUpHigh(){		//Will Move Elevator Lift to the Correct Height of TALL Pole
	while(SensorValue[potentiometer] != 200){
		motor[port3] = 127;
		motor[port4] = 127;
	}
	motor[port3] = 0;
	motor[port4] = 0;
}

//Chain Lift Moving to Low Pole 
void LiftUpLow(){		//Will Move Elevator Lift to the Correct Height of LOW Pole
	while(SensorValue[potentiometer] != 100){
		if(SensorValue[potentiometer] > 100){
			motor[port3] = -127;
			motor[port4] = -127;
		}
		else{
			motor[port3] = 127;
			motor[port4] = 127;
		}
	}
	motor[port3] = 0;
	motor[port4] = 0;
}

//Chain Lift Moving Down 
void LiftDown(){
	while(SensorValue[potentiometer] != 0){
		motor[port3] = -127;
		motor[port4] = -127;
	}
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
task main(){
	while(1){
		motor[port1] = (vexRT[Ch3] + vexRt[Ch4])/2;
		motor[port2] = (vexRT[Ch3] - vexRT[Ch4])/2;
		
		if(vexRt[Btn6U] == 1){		//Will Activate Flywheels and Ball Lift
			FlywheelSpeedUp();
		}
		if(vexRT[Btn6D] == 1){
			LiftDown();
		}
	
		if(vexRT[Btn5U] == 1){		//Will Move Elevator Lift to the Correct Height of TALL Pole 
			LiftUpHigh();
		}
		
		if(vexRT[Btn5D] == 1){		//Will Move Elevator Lift to the Correct Height of Low Pole
			LiftUpLow();
		}
	}
}
