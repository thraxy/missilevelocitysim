#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <GL/glut.h>
#include "missile.hpp"

// Updates the missile altitude based on sim data
void updateMissileAlt();

// drawing the visualization
void drawSim();

// update visualization and missile data
void update();

#endif
