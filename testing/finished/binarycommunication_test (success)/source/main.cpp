/// ----------- sput -------------
/*
 *   project : opticnerve_test
 *   file : main.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1705313.201933
 *   
 */
/// -------------------------------


// ---------- includes -----------
// system includes:
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// my includes:
#include "source/motorneurons/mnw.cpp"
#include "source/motorneurons/mng.cpp"

#define stop '2'

void setbinarydata(char data) {
	if (data == '1') {
		motorneuronwled(1);
		motorneurongled(0);
	}
	else if (data == '0') {	
		motorneuronwled(0);
		motorneurongled(1);
	}
	else if (data == stop) {
		motorneuronwled(0);
		motorneurongled(0);
	}
}



int main(int argc, char **argv) {

	std::cout << "sput.\n" << std::endl;

	std::cout << "input the delay: ";

	int givendelay = 0;
	std::cin >> givendelay;

	//set up gpio:
    wiringPiSetupGpio();

    pinMode(gledpin, OUTPUT);
    pinMode(wledpin, OUTPUT);

	char data[51] = "";

	// get data continuously, and send each bit to the data function.
	while (data[0] != 'x') {
		strcpy(data, "");
		printf("> ");
		fgets(data, 50, stdin);	

		for (int i=0; data[i] != '\0'; i++) {
			setbinarydata(data[i]);
			delay(givendelay);
			setbinarydata(stop);
			delay(givendelay);
		}
	}
	
	printf("thanks for speaking!\n");
    return 0;
}
