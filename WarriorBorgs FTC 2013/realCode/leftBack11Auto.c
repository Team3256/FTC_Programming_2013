#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touchSensor,    sensorTouch)
#pragma config(Motor,  motorA,          feedingMotorUno, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     flagMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     liftingMotor,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     frontRightMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     backRightMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     tiltingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     conveyorMotor, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "driveTrain_Functions.c"

task main()
{
	moveForward(5, 80);
	wait10Msec(50);
	rightTwoWheelTurn(45, 50);
	wait10Msec(57);
	moveForward(45, 80);
	wait10Msec(50);
	leftTwoWheelTurn(45, 50);
	wait10Msec(134);
	stopMotors();
	wait10Msec(100);
	rightTwoWheelTurn(42, 50);
	wait10Msec(133);
	moveForward(7, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(53.5);
	moveForward(25, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(58);
	moveForward(33, 80);
	wait10Msec(50);
	rightTwoWheelTurn(53, 50);
	wait10Msec(150);
	moveBackward(44, 80);
	wait10Msec(50);
}