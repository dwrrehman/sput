
/// ----------- sput -------------
/*
 *   project : init_test
 *   file : init.cpp
 *
 *   creator : dwrr
 *   created : 1707296.143642
 *
 *   version : 0.1
 *   touched : 1707296.143642
 *   
 */
/// -------------------------------

// description:
// the init function for sput. this function initializes many aspects of sputs input and outputs.
// the function purposely does not init the htm system. 


#ifndef init_dot_cpp
#define init_dot_cpp


/*
 
 -------------- agenda: ----------------
 
 1. test LED's
 2. test senses 
 2a. test somatosensory
 2b. test vision
 3. test motors
 3a. right motor, forwards and then backwards alittle bit 
 3b. left motor,  forwards and then backwards alittle bit
 3c. right motor, up and then down, (head is begins (wakes up in) the down most position.)
 4. init htm 
 4a. ...?
 
 5. send a dopamine spike to invoke movement?
 
 
 
 
 */




// --------- system includes: -------
#include <iostream>
#include <wiringPi.h>
#include <unistd.h>

// ---------- my includes ----------
#include "source/spinalcord/s.cpp"


using namespace std;


void test_leds(void) {
    cout << "sput:initialize: testing LEDs..." << endl;
    
    
    /*  info on the input to the spinalcord:
     
     cntl mnh mnl mnr w g r b 
     0000 000 000 000 0 0 0 0 
     0123 456 789 012 3 4 5 6
     
     */
    
    
    unsigned int motorcommands[17] = {0};
    spinalcord(motorcommands);
    
    
    { // test white led:
        motorcommands[13] = 1; spinalcord(motorcommands);
        delay(300);
        motorcommands[13] = 0; spinalcord(motorcommands);
        delay(200);
    }
    
    { // test green led:
        motorcommands[14] = 1; spinalcord(motorcommands);
        delay(200);
        motorcommands[14] = 0; spinalcord(motorcommands);
        delay(200);
    }
    
    { // test red led:
        motorcommands[16] = 1; spinalcord(motorcommands);
        delay(200);
        motorcommands[16] = 0; spinalcord(motorcommands);
        delay(200);
    }
    
    { // test blue led:
        motorcommands[15] = 1; spinalcord(motorcommands);
        delay(200);
        motorcommands[15] = 0; spinalcord(motorcommands);
        delay(100);
    }
    
    cout << "sput:initialize: LED test complete." << endl << endl;
}




void flash_wled_on_completion() {
    unsigned int motorcommands[17] = {0};
    spinalcord(motorcommands);
    
    motorcommands[13] = 1;
    spinalcord(motorcommands);
    delay(100);
    motorcommands[13] = 0;
    spinalcord(motorcommands);
    delay(100);
}





