#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     ultrasonicSensor, sensorSONAR)
#pragma config(Sensor, S4,     lightSensor,    sensorLightInactive)
#pragma config(Motor,  motorA,          conveyerMotor, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          rollerMotor,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     backRightMotor, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     frontRightMotor, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     backLeftMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     frontLeftMotor, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "movingAndTurning.c"
#include "irContinuousTest.c"

task main()
{
/*
Autonomus code for the right side of the pendulum.
*/

moveForward(6, 80);
wait10Msec(100);
rightOneWheelTurn(45, 80);
wait10Msec(100);
moveForward(5,80);
}
