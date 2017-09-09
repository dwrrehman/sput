/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : mnwl.cpp
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
// LED motorneuron function. this is what is called to control the state of the white LED.

#ifndef mnwl_dot_cpp
#define mnwl_dot_cpp

// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"


// prototype:
void motorneuronwled(unsigned int movement);


void motorneuronwled(unsigned int movement){
    if (movement == on) {
        digitalWrite(wledpin, HIGH);
    }
    else if (movement == off) {
        digitalWrite(wledpin, LOW);
    }
}


#endif
