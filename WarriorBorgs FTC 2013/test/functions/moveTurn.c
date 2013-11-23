float pie = 3.14159;
float track = 5.9;
float halfTrack=track/2;
float wheelDiam=2.356;
float wheelRadius = wheelDiam/2;
float wheelCircumference=wheelDiam*pie;
float ticksPerInches = 1440/wheelCircumference;
float halfRobotCircumference = track*pie;
float robotCircumference = track*2*pie;
float inchesPerDegreeOneWheel = wheelCircumference/robotCircumference;
float inchesPerDegreeTwoWheel = wheelCircumference/halfRobotCircumference;

void straight(float inchesMoved, int motorSpeed){
	float nticks = 0;
	nticks =  abs(inchesMoved *ticksPerInches);
	nMotorEncoder[motorC] = 0;
	while(abs(nMotorEncoder[motorC]) < nticks){
		motor[motorC] = motorSpeed;
		motor[motorB] = motorSpeed;

	}
}
void leftTwoWheelTurn(int degreesMoved){
	float nticks =0;
	nticks = abs((degreesMoved*halfTrack)/wheelRadius);

	nMotorEncoder[motorC]=0;
	while(nMotorEncoder[motorC] < nticks){
		motor[motorC] = 40;
		motor[motorB] = -40;

	}
	nticks =0;
}
void  rightTwoWheelTurn(int degreesMoved){
	float nticks = 0;
	nticks = abs((degreesMoved*halfTrack)/wheelRadius);
	nMotorEncoder[motorB]=0;
	while(nMotorEncoder[motorB] < nticks){
		motor[motorC] = -40;
		motor[motorB] = 40;
	}

}
task main()
{



}
