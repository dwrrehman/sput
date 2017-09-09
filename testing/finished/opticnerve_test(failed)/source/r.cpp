/// ----------- sput -------------
/*
 *   project : opticnerve_test
 *   file : r.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1707123.172242
 *   
 */
/// -------------------------------

// description:
// the retina of sput. this is a set of functions used to retreive image data from the camera sensor. 


#ifndef r_dot_cpp
#define r_dot_cpp

// system includes:
#include <unistd.h>
#include <stdio.h>
#include <raspicam/raspicam.h>

// my includes:
#include "r.on.cpp"

/*

example of the retinas use:

    retina_set_size(small);// optional             // 
    //retina_visualencoder_set_n_and_w(50, 5);//opt  //    init
    retina_initialize();                           //

	while(true){
		data = retina();     // bit array.      //     get
	}

	retina_clean();                                 //     end

*/

// ---------- retina functions and variables: --------------

// ---------- constants -------------

#define small 1
#define medium 2
#define large 3

// ---------- vairables ---------

raspicam::RaspiCam Camera; 
unsigned char* retina_data;
int camera_size = small;

// -------------- computed values -------------

#define retina_length (Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB))
#define retina_height (Camera.getHeight())
#define retina_width (Camera.getWidth())

// -------- functions -----------

void retina_set_size(int size) {
	camera_size = size;
}


void retina_initialize() {
	Camera.setFormat(raspicam::RASPICAM_FORMAT_RGB);

	// initialize the size of the camera:
	if (camera_size == small) {
		Camera.setHeight(240);
		Camera.setWidth(320);
	}
	else if (camera_size == medium) {
		Camera.setHeight(480);
		Camera.setWidth(640);
	}
	else if (camera_size == large) {
		Camera.setHeight(960);
		Camera.setWidth(1280);
	}

	Camera.open();
    sleep(3);         // let the camera settle,

	retina_data = new unsigned char[retina_length]; // allocate for image.
}

void retina_clean() {
	delete retina_data;
}


unsigned char* retina() {
    Camera.grab();
    Camera.retrieve(retina_data);
    return retina_data;
}


#endif
