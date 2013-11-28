#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          feedingMotorUno, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     backRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     tiltingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     conveyorMotor, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "driveTrain_Functions.c"
#include "sensor_Functions.c"



task main()
{
	moveForward(3, 80);
	wait10Msec(50);
	stopMotors();
	wait10Msec(30);
	leftTwoWheelTurn(45, 50);
	wait10Msec(50);
	stopMotors();
	wait10Msec(30);
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
	moveBackward(2, 80);
	wait10Msec(50);
	//robot moves backward, so it will be able to sense the ir beacon underneath first bucket
	stopMotors();
	wait10Msec(30);
	//keep going forward until ir sensor senses ir beacon
	StartTask(irLeftTesting);
	wait10Msec(800);
	//wall follow the wall until the ultrasonic sensor stops sensing the black base underneath the pendulum
	while (SensorValue[sonarSensor] < 75)
	{
		motor[frontLeftMotor] = 100;
		motor[frontRightMotor] = 100;
		motor[backRightMotor] = 100;
		motor[backLeftMotor] = 100;
	}
	stopMotors();
	wait10Msec(30);
			motor[tiltingMotor] = 75;
			wait10Msec(85);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
	moveForward(8, 80);
	wait10Msec(50);
	rightTwoWheelTurn(48, 50);
	wait10Msec(60);
	moveForward(25, 80);
	wait10Msec(50);
	rightTwoWheelTurn(48, 50);
	wait10Msec(58);
	moveForward(28.5, 80);
	wait10Msec(50);
	leftTwoWheelTurn(53, 50);
	wait10Msec(120);
	moveBackward(43.5, 80);
	wait10Msec(50);
	//robot is parked in the middle of the ramp
}
