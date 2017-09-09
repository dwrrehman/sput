/// ----------- sput -------------
/*
 *   project : motorneuron_test
 *   file : main.cpp
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
// main program for the code for sput. this main tests the functionality of the motor neuron functions. 








/*

   q   w                     wled_off()  wled_on()

   a   s                     gled_off()  gled_on()

   e                         bled_on()

   z                         rled_on()

    o                         relaxes_everything()

      r   t   u   i                 leftforwards_slow() leftforwards()     rightforwards() rightforwards_slow()
    d   f       j   k 		  leftrelax()      lefthold()                         righthold()            rightrelax()
      c   v   n   m                leftbackwards_slow()  leftbackwards()    rightbackwards()  rightbackwards_slow()


      y               headforwards()
    g   h    headrelax()         headhold()
      b 	 	     headbackwards()

*/








// ------------------- includes --------------------

// ------ system includes -------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <wiringPi.h>
#include <thread>

// ------- my includes -------
#include "source/spinalcord/s.cpp"



int stop = 0;
int givendelay = 300; // milliseconds.

// used for spinalcord:

unsigned int bitarray[] = { 

	0,0,0,0, // control bits
	0,0,0, // mnh
	0,0,0, // mnl
	0,0,0, // mnr
	0,0,0,0 // wled, gled, bled, rled
};





void s_loop();
void s_loop() { 
	while (!stop) {
		spinalcord(bitarray);
		delay(givendelay);
	}
}




int main(void){
	
	std::cout << "sput.\n" << std::endl;

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

    // get delay:
    std::cout << "give the delay: ";
    std::cin >> givendelay;
    std::cout << "thank you.\n";

	std::thread spinalcordthread  = std::thread (s_loop);

	char current;
	do {

		current = getchar();

		if (current == 'o') {
			bitarray[4] = 0;
			bitarray[5] = 0;
			bitarray[6] = 0;

			bitarray[7] = 0;
			bitarray[8] = 0;
			bitarray[9] = 0;

			bitarray[10] = 0;
			bitarray[11] = 0;
			bitarray[12] = 0;

			bitarray[13] = 0;
            bitarray[14] = 0;
		}
		// ---------- hold ------------
		else if (current == 'f') {
			bitarray[8] = 1;
			bitarray[9] = 1;
		}

		else if (current == 'j') {
			bitarray[11] = 1;
			bitarray[12] = 1;
		}
		else if (current == 'h') {
			bitarray[5] = 1;
			bitarray[6] = 1;
		}
		// ---------- forwards ----------
		else if (current == 't') {
			bitarray[7] = 0;
			bitarray[8] = 0; //
			bitarray[9] = 1; //
		}

		else if (current == 'u') {
			bitarray[10] = 0;
			bitarray[11] = 1; //
			bitarray[12] = 0; //
		}
		// ----------- backwards ---------
		else if (current == 'v') {
			bitarray[7] = 0;
			bitarray[8] = 1; //
			bitarray[9] = 0; //
		}

		else if (current == 'n') {
			bitarray[10] = 0;
			bitarray[11] = 0; //
			bitarray[12] = 1; //
		}
		// ---------- slow forwards -----------
		else if (current == 'r') {
			bitarray[7] = 1;
			bitarray[8] = 0; //
			bitarray[9] = 1; //
		}

		else if (current == 'i') {
			bitarray[10] = 1;
			bitarray[11] = 1; //
			bitarray[12] = 0; //
		}

		else if (current == 'y') {
			bitarray[4] = 1; //
			bitarray[5] = 0;
			bitarray[6] = 1;
		}
		// ----------- slow backwards ---------
		else if (current == 'c') {
			bitarray[7] = 1;
			bitarray[8] = 1; //
			bitarray[9] = 0; //
		}

		else if (current == 'm') {
			bitarray[10] = 1;
			bitarray[11] = 0; //
			bitarray[12] = 1; //
		}

		else if (current == 'b') {
			bitarray[4] = 1; //
			bitarray[5] = 1;
			bitarray[6] = 0;
		}
		// ----------- relax ---------------
		else if (current == 'd') {
			bitarray[8] = 0; //
			bitarray[9] = 0; //
		}

		else if (current == 'k') {
			bitarray[11] = 0; //
			bitarray[12] = 0; //
		}

		else if (current == 'g') {
			bitarray[5] = 0;
			bitarray[6] = 0;
		}
		// -------------- wled -----------
		else if (current == 'w') {
			bitarray[13] = 1;
		}
		else if (current == 'q') {
			bitarray[13] = 0;
		}
        else if (current == 's') {
            bitarray[14] = 1;
            bitarray[15] = 0;
            bitarray[16] = 0;
        }
        else if (current == 'a') {
            bitarray[14] = 0;
            bitarray[15] = 0;
            bitarray[16] = 0;
        }
        else if (current == 'e') {
            bitarray[14] = 0;
            bitarray[15] = 1;
            bitarray[16] = 0;
        }
        else if (current == 'z') {
            bitarray[14] = 0;
            bitarray[15] = 0;
            bitarray[16] = 1;
        }
        else if (current == '\n' || current == 'x'){
            // pass.
        }
		else {
			printf("no command associated.\n");
		}

		// ------------------------------

	} while (current != 'x');

	printf("exited.\n");

	stop = 1;
	spinalcordthread.join();

	return 0;
}
