#pragma config(Sensor, S2,     lightSensor,    sensorLightInactive)
#pragma config(Sensor, S3,     ultrasonicSensor, sensorSONAR)
#pragma config(Sensor, S4,     touchSensor,    sensorTouch)
#pragma config(Motor,  motorA,          conveyerMotor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rollerMotor,   tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int count = 0;
void rollerSuck()
{
	motor[rollerMotor] = -100;
}
void rollerSpit()
{
	motor[rollerMotor] = -100;
}
void rollerStop()
{
	motor[rollerMotor] = 0;
}
task blockCountTrap()
{
	bool sensorReleased = true;
	while(true)
	{
		if(sensorReleased)
		{
			if(SensorValue(touchSensor) == 0)
			{
				count ++;
				sensorReleased = false;
			}
		}
		else
		{
			if(SensorValue(touchSensor) == 1)
			{
				sensorReleased = true;
			}
		}
	}
}
task blockCountTrap222()
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
task moveConveyer()
{
	motor[conveyerMotor] = -100;
	wait10Msec(200000);
}
task blockCountTime()
{
	while(true)
	{
		if (SensorValue(touchSensor) == 1)
		{
			wait10Msec(10);
			count++;
		}
	}
}
task main
{
	StartTask(blockCountTrap222);
	StartTask(moveConveyer);
	while(true)
	{
		if (count < 4)
		{
			rollerSuck();
		}
		if (count == 4)
		{
			rollerStop();
		}
	}
}
