// make a class for the missile
// add member variables to the class, that needs to be contined to keep track for each missile
// add member function think we might need, examples: launch(), getvelocity(), getposition(), getmass()

#include <iostream>


class Missile {
    
    double intVelocity; // initial velocity of the missile
    double thrust; // thrust from the missile
    double drag; // the drag that the missile experiences
    double mass; // the weight of the missile
    double gravity; // gravity acting on the missile
    double windSpeed; // speed of the wind that is acting on the missile
    double windDirection; // direction of the wind
    double altitude; // altitude of the missile


public:

    Missile(double intVelocity, double thrust, double drag, double mass, double gravity, double windSpeed, double windDirection, double altitude);

    double getVelocity();

    double getPosition();

    double getThrust();

    double getDrag();

    double getMass();

    double getWindSpeed();

    double getWindDirc();

    double getAltitude();

    void simulateFlight();

};

Missile::Missile(double intVelocity, double thrust, double drag, double mass, double gravity, double windSpeed, double windDirection, double altitude){

    this->intVelocity = intVelocity;
    this->thrust = thrust;
    this->drag = drag;
    this->mass = mass;
    this->gravity = gravity;
    this->windSpeed = windSpeed;
    this->windDirection = windDirection;
    this->altitude = altitude;
}

void Missile::simulateFlight() {

    // simulate logic
    double time = 0.0;
    double position = 0.0;
    double velocity = intVelocity;

    // sim loop
    while (altitude > 0) {

        // netforce 
        double netForce = thrust - drag - mass * gravity;

        // update velocity and position
        velocity += (netForce / mass) * time;
        position += velocity * time;

        // update altitude based on the position
        altitude -= position;

        // print time and missile information
        std::cout << "Time: " << time << "s | Altitude: " << altitude << "m | Velocity: " << velocity << "m/s" << std::endl;

        // increment time
        time += 1.0;
    }

    // flight simulation is complete
    std::cout <<"Flight Simulation complete." << std::endl;
}

