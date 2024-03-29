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
#include "sensor_Functions.c"
#include "JoystickDriver.c"

task main()
{
	waitForStart();
	moveForward(0.15, 80);
	wait10Msec(50);
	stopMotors();
	wait10Msec(30);
	rightTwoWheelTurn(45, 40);
	wait10Msec(86);
	stopMotors();
	wait10Msec(30);
	//robot moves backward, so it will be able to sense the ir beacon underneath first bucket
	moveBackward(0.5, 80);
	wait10Msec(50);
	stopMotors();
	wait10Msec(30);
	//keep going forward until ir sensor senses ir beacon
	StartTask(irRightTesting);
	wait10Msec(1500);
	//wall follow the wall until the ultrasonic sensor stops sensing the black base underneath the pendulum
	while (SensorValue[sonarSensor] < 60)
	{
		motor[frontLeftMotor] = 100;
		motor[frontRightMotor] = -100;
		motor[backRightMotor] = 100;
		motor[backLeftMotor] = 100;
	}
	stopMotors();
	wait10Msec(30);
	moveForward(2.25, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(65);
	moveForward(25, 80);
	wait10Msec(50);
	leftTwoWheelTurn(48, 50);
	wait10Msec(50);
	moveForward(34, 80);
	wait10Msec(50);
	rightTwoWheelTurn(53, 50);
	wait10Msec(152);
	moveBackward(47, 80);
	wait10Msec(50);
	//robot is parked in the middle of the ramp
}
