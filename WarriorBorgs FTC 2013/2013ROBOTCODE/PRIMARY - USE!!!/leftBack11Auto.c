//A Rishi Desai Production
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          feedingMotorUno, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          flagPositionMotor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontRightMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     tiltingMotor,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     conveyorMotor, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "driveTrain_Functions.c"
#include "JoystickDriver.c"
#include "rollerAndArm_Functions.c"

task main()
{
	waitForStart();
	moveForward(3, 80);
	wait10Msec(50);
	rightTwoWheelTurn(45, 50);
	wait10Msec(58);
	moveForward(44.5, 80);
	wait10Msec(50);
	leftTwoWheelTurn(45, 50);
	wait10Msec(135);
	//robot positioned at the third box from the left side of the pendulum
	stopMotors();
	wait10Msec(100);
	/*
			motor[tiltingMotor] = 75;
			wait10Msec(105);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
				motor[conveyorMotor] = 100;
				wait10Msec(350);
				motor[conveyorMotor] = 0;
				wait10Msec(50);
			motor[tiltingMotor] = -35;
			wait10Msec(105);
			motor[tiltingMotor] = -25;
			wait10Msec(10);
			motor[tiltingMotor] = 0;
			wait10Msec(10);*/

			armUp();
			wait10Msec(200);
			conveyorBackward();
			wait10Msec(200);
			conveyorStop();
			wait10Msec(100);
			armDown();
			wait10Msec(200);

	rightTwoWheelTurn(42, 50);
	wait10Msec(143);
	moveForward(13, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(68);
	moveForward(32, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(50);
	moveForward(30.5, 80);
	wait10Msec(50);
	rightTwoWheelTurn(53, 50);
	wait10Msec(165);
	moveBackward(44, 80);
	wait10Msec(50);
	//robot is parked in the ramp, in the middle
}
