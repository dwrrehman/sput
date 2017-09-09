/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : pins.cpp
 *
 *   creator : dwrr
 *   created : 1706261.203048
 *
 *   version : 0.1
 *   touched : 1706261.203048
 *   
 */
/// -------------------------------

// description: 
// pin constants for all motors on sput.


#ifndef pins_dot_hpp
#define pins_dot_hpp

// pi3 pins.
#define mnh1a 14
#define mnh1b 15
#define mnh2a 18
#define mnh2b 23

#define mnl1a 12
#define mnl1b 16
#define mnl2a 20
#define mnl2b 21

#define mnr1a 24
#define mnr1b 25
#define mnr2a 8
#define mnr2b 7

#define wledpin 4
#define gledpin 17
#define rledpin 27
#define bledpin 22


// for use in motor_neuron functions:

#define relax 0
#define forwards 1
#define backwards 2
#define hold 3

#define on 1
#define off 0

#endif

