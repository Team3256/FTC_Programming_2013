#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          feedingMotorUno, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontRightMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     tiltingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     conveyorMotor, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "driveTrain_Functions.c"
#include "JoystickDriver.c"

task main()
{
	//waitForStart();
	moveForward(5, 80);
	wait10Msec(50);
	rightTwoWheelTurn(30, 50);
	wait10Msec(40);
	//robot stops at first bucket from the right side of the pendulum
	stopMotors();
	wait10Msec(100);
			motor[tiltingMotor] = 75;
			wait10Msec(85);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
				motor[conveyorMotor] = 100;
				wait10Msec(200);
				motor[conveyorMotor] = 0;
				wait10Msec(50);
			motor[tiltingMotor] = -35;
			wait10Msec(60);
			motor[tiltingMotor] = -25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
	rightTwoWheelTurn(35, 50);
	wait10Msec(83);
	moveForward(25, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(58);
	moveForward(29, 80);
	wait10Msec(50);
	rightTwoWheelTurn(53, 50);
	wait10Msec(150);
	moveBackward(43, 80);
	wait10Msec(60);
	//robot parked in the middle of the ramp
}
