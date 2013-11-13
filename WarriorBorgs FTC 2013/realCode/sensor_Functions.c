#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     touchSensorDos,    sensorLightActive)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touchSensorUno,    sensorTouch)
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
#include "leftIRAuto.c"

float inchesMoved;
bool taskEnder= false;

// task that turns left when an IR seeker finds the IR beacon underneath a box to put the autonomous block
task irRightTesting()
{
	while(true)
	{
		if(SensorValue(irSensor) == 5)
		{
			//inchesMoved= nMotorEncoder[backLeftMotor]/ticksPerInches;
			stopMotors();
			wait10Msec(40);
			moveForward(4, 80);
			wait10Msec(100);
			leftTwoWheelTurn(90, 80);
			wait10Msec(82);
			stopMotors();
			wait10Msec(30);
			rightTwoWheelTurn(90, 80);
			wait10Msec(100);
			stopMotors();
			wait10Msec(30);
			/*float tester = inchesMoved * 1.1612;
			if(tester <= 6)
			{
				writeDebugStreamLine("1");
				moveForward(50, 80);
				wait10Msec(30);
				//taskEnder = true;
				break;
			}
				else if(tester >= 14 && tester <=41)
			{
				writeDebugStreamLine("2");
				moveForward(45, 80);
				wait10Msec(30);
				//taskEnder = true;
				break;
			}
				else if(tester >= 42 && tester <= 51)
			{
				writeDebugStreamLine("3");
				moveForward(40, 80);
				wait10Msec(30);
				//taskEnder = true;
				break;
			}else if(tester >= 51)
			{

					moveForward(29, 80);
					wait10Msec(30);
					//taskEnder = true;
					break;
			}*/

		}
		else
		{
			motor[frontLeftMotor] = 100;
			motor[frontRightMotor] = 100;
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
			inchesMoved= nMotorEncoder[backLeftMotor]/ticksPerInches;
			wait10Msec(40);
			moveForward(3, 80);
			wait10Msec(50);
			rightTwoWheelTurn(90, 80);
			wait10Msec(86);
			motor[frontLeftMotor] = 0;
			motor[frontRightMotor] = 0;
			motor[backRightMotor] = 0;
			motor[backLeftMotor] = 0;
			wait10Msec(100);
			leftTwoWheelTurn(90, 80);
			wait10Msec(102);
			break;
		}
		else if(SensorValue(irSensor) >= 1 || SensorValue(irSensor) <= 4)
		{
			motor[frontLeftMotor] = 100;
			motor[frontRightMotor] = 100;
			motor[backRightMotor] = 100;
			motor[backLeftMotor] = 100;
		}
		else if (SensorValue(irSensor) >= 6 || SensorValue(irSensor) <= 9)
		{
			motor[frontLeftMotor] = 100;
			motor[frontRightMotor] = 100;
			motor[backRightMotor] = 100;
			motor[backLeftMotor] = 100;
		}
	}
}

void irPositionTest(int inches)
{
	wait10Msec(100);
	inches *= 1.1612;
	if(inches<=12)
	{
		moveForward(69, 80);
	}
	else if(inches>=12 && inches<=22)
	{
		moveForward(59, 80);
	}
	else if(inches>=22 && inches<=41)
	{
		moveForward(40, 80);
	}
	else if(inches>=41 && inches<=50)
	{
		moveForward(29, 80);
	}
}

/*
task main()
{
	StartTask(irTesting);
}
*/
