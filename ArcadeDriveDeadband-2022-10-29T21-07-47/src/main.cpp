/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\porkc                                            */
/*    Created:      Sat Oct 29 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (1) {
   int deadband = 10;
   int DrivetrainPosition = Controller1.Axis3.position();
   
   if (abs (DrivetrainPosition) < deadband) {
   Drivetrain.setDriveVelocity(0,percent);

   } else { 
     
   Drivetrain.setDriveVelocity(DrivetrainPosition, percent);
   
   } 
    int DrivetrainPosition2 = Controller1.Axis1. position();

    if (abs (DrivetrainPosition2) < deadband) {
    Drivetrain.setDriveVelocity(0, percent);

    } else {

    Drivetrain.setDriveVelocity(DrivetrainPosition2, percent);
    }
   }
  }
