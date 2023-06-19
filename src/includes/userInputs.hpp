#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include <iostream>
#include <string>

// Function to get the user inputs for missile parameters
void getUserInputs(double& param, const std::string& paramName){
    std::cout << "Enter " << paramName << ": ";
    std::cin >> param;
}


#endif 
