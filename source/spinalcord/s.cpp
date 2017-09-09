/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : s.cpp
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
// spinal cord funciton for sput. controls the movement of all the motors. takes in a bit array encoding the motor movements.



#ifndef s_dot_cpp
#define s_dot_cpp

// ------------------- includes --------------------

// ------ system includes -------
#include <thread>
#include <stdlib.h>

// ------- my includes -------
#include "source/motorneurons/mnh.cpp"
#include "source/motorneurons/mnl.cpp"
#include "source/motorneurons/mnr.cpp"

#include "source/motorneurons/mnwl.cpp"
#include "source/motorneurons/mngl.cpp"
#include "source/motorneurons/mnrl.cpp"
#include "source/motorneurons/mnbl.cpp"



// prototype:
void spinalcord(unsigned int*);

// threads:
std::thread mnhthread;
std::thread mnlthread;
std::thread mnrthread;
std::thread wledthread;
std::thread gledthread;
std::thread rledthread;
std::thread bledthread;


// function definition:
void spinalcord(unsigned int* movements) {


	// before anything, test for control bits:

	if (movements[0] && 
		movements[1] && 
		movements[2] && 
		movements[3]) {
		system("sudo shutdown now");
	}

	// else if (...) {}          // another robot control function, tbc.


/*
 cntl mnh mnl mnr w g r b 
 0000 000 000 000 0 0 0 0 
 0123 456 789 012 3 4 5 6
*/
    
    
	// extract:
	unsigned int mnhmovement = movements[5] << 1 | movements[6];
	unsigned int mnlmovement = movements[8] << 1 | movements[9];
	unsigned int mnrmovement = movements[11] << 1 | movements[12];
	unsigned int wledmovement = movements[13];
    unsigned int gledmovement = movements[14];
    unsigned int rledmovement = movements[16];
    unsigned int bledmovement = movements[15];
    
	// execute motor movements:

	if (movements[4]) mnhthread = std::thread (motorneuronhead_slow, mnhmovement);
	else mnhthread = std::thread (motorneuronhead, mnhmovement);

	if (movements[7]) mnlthread = std::thread (motorneuronleft_slow, mnlmovement);
	else mnlthread = std::thread (motorneuronleft, mnlmovement);
	
	if (movements[10]) mnrthread = std::thread (motorneuronright_slow, mnrmovement);
	else mnrthread = std::thread (motorneuronright, mnrmovement);

	wledthread = std::thread (motorneuronwled, wledmovement);
    gledthread = std::thread (motorneurongled, gledmovement);
    rledthread = std::thread (motorneuronrled, rledmovement);
    bledthread = std::thread (motorneuronbled, bledmovement);
    
	// join threads:
	mnhthread.join();
    mnlthread.join();
    mnrthread.join();
    wledthread.join();
    gledthread.join();
    rledthread.join();
    bledthread.join();

}// s


#endif

