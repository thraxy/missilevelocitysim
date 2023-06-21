// make a class for the missile
// add member variables to the class, that needs to be contined to keep track for each missile
// add member function think we might need, examples: launch(), getvelocity(), getposition(), getmass()

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <filesystem>


class Missile {
    
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

    Missile(double velocity, double thrust, double drag, double mass, double gravity, double windSpeed, double windDirection, double altitude);
    // getters
    double getVelocity() const;
    double getPosition() const;
    double getThrust() const;
    double getDrag() const;
    double getMass() const;
    double getWindSpeed() const;
    double getWindDirc() const;
    double getAltitude() const;
    // setters
    void setVelocity(double velocity);
    void setPosition(double position);
    void setThrust(double thrust);
    void setDrag(double drag);
    void setMass(double mass);
    void setWindSpeed(double windSpeed);
    void setWindDirc(double windDirection);
    void setAltitude(double altitude);
    // sim flight
    void simulateFlight();

};



Missile::Missile(double velocity, double thrust, double drag, double mass, double gravity, double windSpeed, double windDirection, double altitude){
    this->velocity = velocity;
    this->thrust = thrust;
    this->drag = drag;
    this->mass = mass;
    this->gravity = gravity;
    this->windSpeed = windSpeed;
    this->windDirection = windDirection;
    this->altitude = altitude;
}

double Missile::getVelocity() const {
    return velocity;
}

double Missile::getPosition() const {
    return position;
}

double Missile::getThrust() const {
    return thrust;
}

double Missile::getDrag() const {
    return drag;
}

double Missile::getMass() const {
    return mass;
}

double Missile::getWindSpeed() const {
    return windSpeed;
}

double Missile::getWindDirc() const {
    return windDirection;
}

double Missile::getAltitude() const {
    return altitude;
}

void Missile::setVelocity(double velocity) {
    this->velocity = velocity;
}

void Missile::setPosition(double position) {
    this->position = position;
}

void Missile::setThrust(double thrust) {
    this->thrust = thrust;
}

void Missile::setDrag(double drag) {
    this->drag = drag;
}

void Missile::setMass(double mass) {
    this->mass = mass;
}

void Missile::setWindSpeed(double windSpeed) {
    this->windSpeed = windSpeed;
}

void Missile::setWindDirc(double windDirection) {
    this->windDirection = windDirection;
}

void Missile::setAltitude(double altitude) {
    this->altitude = altitude;
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
    setPosition(0.0);
    setVelocity(getVelocity());
    double windForce = calcWindForce(getWindSpeed(), getWindDirc());

    // time increment based on simulation
    double simDuration = 90.0; // max duration
    double timeStep = 0.1;

    // generate a unique name based on existing files
    std::string baseFileName = "data";
    int fileNum = 1;
    std::string fileName;
    std::string outputDir;

    // loop to check and increment the file number
    while (true) {
        std::ostringstream oss;
        // basename + filenum + .csv
        oss << baseFileName << fileNum << ".csv";
        // save and convert file name to string
        fileName = oss.str();
        // file path converted to a string
        outputDir = "output/" + fileName;
        // checks if file exists
        std::ifstream fileExists(outputDir);
        if (!fileExists){
            break;
        }
        fileNum++;
    }
    
    // open file from path
    std::ofstream file(outputDir);

    // check if file is opened
    if (!file.is_open()) {
        std::cout<<"Failed to open the data file."<<std::endl;
        return;
    }

    // sim loop
    while (getAltitude() > 0 && time <= simDuration) {

        // netforce Newton's second Law : F = ma 
        double netForce = getThrust() - getDrag() - getMass() * gravity + windForce;

        // update velocity and position
        setVelocity(getVelocity() + ((netForce / getMass()) * timeStep) - (windForce / getMass()) * timeStep);
        setPosition(getPosition() + (getVelocity() * timeStep) - (getWindSpeed() * timeStep));

        // update altitude based on the position
        setAltitude(getAltitude() - std::abs(getPosition()));

        // print time and missile information
        std::cout << "Time: " << time << "s | Altitude: " << getAltitude() << "m | Velocity: " << getVelocity() << "m/s" << std::endl;

        // print time and missile information to outputfile
        file << time << "," << getAltitude() << "," << getVelocity() << std::endl;

        // increment time
        time += timeStep;
    }

    // close output file
    file.close();

    // flight simulation is complete
    std::cout <<"Flight Simulation complete." << std::endl;
}