void test_motors(
                 int head_numberofsteps, 
                 int left_numberofsteps, 
                 int right_numberofsteps
                 ) {
    
    cout << "sput:initialize: testing motors..." << endl;
    
    /*  info on the input to the spinalcord:
     
     cntl mnh mnl mnr w g b r 
     0000 000 000 000 0 0 0 0 
     0123 456 789 012 3 4 5 6
     
     */
    
    int upright_parameter = 116; // (a magic value found through alot of testing...)
    
    
    
    unsigned int motorcommands[17] = {0};
    
    // relax body:
    spinalcord(motorcommands);
    delay(200);
    
    { // straighten head motor, so it is perfectly vertical:
        motorcommands[4] = 1;
        motorcommands[5] = 1;
        motorcommands[6] = 0;
        for (int i = 0; i < upright_parameter; i++) {
            spinalcord(motorcommands);
            delay(30);
        }
        motorcommands[13] = 0; // white led off
        
        // clean up:
        motorcommands[4] = 0;
        motorcommands[5] = 0;
        motorcommands[6] = 0;
        spinalcord(motorcommands);
        flash_wled_on_completion();
        delay(200);
    }
    
    
    
    
    
    
    
    { // test head motor:
        
        // forwards:
        motorcommands[4] = 0;
        motorcommands[5] = 0;
        motorcommands[6] = 1;
        
        motorcommands[14] = 1; // green led on
        for (int i = 0; i < head_numberofsteps; i++) {
            spinalcord(motorcommands);
            delay(20);
        }
        motorcommands[14] = 0; // green led off
        
        delay(200);
        
        // backwards:
        motorcommands[4] = 1;
        motorcommands[5] = 1;
        motorcommands[6] = 0;
        
        motorcommands[15] = 1; // blue led on
        for (int i = 0; i < head_numberofsteps*2; i++) {
            spinalcord(motorcommands);
            delay(20);
        }
        motorcommands[15] = 0; // blue led off
        
        // clean up:
        motorcommands[4] = 0;
        motorcommands[5] = 0;
        motorcommands[6] = 0;
        spinalcord(motorcommands);
        delay(200);
        flash_wled_on_completion();
    }
    
    
    
    
    { // test left motor:
        
        // forwards:
        motorcommands[7] = 0;
        motorcommands[8] = 0;
        motorcommands[9] = 1;
        
        motorcommands[10] = 0;
        motorcommands[11] = 1;
        motorcommands[12] = 1;
        
        motorcommands[14] = 1; // green led on
        for (int i = 0; i < left_numberofsteps; i++) {
            spinalcord(motorcommands);
            delay(20);
        }
        motorcommands[14] = 0; // green led off
        
        delay(200);
        
        // backwards:
        motorcommands[7] = 1;
        motorcommands[8] = 1;
        motorcommands[9] = 0;
        
        motorcommands[15] = 1; // blue led on 
        for (int i = 0; i < left_numberofsteps*2; i++) {
            spinalcord(motorcommands);
            delay(20);
        }
        motorcommands[15] = 0; // blue led off
        
        // clean up:
        motorcommands[7] = 0;
        motorcommands[8] = 0;
        motorcommands[9] = 0;
        spinalcord(motorcommands);
        delay(200);
        flash_wled_on_completion();
    }
    
    
    
    
    { // test right motor:
        // forwards:
        motorcommands[10] = 0;
        motorcommands[11] = 1;
        motorcommands[12] = 0;
        
        motorcommands[7] = 0;
        motorcommands[8] = 1;
        motorcommands[9] = 1;
        
        motorcommands[14] = 1; // green led on 
        for (int i = 0; i < right_numberofsteps; i++) {
            spinalcord(motorcommands);
            delay(20);
        }
        motorcommands[14] = 0; // green led off
        
        delay(200);
        
        // backwards:
        motorcommands[10] = 1;
        motorcommands[11] = 0;
        motorcommands[12] = 1;
        
        motorcommands[15] = 1; //blue led on
        for (int i = 0; i < right_numberofsteps*2; i++) {
            spinalcord(motorcommands);
            delay(20);
        }
        motorcommands[15] = 0; // blue led off
        
        // clean up:
        motorcommands[10] = 0;
        motorcommands[11] = 0;
        motorcommands[12] = 0;
        spinalcord(motorcommands);
        delay(100);
        flash_wled_on_completion();
    }
    
    motorcommands[0] = 0;
    motorcommands[1] = 0;
    motorcommands[2] = 0;
    motorcommands[3] = 0;
    
    motorcommands[4] = 0;
    motorcommands[5] = 0;
    motorcommands[6] = 0;
    
    motorcommands[7] = 0;
    motorcommands[8] = 0;
    motorcommands[9] = 0;
    
    motorcommands[10] = 0;
    motorcommands[11] = 0;
    motorcommands[12] = 0;
    
    motorcommands[13] = 0;
    motorcommands[14] = 0;
    motorcommands[15] = 0;
    motorcommands[16] = 0;
    
    spinalcord(motorcommands);
    delay(100);
    
    // done.
    cout << "sput:initialize: motor test complete." << endl << endl;
}




void init_gpio(void) {
    //set up gpio:
    wiringPiSetupGpio();
    
    pinMode(mnh1a, OUTPUT);
    pinMode(mnh1b, OUTPUT);
    pinMode(mnh2a, OUTPUT);
    pinMode(mnh2b, OUTPUT);
    
    pinMode(mnl1a, OUTPUT);
    pinMode(mnl1b, OUTPUT);
    pinMode(mnl2a, OUTPUT);
    pinMode(mnl2b, OUTPUT);
    
    pinMode(mnr1a, OUTPUT);
    pinMode(mnr1b, OUTPUT);
    pinMode(mnr2a, OUTPUT);
    pinMode(mnr2b, OUTPUT);
    
    pinMode(wledpin, OUTPUT);
    pinMode(gledpin, OUTPUT);
    pinMode(rledpin, OUTPUT);
    pinMode(bledpin, OUTPUT);
}




void initialize(void) {
    
    cout << endl << endl << "sput" << endl << endl;
    cout << "sput:initialize: initializing..." << endl;
    
    init_gpio();
    
    test_leds();
    
    //test_touch();
    
    //test_vision();
    
    test_motors(50, 20, 20); // (format:   distance for head,   distance for left,   distance for right)
    
    cout << "sput:initialize: initialization complete." << endl << endl;
    
}






#endif
