/// --------------- sput -------------------
/*
 *   project : motorneuron_test
 *   file : mnr.cpp
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
// mnr motor function. this is what is called to control the movement of the right motor.


#ifndef mnr_dot_cpp
#define mnr_dot_cpp

// ------------ includes ----------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"





// prototypes:
void motorneuronright(unsigned int movement);

// state variable for the function:
unsigned mnrstate = 0; // pi3


// function defition
void motorneuronright(unsigned int movement) {
    if (movement == hold) {
        if (mnrstate == 0) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrstate = 2;
        }
    }
    else if (movement == forwards) {
        if (mnrstate == 0 || mnrstate == 1) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrstate = 2;
        }
        else if (mnrstate == 2) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrstate = 3;
        }
        else if (mnrstate == 3) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrstate = 4;
        }
        else if (mnrstate == 4) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrstate = 1;
        }
    }
    if (movement == backwards) {
        if (mnrstate == 0 || mnrstate == 1) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrstate = 2;
        }
        else if (mnrstate == 2) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrstate = 3;
        }
        else if (mnrstate == 3) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrstate = 4;
        }
        else if (mnrstate == 4) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrstate = 1;
        }
    }
    else if(movement == relax) {
        digitalWrite(mnr1a, LOW);
        digitalWrite(mnr1b, LOW);
        digitalWrite(mnr2a, LOW);
        digitalWrite(mnr2b, LOW);
        mnrstate = 0;
    }
}








// prototype:
void motorneuronright_slow(unsigned int movement);

// state for function:
unsigned int mnrslowstate = 0; 

// function definition:
void motorneuronright_slow(unsigned int movement) {
    if (movement == hold) {
        if (mnrslowstate == 0) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 2;
        }
    }
    else if (movement == forwards) {
        if (mnrslowstate == 0 || mnrslowstate == 1) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 2;
        }
        else if (mnrslowstate == 2) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 3;
        }
        else if (mnrslowstate == 3) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 4;
        }
        else if (mnrslowstate == 4) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 5;
        }
        else if (mnrslowstate == 5) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrslowstate = 6;
        }
        else if (mnrslowstate == 6) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrslowstate = 7;
        }
        else if (mnrslowstate == 7) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrslowstate = 8;
        }
        else if (mnrslowstate == 8) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 1;
        }
    }
    if (movement == backwards) {
        if (mnrslowstate == 0 || mnrslowstate == 1) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 2;
        }
        else if (mnrslowstate == 2) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrslowstate = 3;
        }
        else if (mnrslowstate == 3) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrslowstate = 4;
        }
        else if (mnrslowstate == 4) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, HIGH);
            mnrslowstate = 5;
        }
        else if (mnrslowstate == 5) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, LOW);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 6;
        }
        else if (mnrslowstate == 6) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, HIGH);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 7;
        }
        else if (mnrslowstate == 7) {
            digitalWrite(mnr1a, LOW);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 8;
        }
        else if (mnrslowstate == 8) {
            digitalWrite(mnr1a, HIGH);
            digitalWrite(mnr1b, LOW);
            digitalWrite(mnr2a, HIGH);
            digitalWrite(mnr2b, LOW);
            mnrslowstate = 1;
        }
    }
    else if(movement == relax) {
        digitalWrite(mnr1a, LOW);
        digitalWrite(mnr1b, LOW);
        digitalWrite(mnr2a, LOW);
        digitalWrite(mnr2b, LOW);
        mnrslowstate = 0;
    }
}




#endif 
