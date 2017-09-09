/// --------------- sput -------------------
/*
 *   project : motorneuron_test
 *   file : mnl.cpp
 *
 *   creator : dwrr
 *   created : 1706261.203048
 *
 *   version : 0.1
 *   touched : 1706261.203048
 *   
 */
/// ------------------------------------------

// description: 
// mnl motor function. this is what is called to control the movement of the left motor.


#ifndef mnl_dot_cpp
#define mnl_dot_cpp

// ------------ includes ----------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"





// prototypes:
void motorneuronleft(unsigned int movement);

// state variable for the function:
unsigned mnlstate = 0; // pi3


// function defition
void motorneuronleft(unsigned int movement) {
    if (movement == hold) {
        if (mnlstate == 0) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlstate = 2;
        }
    }
    else if (movement == forwards) {
        if (mnlstate == 0 || mnlstate == 1) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlstate = 2;
        }
        else if (mnlstate == 2) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlstate = 3;
        }
        else if (mnlstate == 3) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlstate = 4;
        }
        else if (mnlstate == 4) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlstate = 1;
        }
    }
    if (movement == backwards) {
        if (mnlstate == 0 || mnlstate == 1) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlstate = 2;
        }
        else if (mnlstate == 2) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlstate = 3;
        }
        else if (mnlstate == 3) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlstate = 4;
        }
        else if (mnlstate == 4) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlstate = 1;
        }
    }
    else if(movement == relax) {
        digitalWrite(mnl1a, LOW);
        digitalWrite(mnl1b, LOW);
        digitalWrite(mnl2a, LOW);
        digitalWrite(mnl2b, LOW);
        mnlstate = 0;
    }
}








// prototype:
void motorneuronleft_slow(unsigned int movement);

// state for function:
unsigned int mnlslowstate = 0; 

// function definition:
void motorneuronleft_slow(unsigned int movement) {
    if (movement == hold) {
        if (mnlslowstate == 0) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 2;
        }
    }
    else if (movement == forwards) {
        if (mnlslowstate == 0 || mnlslowstate == 1) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 2;
        }
        else if (mnlslowstate == 2) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 3;
        }
        else if (mnlslowstate == 3) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 4;
        }
        else if (mnlslowstate == 4) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 5;
        }
        else if (mnlslowstate == 5) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlslowstate = 6;
        }
        else if (mnlslowstate == 6) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlslowstate = 7;
        }
        else if (mnlslowstate == 7) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlslowstate = 8;
        }
        else if (mnlslowstate == 8) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 1;
        }
    }
    if (movement == backwards) {
        if (mnlslowstate == 0 || mnlslowstate == 1) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 2;
        }
        else if (mnlslowstate == 2) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlslowstate = 3;
        }
        else if (mnlslowstate == 3) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlslowstate = 4;
        }
        else if (mnlslowstate == 4) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, HIGH);
            mnlslowstate = 5;
        }
        else if (mnlslowstate == 5) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, LOW);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 6;
        }
        else if (mnlslowstate == 6) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, HIGH);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 7;
        }
        else if (mnlslowstate == 7) {
            digitalWrite(mnl1a, LOW);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 8;
        }
        else if (mnlslowstate == 8) {
            digitalWrite(mnl1a, HIGH);
            digitalWrite(mnl1b, LOW);
            digitalWrite(mnl2a, HIGH);
            digitalWrite(mnl2b, LOW);
            mnlslowstate = 1;
        }
    }
    else if(movement == relax) {
        digitalWrite(mnl1a, LOW);
        digitalWrite(mnl1b, LOW);
        digitalWrite(mnl2a, LOW);
        digitalWrite(mnl2b, LOW);
        mnlslowstate = 0;
    }
}




#endif 
