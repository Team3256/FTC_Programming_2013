#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNXT, PIDControl,reversed, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl,reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     backRightMotor, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     frontRightMotor, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     frontLeftMotor, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float pie = 3.1415926;
float track = 6.5;
float halftrack = track / 2;
int wheelDiam = 2.5;
float wheelRadius = 1.5;
float wheelCircumference = wheelDiam * PI;
float ticksPerInches = 360 / wheelCircumference;
float halfRobotCircumference = track / PI;
float robotCircumference = track * 2 * PI;
float inchesPerDegreeOneWheel = wheelCircumference / robotCircumference;
float inchesPerDegreeTwoWheel = wheelCircumference / halfRobotCircumference;

void straight(float inchesMoved, int motorSpeed){
	float nticks = 0;
	nticks =  abs(inchesMoved *ticksPerInches);
	nMotorEncoder[motorC] = 0;
	while(abs(nMotorEncoder[motorC]) < nticks){
		motor[motorC] = motorSpeed;
		motor[motorB] = motorSpeed;

	}
}
void leftTwoWheelTurn(int degreesMoved){
	float nticks =0;
	nticks = abs((degreesMoved*halfTrack)/wheelRadius);

	nMotorEncoder[motorC]=0;
	while(nMotorEncoder[motorC] < nticks){
		motor[motorC] = 40;
		motor[motorB] = -40;

	}
	nticks =0;
}
void  rightTwoWheelTurn(int degreesMoved){
	float nticks = 0;
	nticks = abs((degreesMoved*halfTrack)/wheelRadius);
	nticks*=0.94;
	nMotorEncoder[motorB]=0;
	while(nMotorEncoder[motorB] < nticks){
		motor[motorC] = -40;
		motor[motorB] = 40;
	}

}

task main()
{
motor[motorA] = -20;
wait10Msec(20);
straight(5,60);
rightTwoWheelTurn(90);
straight(2,30);
wait10Msec(40);
leftTwoWheelTurn(90);

}