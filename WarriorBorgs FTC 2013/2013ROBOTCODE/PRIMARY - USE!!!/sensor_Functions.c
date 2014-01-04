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
#include "rollerAndArm_Functions.c"
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
			moveForward(4, 80);
			wait10Msec(100);
			leftTwoWheelTurn(90, 80);
			wait10Msec(98.5);
			stopMotors();
			wait10Msec(30);

			int ticksPerDegree2 = 5760/360;
			int nTicks =0;
			nTicks= ticksPerDegree2*150;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks)
			{
				motor[tiltingMotor]=75;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;
			motor[conveyorMotor] = -100;
			wait10Msec(200);
			motor[conveyorMotor] = 0;
			wait10Msec(50);
			int nTicksDown =0;
			nTicksDown = ticksPerDegree2*120;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks)
			{
				motor[tiltingMotor]=-50;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;


			rightTwoWheelTurn(90, 40);
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
			moveForward(1.5, 80);
			wait10Msec(100);
			rightTwoWheelTurn(90, 80);
			wait10Msec(109);
			stopMotors();
			wait10Msec(30);

			int ticksPerDegree2 = 5760/360;
			int nTicks =0;
			nTicks= ticksPerDegree2*150;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks)
			{
				motor[tiltingMotor]=75;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;
			motor[conveyorMotor] = -100;
			wait10Msec(200);
			motor[conveyorMotor] = 0;
			wait10Msec(50);
			int nTicksDown =0;
			nTicksDown = ticksPerDegree2*120;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks)
			{
				motor[tiltingMotor]=-50;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;

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
