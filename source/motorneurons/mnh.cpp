/// --------------- sput -------------------
/*
 *   project : motorneuron_test
 *   file : mnh.cpp
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
// mnh motor function. this is what is called to control the movement of the head motor.


#ifndef mnh_dot_cpp
#define mnh_dot_cpp

// ------------ includes ----------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"





// prototypes:
void motorneuronhead(unsigned int movement);

// state variable for the function:
unsigned mnhstate = 0; // pi3


// function defition
void motorneuronhead(unsigned int movement) {
    if (movement == hold) {
        if (mnhstate == 0) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhstate = 2;
        }
    }
    else if (movement == forwards) {
        if (mnhstate == 0 || mnhstate == 1) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhstate = 2;
        }
        else if (mnhstate == 2) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhstate = 3;
        }
        else if (mnhstate == 3) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhstate = 4;
        }
        else if (mnhstate == 4) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhstate = 1;
        }
    }
    if (movement == backwards) {
        if (mnhstate == 0 || mnhstate == 1) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhstate = 2;
        }
        else if (mnhstate == 2) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhstate = 3;
        }
        else if (mnhstate == 3) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhstate = 4;
        }
        else if (mnhstate == 4) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhstate = 1;
        }
    }
    else if(movement == relax) {
        digitalWrite(mnh1a, LOW);
        digitalWrite(mnh1b, LOW);
        digitalWrite(mnh2a, LOW);
        digitalWrite(mnh2b, LOW);
        mnhstate = 0;
    }
}








// prototype:
void motorneuronhead_slow(unsigned int movement);

// state for function:
unsigned int mnhslowstate = 0; 

// function definition:
void motorneuronhead_slow(unsigned int movement) {
    if (movement == hold) {
        if (mnhslowstate == 0) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 2;
        }
    }
    else if (movement == forwards) {
        if (mnhslowstate == 0 || mnhslowstate == 1) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 2;
        }
        else if (mnhslowstate == 2) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 3;
        }
        else if (mnhslowstate == 3) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 4;
        }
        else if (mnhslowstate == 4) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 5;
        }
        else if (mnhslowstate == 5) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhslowstate = 6;
        }
        else if (mnhslowstate == 6) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhslowstate = 7;
        }
        else if (mnhslowstate == 7) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhslowstate = 8;
        }
        else if (mnhslowstate == 8) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 1;
        }
    }
    if (movement == backwards) {
        if (mnhslowstate == 0 || mnhslowstate == 1) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 2;
        }
        else if (mnhslowstate == 2) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhslowstate = 3;
        }
        else if (mnhslowstate == 3) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhslowstate = 4;
        }
        else if (mnhslowstate == 4) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, HIGH);
            mnhslowstate = 5;
        }
        else if (mnhslowstate == 5) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, LOW);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 6;
        }
        else if (mnhslowstate == 6) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, HIGH);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 7;
        }
        else if (mnhslowstate == 7) {
            digitalWrite(mnh1a, LOW);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 8;
        }
        else if (mnhslowstate == 8) {
            digitalWrite(mnh1a, HIGH);
            digitalWrite(mnh1b, LOW);
            digitalWrite(mnh2a, HIGH);
            digitalWrite(mnh2b, LOW);
            mnhslowstate = 1;
        }
    }
    else if(movement == relax) {
        digitalWrite(mnh1a, LOW);
        digitalWrite(mnh1b, LOW);
        digitalWrite(mnh2a, LOW);
        digitalWrite(mnh2b, LOW);
        mnhslowstate = 0;
    }
}




#endif 
