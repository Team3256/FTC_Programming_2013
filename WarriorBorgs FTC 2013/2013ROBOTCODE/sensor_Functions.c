#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     lightSensor,    sensorLightActive)
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
float inchesMoved;

// task that turns left when an IR seeker finds the IR beacon underneath a box to put the autonomous block
task irRightTesting()
{
	while(true)
	{
		if(SensorValue(irSensor) == 5)
		{
			stopMotors();
			wait10Msec(40);
			//moveForward(4, 80);
			//wait10Msec(100);
			leftTwoWheelTurn(90, 80);
			wait10Msec(95);
			stopMotors();
			wait10Msec(30);
			motor[tiltingMotor] = 75;
			wait10Msec(105);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
				motor[conveyorMotor] = 100;
				wait10Msec(200);
				motor[conveyorMotor] = 0;
				wait10Msec(50);
			motor[tiltingMotor] = -35;
			wait10Msec(350);
			motor[tiltingMotor] = -25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
			rightTwoWheelTurn(90, 80);
			wait10Msec(110);
			stopMotors();
			wait10Msec(100);
			break;
		}
		else
		{
			motor[frontLeftMotor] = 100;
			motor[frontRightMotor] = -100;
			motor[backRightMotor] = 100;
			motor[backLeftMotor] = 100;
		}
	}
}
// task that turns right when an IR seeker finds the IR beacon underneath a box to put the autonomous block
task irLeftTesting()
{
	while(true)
	{
		if(SensorValue(irSensor) == 5)
		{
			stopMotors();
			wait10Msec(40);
			moveForward(4, 80);
			wait10Msec(100);
			rightTwoWheelTurn(90, 80);
			wait10Msec(109);
			stopMotors();
			wait10Msec(30);
			motor[tiltingMotor] = 75;
			wait10Msec(105);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
				motor[conveyorMotor] = 100;
				wait10Msec(200);
				motor[conveyorMotor] = 0;
				wait10Msec(50);
			motor[tiltingMotor] = -35;
			wait10Msec(350);
			motor[tiltingMotor] = -25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
			leftTwoWheelTurn(90, 80);
			wait10Msec(95.5);
			stopMotors();
			wait10Msec(100);
			break;
		}
		else
		{
			motor[frontLeftMotor] = 100;
			motor[frontRightMotor] = -100;
			motor[backRightMotor] = 100;
			motor[backLeftMotor] = 100;
		}
	}
}
/*
task main()
{
	StartTask(irTesting);
}
*/
