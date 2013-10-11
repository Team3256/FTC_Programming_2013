#pragma+ config(Sensor, S4,     touchSensor,    sensorTouch)
#pragma config(Sensor, S3,     ultrasonicSensor, sensorSONAR)
#pragma config(Motor,  motorB,          rightRoller,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftRoller,   tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int count = -1;
void rollerSuck()
{
	motor[leftRoller] = 90;
	motor[rightRoller] = 90;
}
void rollerSpit()
{
	motor[leftRoller] = -90;
	motor[rightRoller] = -0;
}
void rollerStop()
{
	motor[leftRoller] = 0;
	motor[rightRoller] = 0;
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
	StartTask(blockCountTrap);
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
