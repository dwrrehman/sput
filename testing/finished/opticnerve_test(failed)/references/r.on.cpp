/// ----------- sput -------------
/*
 *   project : opticnerve_test
 *   file : r.on.cpp
 *
 *   creator : dwrr
 *   created : 1707123.172242
 *
 *   version : 0.1
 *   touched : 1707123.172242
 *   
 */
/// -------------------------------

// description:
// the optic nerve (visual encoder) of the retina of sput. this is a set of functions to convert camera image data into a bit array.


#ifndef r_dot_on_dot_cpp
#define r_dot_on_dot_cpp

// system includes:
#include <unistd.h>
#include <stdio.h>


// ------------------ visual encoder functions and variables: --------------

// ----- constants ------

#define maximum 255.0

// ------------ variables -----------

int retina_size = 1; 					// dummy default value.

// parameters:
unsigned int n = 50;     		  			// default values.
unsigned int w = 5;        		            //

#define encoding_size (retina_size * n)                            //
unsigned int* encoding = new unsigned int[encoding_size];          // init an array of 1's and 0's, whos size corresponds to the number of RGB values in the image (retina size), times the total number of bits per RGB value encoding (n).


// ------------- functions ---------------

// setters:

void visualencoder_setparameters(unsigned int given_n, unsigned int given_w) {
    n = given_n;
    w = given_w;
}

void visualencoder_set_retina_size(unsigned int size) {
    retina_size = size;
}

// encoder function:

unsigned int* visualencoder(unsigned char* image) {
    
    for (int i = 0; i < retina_size; i++) { // for each RGB, in each pixel, in the image, 
        
        // trim step skipped. 
        
        // compute:
        float resolution = maximum / (float)(n - w);
        int firstonebitindex = ((int)((((float)image[i]) + resolution/2) / resolution) + w/2) - (w - 1) / 2; 
        
        // set on bits:
        for (int j = firstonebitindex; j < w + firstonebitindex; j++) {
            
            //  ----- this may be optional....
            if (j < 0 || j >= encoding_size) {    // set fault error catching.
                printf("retina: visual encoding error\n");
                break;
            }
            // -----
            
            encoding[n*i + j] = 1;
        }
    }   
    return encoding;
}

void visualencoder_clean() {
    delete encoding;
}


#endif
