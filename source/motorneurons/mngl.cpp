/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : mngl.cpp
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
// LED motorneuron function. this is what is called to control the state of the green LED.

#ifndef mngl_dot_cpp
#define mngl_dot_cpp

// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"


// prototype:
void motorneurongled(unsigned int movement);


void motorneurongled(unsigned int movement){
    if (movement == on) {
        digitalWrite(gledpin, HIGH);
    }
    else if (movement == off) {
        digitalWrite(gledpin, LOW);
    }
}


#endif
