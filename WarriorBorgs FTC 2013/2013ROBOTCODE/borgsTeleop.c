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

//including all the files into this teleop program
#include "JoystickDriver.c"
#include "driveTrain_Functions.c"
#include "sensor_Functions.c"
#include "roller_Functions.c"

task main()
{
	waitForStart();
	while(1==1)
	{
		//left two motors controlled by the right joystick in controller one
		motor[frontLeftMotor] = ((-100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		motor[backLeftMotor] = ((-100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		//right two motors controlled by the left joystick in controller one
		motor[frontRightMotor] = ((100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		motor[backRightMotor] = ((-100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		//two feeding motors controlled by the left joystick in controller two
		motor[feedingMotorUno] = ((100.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0));
		motor[feedingMotorDos] = ((100.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0));
		//conveyor motor controlled by the right joystick in controller two (should be pushed at the same time as left joystick in controller two is pushed)
		motor[conveyorMotor] = ((100.0)*(joystick.joy2_y2/127.0)*(joystick.joy2_y2/127.0)*(joystick.joy2_y2/127.0));
		//tilting motor moves a little bit down when button one in controller two is pressed
		if(joy2Btn(1))
		{
			motor[tiltingMotor] = 60;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(3);
		}
		//tilting motor moves a little bit up when button two in controller two is pressed
		if(joy2Btn(2))
		{
			motor[tiltingMotor] = -60;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(3);
		}
		//the counter for the conveyor and feeding motors run when button four in controller two is pressed
		if(joy2Btn(4))
		{
			StartTask(rollerRun);
			wait10Msec(500);
		}
		//the robot puts itself in the lifting position when button seven in controller two is pressed
		if(joy2Btn(7))
		{
			motor[liftingMotor] = -100;
			wait10Msec(100);
			motor[liftingMotor] = 0;
			wait10Msec(3);
		}
		//this button brings the carriage down, to completely get the robot to hang
		else if(joy2Btn(5))
		{
			motor[liftingMotor] = 100;
			wait10Msec(150);
			motor[liftingMotor] = 0;
			wait10Msec(3);
		}
		if(joy2Btn(8))
		{
			motor[tiltingMotor] = 75;
			wait10Msec(60);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
		}
		//the robot runs its flag motor to raise the flag, when button eight in controller two is pressed
		if(joy2Btn(6))
		{
			motor[flagMotor] = 100;
			wait10Msec(600);
			motor[flagMotor] = 0;
			wait10Msec(3);
		}
		//the up tophat brings up the tiltometer to its highest position
		if(joystick.joy2_TopHat == 0)
	  {
	  	motor[tiltingMotor] = 75;
			wait10Msec(80);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
	  }
	  //the right tophat brings up the tiltometer to its middle position
	  if(joystick.joy2_TopHat == 2)
	  {
	  	motor[tiltingMotor] = 75;
			wait10Msec(85);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);
	  }
	  //the down tophat brings up the tiltometer to its lowest position
	  if(joystick.joy2_TopHat == 4)
	  {
	  	motor[tiltingMotor] = 75;
			wait10Msec(90);
			motor[tiltingMotor] = 25;
			wait10Msec(7);
			motor[tiltingMotor] = 0;
			wait10Msec(4);
	  }
	  //the left tophat brings the tiltometer to its base position
	  if(joystick.joy2_TopHat == 6)
	  {
	  	motor[tiltingMotor] = -30;
			wait10Msec(57);
			motor[tiltingMotor] = -25;
			wait10Msec(20);
			motor[tiltingMotor] = 0;
			wait10Msec(4);
	  }
	}
}
