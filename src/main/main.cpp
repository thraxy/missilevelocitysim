#include "../includes/missile.hpp"
#include <stdio.h>
#include <iostream>

int main (void)
{
    printf("hello world\n");
    // c++ way of printing
    std::cout<<"ansda"<<std::endl;

    // input for missile info
    double intVelocity, thrust, drag, mass, gravity, windSpeed, windDirection, altitude;
    
    gravity = 9.81;

    // create a test missile
    Missile testMissile(100.0, 2000.0, 150.0, 500.0, 9.81, 20.0, 45.0, 2000.0);

    // user input
    std::cout << "Enter initial velocity: ";
    std::cin >> intVelocity;

    std::cout << "Enter thrust: ";
    std::cin >> thrust;

    std::cout << "Enter drag: ";
    std::cin >> drag;

    std::cout << "Enter mass: ";
    std::cin >> mass;

    std::cout << "Enter wind speed: ";
    std::cin >> windSpeed;

    std::cout << "Enter wind direction: ";
    std::cin >> windDirection;

    std::cout << "Enter altitude: ";
    std::cin >> altitude;

    // create user input missile
    Missile userMissile(intVelocity, thrust, drag, mass, gravity, windSpeed, windDirection, altitude);

    // simulate
    testMissile.simulateFlight();
    userMissile.simulateFlight();

    return 0;
}