/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Split Arcade                                              */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         1               
// RightMotor           motor         2               
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// FlyWheelMotor        motor         4               
// SpinnerMotor         motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;


  while (true) {
  //Flywheel spin when R2 Pressed
  if (Controller1.ButtonR2.pressing() == true){
  FlyWheelMotor.setVelocity(75, percent);
  FlyWheelMotor.spin(forward);
  } else {
    FlyWheelMotor.stop();
  }
  //if (Controller1.ButtonUp.pressing() == true){
  //SpinnerMotor.setVelocity(15, percent);
  //SpinnerMotor.spin(forward);
  //} else {
    //SpinnerMotor.stop();
  //}
    while (Controller1.ButtonUp.pressing() == true){
      SpinnerMotor.setVelocity(15, percent);
    SpinnerMotor.spin(forward);
    Brain.Screen.print("3");
    Brain.Screen.clearLine(1);
    if (Controller1.ButtonUp.pressing() == false){
      SpinnerMotor.setVelocity(0, percent);
    }
    wait(20, msec);
    }
    while (Controller1.ButtonDown.pressing() == true){
    SpinnerMotor.setVelocity(15, percent);
    SpinnerMotor.spin(reverse);
    wait(20, msec);
    }
  
    // Get the velocity percentage of the left motor. (Axis3 + Axis1)
    int leftMotorSpeed =
        Controller1.Axis3.position() + Controller1.Axis1.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis1)
    int rightMotorSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      LeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      RightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

    // Spin both motors in the forward direction.
    LeftMotor.spin(forward);
    RightMotor.spin(forward);

    wait(25, msec);
  }
}
