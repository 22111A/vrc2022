#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"

#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10

//using namespace pros;

void opcontrol() {
  pros::Motor left1 (2);
  pros::Motor right1 (8, true); // This reverses the motor
  pros::Motor right2 (9, true);
  pros::Motor left2 (1);
  pros::Motor shooter (15, false);
  pros::Motor bottom_intake (14, true);
  pros::Motor bottom_intake2 (4,false);
  pros::Motor top_intake (10, true);
  pros::Controller master (CONTROLLER_MASTER);
  pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!2");
  master.clear();
  while (true) {
    left1.move(master.get_analog(ANALOG_LEFT_Y));
    left2.move(master.get_analog(ANALOG_LEFT_Y));
    right1.move(master.get_analog(ANALOG_RIGHT_Y));
    right2.move(master.get_analog(ANALOG_RIGHT_Y));
    if (master.get_digital(DIGITAL_A)){
      bottom_intake.move_velocity(-100000);
      bottom_intake2.move_velocity(-100000);
      top_intake.move_velocity(100000);
      top_intake.move(127);
      bottom_intake.move(127);
      bottom_intake2.move(127);
    }
    if (master.get_digital(DIGITAL_B)){
      bottom_intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      bottom_intake2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      top_intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      bottom_intake.brake();
      bottom_intake2.brake();
      top_intake.brake();
    }
    if (master.get_digital(DIGITAL_X)){
      shooter.move_velocity(100000);
      shooter.move(127);
    }
    if (master.get_digital(DIGITAL_Y)){
      shooter.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      shooter.brake();
    }
    master.print(0, 0, "velocity: %d", int(bottom_intake.get_actual_velocity()));
    // master.print(1, 0, "efficiency: %d", bottom_intake.get_efficiency());
    // master.print(2, 0, "temperature: %d", bottom_intake.get_temperature());
    // master.print(3, 0, "voltage: %d", bottom_intake.get_voltage());
    pros::delay(2);
    
  }
}
