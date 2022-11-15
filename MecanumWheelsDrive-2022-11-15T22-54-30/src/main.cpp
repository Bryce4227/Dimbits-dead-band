/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\porkc                                            */
/*    Created:      Tue Nov 15 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontRight           motor         1               
// frontLeft            motor         2               
// backRight            motor         3               
// backLeft             motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  
  int forward = Controller1.Axis3.position(vex::percent);
  int sideways = Controller1.Axis4.position(vex::percent);
  int turn = Controller1.Axis1.position(vex::percent);

  frontRight.spin(vex::forward, forward - sideways + turn, vex::percent);
  frontLeft.spin(vex::forward,  forward + sideways - turn, vex::percent);
  backRight.spin(vex::forward,  forward + sideways + turn, vex::percent);
  backLeft.spin(vex::forward,   forward - sideways - turn, vex::percent);
  
 
}
