#include "main.h"
#include "pros/misc.h"

#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10

//using namespace pros;

void opcontrol() {
  pros::Motor left1 (10);
  pros::Motor right1 (1, true); // This reverses the motor
  pros::Motor right2 (2, true);
  pros::Motor left2 (4);
  pros::Motor shooter (9);
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
      shooter.move_velocity(100000);
      shooter.move(127);
    }
    if (master.get_digital(DIGITAL_B)){
      shooter.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      shooter.brake();

    }
    
    master.print(0, 0, "velocity: %d", shooter.get_actual_velocity());
    master.print(1, 0, "efficiency: %d", shooter.get_efficiency());
    master.print(2, 0, "temperature: %d", shooter.get_temperature());
    master.print(3, 0, "voltage: %d", shooter.get_voltage());
    pros::delay(2);
    
  }
}
