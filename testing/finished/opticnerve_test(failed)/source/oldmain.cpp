/// ----------- sput -------------
/*
 *   project : opticnerve_test
 *   file : main.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1707123.172242
 *   
 */
/// -------------------------------


// ---------- includes -----------
// system includes:
#include <unistd.h>
#include <stdio.h>

// my includes:
#include "r.cpp"


int main(int argc, char **argv) {
    
	unsigned int* data;

	// init:
	printf("initializing retina...\n");
	retina_set_size(small);
	//retina_visualencoder_set_n_and_w(50, 5);
	retina_initialize();

	// execute:
	printf("executing...\n");
	
	while (true) {


		//printf("DEBUG STATEMENT: 1");

		// get the image from the retina:
		data = retina();

		// print
		for (int i = 0; i < retina_length; i++) {

			printf("%c ", data[i]);
		}
		printf("\n\n");


		// wait to see how long that took.
		printf("done.\n");
		sleep(1);
	}

	// clean:
	retina_clean();

    return 0;
}
