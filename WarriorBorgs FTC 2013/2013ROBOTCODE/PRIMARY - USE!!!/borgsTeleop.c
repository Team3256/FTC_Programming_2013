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

//including all the files into this teleop program
#include "JoystickDriver.c"
#include "driveTrain_Functions.c"
#include "sensor_Functions.c"
#include "rollerAndArm_Functions.c"

int ticksPerDegree=5760/360;

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
		motor[feedingMotorUno] = ((-100.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0));
		motor[feedingMotorDos] = ((-100.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0)*(joystick.joy2_y1/127.0));
		motor[conveyorMotor] = ((100.0)*(joystick.joy2_y2/127.0)*(joystick.joy2_y2/127.0)*(joystick.joy2_y2/127.0));
		if(joy1Btn(6))
		{
			motor[frontLeftMotor] = ((-45.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
			motor[backLeftMotor] = ((-45.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
			motor[frontRightMotor] = ((45.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
			motor[backRightMotor] = ((-45.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		}
		else
		{
			motor[frontLeftMotor] = ((-100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
			motor[backLeftMotor] = ((-100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
			motor[frontRightMotor] = ((100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
			motor[backRightMotor] = ((-100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		}
		if(joystick.joy2_TopHat == 0)
		{
				motor[tiltingMotor]=80;
				wait10Msec(30);
		}
		//tilting motor moves a little bit up when button two in controller two is pressed
		else if(joystick.joy2_TopHat == 4)
		{
				motor[tiltingMotor]=-80;
				wait10Msec(30);
		}
		else
		{
			motor[tiltingMotor] = 0;
		}
		//the robot puts itself in the lifting position when button seven in controller one is pressed
		if(joy1Btn(7) && joy1Btn(8))
		{
			motor[liftingMotor] = -100;
		}
		//this button brings the carriage down, to completely get the robot to hang
		else if(joy1Btn(5))
		{
			motor[liftingMotor] = 100;
		}
		else
		{
			motor[liftingMotor] = 0;
		}

		if(joy2Btn(8))
		{
					int nTicks =0;
			nTicks= ticksPerDegree*107.5;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks )
			{
				motor[tiltingMotor]=65;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;
		}
		else
			motor[tiltingMotor] = 0;

		//the robot runs its flag motor to raise the flag, when button eight in controller two is pressed
		if(joy2Btn(5))
			motor[flagMotor] = 100;
		else if(joy2Btn(7))
			motor[flagMotor] = -100;
		else
			motor[flagMotor] = 0;

		//the up tophat brings up the tiltometer to its highest position
		if(joy2Btn(4))
	  {
	  	/*motor[tiltingMotor] = 75;
			wait10Msec(80);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);*/
			int nTicks =0;
			nTicks= ticksPerDegree*120;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks )
			{
				motor[tiltingMotor]=75;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;
	  }
	  //the right tophat brings up the tiltometer to its middle position
	  else if(joy2Btn(3))
	  {
	  	/*motor[tiltingMotor] = 75;
			wait10Msec(85);
			motor[tiltingMotor] = 25;
			wait10Msec(5);
			motor[tiltingMotor] = 0;
			wait10Msec(10);*/
			int nTicks =0;
			nTicks= ticksPerDegree*150;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks )
			{
				motor[tiltingMotor]=75;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;
	  }
	  //the down tophat brings up the tiltometer to its lowest position
	  else if(joy2Btn(2))
	  {
	  	/*motor[tiltingMotor] = 75;
			wait10Msec(90);
			motor[tiltingMotor] = 25;
			wait10Msec(7);
			motor[tiltingMotor] = 0;
			wait10Msec(4);*/
			int nTicks =0;
			nTicks= ticksPerDegree*175;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks )
			{
				motor[tiltingMotor]=75;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;
	  }
	  //the left tophat brings the tiltometer to its base position
	  else if(joy2Btn(1))
	  {
	  	/*motor[tiltingMotor] = -30;
			wait10Msec(57);
			motor[tiltingMotor] = -25;
			wait10Msec(20);
			motor[tiltingMotor] = 0;
			wait10Msec(4);*/
			motor[tiltingMotor] = -100;
			wait10Msec(50);
			/*int nTicks =0;
			nTicks= ticksPerDegree*110;
			nMotorEncoder[tiltingMotor]=0;
			while (abs(nMotorEncoder[tiltingMotor]) < nTicks )
			{
				motor[tiltingMotor]=-75;
			}
			motor[tiltingMotor]=0;
			nMotorEncoder[tiltingMotor]=0;*/
	  }
	  else
	  	motor[tiltingMotor] = 0;
	}
}
