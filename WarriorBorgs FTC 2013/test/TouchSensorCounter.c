#pragma config(Sensor, S2,     touchSensor,    sensorTouch)
#pragma config(Sensor, S3,     ultrasonicSensor, sensorSONAR)
#pragma config(Motor,  motorB,          rightRoller,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftRoller,   tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int count = 0;
void rollerSuck()
{
	motor[leftRoller] = 85;
	motor[rightRoller] = 85;
}
void rollerSpit()
{
	motor[leftRoller] = -85;
	motor[rightRoller] = -85;
}
void rollerStop()
{
	motor[leftRoller] = 0;
	motor[rightRoller] = 0;
}
task main()
{
	while (1==1)
	{
		if (SensorValue(touchSensor) == 0)
		{
			rollerSuck();
		}
		else
		{
			rollerStop();
			wait10Msec(10);
			count++;
			rollerSuck();
		}
		if (count == 4)
		{
			rollerStop();
			break;
		}
	}
}
