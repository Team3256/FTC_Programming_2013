#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          tube,          tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,          rackPinion,    tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorRight,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorLeft,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_2,    ringPlacer,           tServoStandard)
#pragma config(Servo,  srvo_S1_C2_1,    elServo,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

void drival(int right, int left)
{
	motor[motorRight] = right;
	motor[motorLeft] = left;
}

void gostraight(int encoder, int speed) {
	nMotorEncoder[motorRight] = 0;
	while(true)
	{
		if (encoder > abs(nMotorEncoder[motorRight]))
			drival(speed, speed);
		if (encoder <= abs(nMotorEncoder[motorRight]))
			break;
	}
	drival(0,0);
}

void turnleft(int encoder, int speed) {
	nMotorEncoder[motorRight] = 0;
	while(true) {
		if (encoder > abs(nMotorEncoder[motorRight]))
			drival(speed, 0);
		if (encoder <= abs(nMotorEncoder[motorRight]))
			break;
	}
	drival(0,0);
}

void turnright (int encoder, int speed) {
	nMotorEncoder[motorLeft]=0;
	while(true)
	{
		if (abs(encoder) > abs(nMotorEncoder[motorLeft]))
			drival(0, speed);
		if (abs(encoder) <= abs(nMotorEncoder[motorLeft]))
			break;
	}
	drival(0,0);
}

task main()
{
}
