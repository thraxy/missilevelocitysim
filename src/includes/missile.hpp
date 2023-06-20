// make a class for the missile
// add member variables to the class, that needs to be contined to keep track for each missile
// add member function think we might need, examples: launch(), getvelocity(), getposition(), getmass()

#include <iostream>
#include <cmath>


class Missile {
    
    double intVelocity; // initial velocity of the missile
    double velocity; // velocity
    double position; // position of the missile
    double thrust; // thrust from the missile
    double drag; // the drag that the missile experiences
    double mass; // the weight of the missile
    double gravity; // gravity acting on the missile
    double windSpeed; // speed of the wind that is acting on the missile
    double windDirection; // direction of the wind
    double altitude; // altitude of the missile


public:

    Missile(double intVelocity, double thrust, double drag, double mass, double gravity, double windSpeed, double windDirection, double altitude);

    double getVelocity() const {
        return velocity;
    }

    double getPosition() const {
        return position;
    }

    double getThrust() const {
        return thrust;
    }

    double getDrag() const {
        return drag;
    }

    double getMass() const {
        return mass;
    }

    double getWindSpeed() const {
        return windSpeed;
    }

    double getWindDirc() const {
        return windDirection;
    }

    double getAltitude() const {
        return altitude;
    }

    void setVelocity(double velocity) {
        this->velocity = velocity;
    }

    void setPosition(double position) {
        this->position = position;
    }

    void setThrust(double thrust) {
        this->thrust = thrust;
    }

    void setDrag(double drag) {
        this->drag = drag;
    }

    void setMass(double mass) {
        this->mass = mass;
    }

    void setWindSpeed(double windSpeed) {
        this->windSpeed = windSpeed;
    }

    void setWindDirection(double windDirection) {
        this->windDirection = windDirection;
    }

    void setAltitude(double altitude) {
        this->altitude = altitude;
    }

    void simulateFlight();

};



Missile::Missile(double intVelocity, double thrust, double drag, double mass, double gravity, double windSpeed, double windDirection, double altitude){

    getVelocity();
    getThrust();
    getDrag();

    this->gravity = gravity;

    getMass();
    getWindSpeed();
    getWindDirc();
    getAltitude();
    
}

// calculating windforce based the windspeed and direction inputs
double calcWindForce(double windSpeed, double windDirection) {
    // converting the wind direction to radians
    // M_PI = 3.14....
    // conversion is required because the functions expect the angles to be in radians and not degrees
    double windDirectionRad = windDirection * (M_PI/ 180.0);

    // calculating wind force
    double windForce = windSpeed * cos(windDirectionRad);

    return windForce;
}

void Missile::simulateFlight() {

    // simulate logic
    double time = 0.0;
    position = 0.0;
    velocity = intVelocity;
    double windForce = calcWindForce(windSpeed, windDirection);


    // sim loop
    while (altitude > 0) {

        // netforce Newton's second Law : F = ma 
        double netForce = thrust - drag - mass * gravity + windForce;

        // update velocity and position
        velocity += ((netForce / mass) * time) - (windForce / mass) * time;
        position += (velocity * time) - (windSpeed * time);

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

