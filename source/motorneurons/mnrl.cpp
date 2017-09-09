/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : mnrl.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1705033.102324
 *   
 */
/// -------------------------------

// description: 
// LED motorneuron function. this is what is called to control the state of the red LED.

#ifndef mnrl_dot_cpp
#define mnrl_dot_cpp

// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"


// prototype:
void motorneuronrled(unsigned int movement);


void motorneuronrled(unsigned int movement){
    if (movement == on) {
        digitalWrite(rledpin, HIGH);
    }
    else if (movement == off) {
        digitalWrite(rledpin, LOW);
    }
}


#endif
