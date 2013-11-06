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

#include "JoystickDriver.c"
#include "driveTrain_Functions.c"
#include "sensor_Functions.c"
#include "roller_Functions.c"
#include "it_Functions.c"

task main()
{
	waitForStart();
	//nMotorEncoder[tiltingMotor] = 0;
	//int targetTicks = 0;
	while(1==1)
	{
		writeDebugStreamLine("%d", abs(nMotorEncoder[tiltingMotor]));
		motor[frontLeftMotor] = ((100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		motor[backLeftMotor] = ((100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		motor[frontRightMotor] = ((100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		motor[backRightMotor] = ((100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		motor[feedingMotorUno] = ((100.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0));
		motor[feedingMotorDos] = ((100.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0));
		motor[conveyorMotor] = ((100.0)*(joystick.joy2_y2/127.0)*(joystick.joy2_y2/127.0)*(joystick.joy2_y2/127.0));


		//tilting(targetTicks);

		if(joy2Btn(1))
		{
			motor[tiltingMotor] = 60;
			wait10Msec(3);
			motor[tiltingMotor] = 0;
			wait10Msec(3);
			//targetTicks = 300;
			/*if(abs(nMotorEncoder[tiltingMotor]) < targetTicks)
			{
				motor[tiltingMotor] = 100;
			}
			else
			{
				motor[tiltingMotor] = 0;
			}*/
		}
		if(joy2Btn(2))
		{
			motor[tiltingMotor] = -60;
			wait10Msec(3);
			motor[tiltingMotor] = 0;
			wait10Msec(3);
			/*if(abs(nMotorEncoder[tiltingMotor]) < 75)
			{
				motor[tiltingMotor] = -100;
			}
			else
			{
				motor[tiltingMotor] = 0;
			}*/
		}
		if(joy2Btn(4))
		{
			StartTask(rollerRun);
			wait10Msec(200);
		}
		if(joy2Btn(7))
		{
			motor[liftingMotor] = -100;
			wait10Msec(800);
			motor[liftingMotor] = 0;
			wait10Msec(3);
		}
		if(joy2Btn(8))
		{
			motor[flagMotor] = 100;
			wait10Msec(600);
			motor[flagMotor] = 0;
			wait10Msec(3);
		}
		if(joystick.joy2_TopHat == 0)
	  {
	  	motor[tiltingMotor] = 75;
			wait10Msec(61);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
	  	/*if(abs(nMotorEncoder[tiltingMotor]) < 75)
			{
				motor[tiltingMotor] = 100;
			}
			else
			{
				motor[tiltingMotor] = 0;
			}*/
	  }
	  if(joystick.joy2_TopHat == 2)
	  {
	  	motor[tiltingMotor] = 75;
			wait10Msec(70);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
	  	/*if(abs(nMotorEncoder[tiltingMotor]) < 75)
			{
				motor[tiltingMotor] = 100;
			}
			else
			{
				motor[tiltingMotor] = 0;
			}*/
	  }
	  if(joystick.joy2_TopHat == 4)
	  {
	  	motor[tiltingMotor] = 75;
			wait10Msec(72);
			motor[tiltingMotor] = 25;
			wait10Msec(7);
			motor[tiltingMotor] = 0;
			wait10Msec(4);
	  	/*if(abs(nMotorEncoder[tiltingMotor]) < 75)
			{
				motor[tiltingMotor] = -100;
			}
			else
			{
				motor[tiltingMotor] = 0;
			}*/
	  }
	  if(joystick.joy2_TopHat == 6)
	  {
	  	motor[tiltingMotor] = -50;
			wait10Msec(57);
			motor[tiltingMotor] = -25;
			wait10Msec(10);
			motor[tiltingMotor] = 0;
			wait10Msec(4);
	  	/*if(abs(nMotorEncoder[tiltingMotor]) < 75)
			{
				motor[tiltingMotor] = 100;
			}
			else
			{
				motor[tiltingMotor] = 0;
			}*/
	  }
	}
}
