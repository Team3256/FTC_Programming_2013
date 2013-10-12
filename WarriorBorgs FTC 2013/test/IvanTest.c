	#pragma config(Sensor, S1,     lightSensor,    sensorLightActive)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touchSensor,    sensorTouch)
#pragma config(Motor,  motorA,          arm,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightWheel,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftWheel,     tmotorNXT, PIDControl, encoder)

task main()
{
motor[motorB]	= 100;
motor[motorC] = 100;
wait10Msec(5000);

}
