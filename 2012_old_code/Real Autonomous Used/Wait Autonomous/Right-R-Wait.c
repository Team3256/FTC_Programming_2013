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
#define RP_POSITION_1 60
#define ES_POSITION_1 201
#define RP_POSITION_2 255
#define ES_POSITION_2 72
#define RP_POSITION_3 156
#define RACK_ALIGN_POSITION 100

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
	//initializeRobot();
	waitForStart();
	wait10Msec(900);
	servoChangeRate[elServo]=1;
	servoChangeRate[ringPlacer]=1;
	servo[elServo] = ES_POSITION_1;
	servo[ringPlacer] = RP_POSITION_3;
	servoChangeRate[elServo]=10;
	servoChangeRate[ringPlacer]=10;
	wait10Msec(200);
	gostraight (2500, 80);
	turnright (4350, 80);
	gostraight (3650, 80);
	wait10Msec(200);
	servo[elServo] = ES_POSITION_2;
	servo[ringPlacer] = RP_POSITION_2;
	wait10Msec(200);
	servo[ringPlacer] = RP_POSITION_3;
	wait10Msec(200);
	turnright(180, 80);
	turnleft(180, 80);
	turnright(180, 80);
	turnleft(180, 80);
	drival (-50, -50);
	wait10Msec(200);
	drival (0, 0);
	drival (0, 0);
}
