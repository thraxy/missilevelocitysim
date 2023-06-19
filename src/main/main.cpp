#include "../includes/userInputs.hpp"
#include "../includes/missile.hpp"

#include <stdio.h>
#include <iostream>

int main (void)
{
    // printf("hello world\n");
    // c++ way of printing
    // std::cout<<"ansda"<<std::endl;

    // input for missile info
    double intVelocity, thrust, drag, mass, gravity, windSpeed, windDirection, altitude;
    
    gravity = 9.81;

    // create a test missile
    Missile testMissile(100.0, 2000.0, 150.0, 500.0, 9.81, 20.0, 45.0, 2000.0);

    // user input
   getUserInputs(intVelocity, "Intial Velocity");
   getUserInputs(thrust, "Thrust");
   getUserInputs(drag, "Drag");
   getUserInputs(mass, "Mass");
   getUserInputs(windSpeed, "Wind Speed");
   getUserInputs(windDirection, "Wind Direction");
   getUserInputs(altitude, "Altitude");

    // create user input missile
    Missile userMissile(intVelocity, thrust, drag, mass, gravity, windSpeed, windDirection, altitude);

    // simulate
    testMissile.simulateFlight();
    userMissile.simulateFlight();

    return 0;
}