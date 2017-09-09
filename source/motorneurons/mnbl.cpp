/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : mnbl.cpp
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
// LED motorneuron function. this is what is called to control the state of the blue LED.

#ifndef mnbl_dot_cpp
#define mnbl_dot_cpp

// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"


// prototype:
void motorneuronbled(unsigned int movement);


void motorneuronbled(unsigned int movement){
    if (movement == on) {
        digitalWrite(bledpin, HIGH);
    }
    else if (movement == off) {
        digitalWrite(bledpin, LOW);
    }
}


#endif
