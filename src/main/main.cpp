#include "../includes/userInputs.hpp"
#include "../includes/missile.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>

int main (void)
{
    // printf("hello world\n");
    // c++ way of printing
    // std::cout<<"ansda"<<std::endl;

    // input for missile info
    double velocity, thrust, drag, mass, gravity, windSpeed, windDirection, altitude;
    
    gravity = 9.81;

    // create a test missile
    //Missile testMissile(100.0, 2000.0, 150.0, 500.0, 9.81, 20.0, 45.0, 2000.0);
    Missile testMissile(10.0, 50000.0, 2500.0, 1000.0, 9.81, 10.0, 45.0, 1000.0);

    // user input
    getUserInputs(velocity, "Intial Velocity");
    getUserInputs(thrust, "Thrust");
    getUserInputs(drag, "Drag");
    getUserInputs(mass, "Mass");
    getUserInputs(windSpeed, "Wind Speed");
    getUserInputs(windDirection, "Wind Direction");
    getUserInputs(altitude, "Altitude");

    // create user input missile
    Missile userMissile(velocity, thrust, drag, mass, gravity, windSpeed, windDirection, altitude);

    // simulate
    //std::cout<<"test"<<std::endl;
    testMissile.simulateFlight();
    //std::cout<<"userinput"<<std::endl;
    userMissile.simulateFlight();

    return 0;
}