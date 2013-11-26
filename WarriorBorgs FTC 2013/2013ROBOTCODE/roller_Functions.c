#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          feedingMotorUno, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     backRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     tiltingMotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     conveyorMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     liftingMotor,  tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int count = 0;
task conveyorForward() //conveyor feeds
{
	motor[conveyorMotor] = 80;
}
task conveyorBackward() //conveyor spits
{
	motor[conveyorMotor] = -80;
}
task conveyorStop() //conveyor stops
{
	motor[conveyorMotor] = 0;
}
task rollerSuck() //roller motors suck in blocks
{
	motor[feedingMotorUno] = 80;
	motor[feedingMotorDos] = 80;
}
task rollerSpit() //roller motors spit out blocks
{
	motor[feedingMotorUno] = -80;
	motor[feedingMotorDos] = -80;
}
task rollerStop() //roller motors stop running
{
	motor[feedingMotorUno] = 0;
	motor[feedingMotorDos] = 0;
}

// this task runs the motors to create a counter trap
task blockCountTrap100()
{
	bool sensorReleased = true;
	while(true)
	{
		if(sensorReleased)
		{
			if(SensorValue(lightSensor) < 50)
			{
				count ++;
				sensorReleased = false;
			}
		}
		else
		{
			if(SensorValue(lightSensor) >= 50)
			{
				sensorReleased = true;
			}
		}
	}
}

//task that runs the motors, and counts the number of blocks that passes by the light sensor
task rollerRun()
{
	StartTask(blockCountTrap100);
	while(true)
	{
		if (count < 5)
		{
			StartTask(rollerSuck);
			StartTask(conveyorBackward);
		}
		if (count == 4)
		{
			StartTask(rollerStop);
			StartTask(conveyorStop);
		}
	}
}

/*
task main()
{
}
*/
