// a program which connects to sput, 
// and streams the camera image data from the pi to this computer, 
// and displays it using opencv.


// ---------------- includes: ---------------

// opencv:
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// c:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// c++:
#include <iostream>
#include <thread>



// ------------------- main ----------------------

int main(void) {

	std::cout << "this is a program to connect to sput, to see what its seeing.\n";

    
    // image container:
	unsigned char* imagedata;
    
    // init for finding the length:
    unsigned char length_buffer[4];
    unsigned char response[1];
    
    // length:
    unsigned long length = 0;
    

	// client socket set up:
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int socket = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname("192.168.1.141");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("dwrr to sput: a connection failure.\n");
        exit(1);
    }
    else {
        printf("connected.\n");
    }

    // ----- get length from server: -------
    
    // read:
    read(socket, length_buffer, 4);
    
    // respond:
    reponse[0] = 1;
    write(socket, response, 1);
    
    // extract:
    length = (length_buffer[0] << 24) | (length_buffer[1] << 16) | (length_buffer[2] << 8) | length_buffer[3];
    printf("%d", (int)length);

    while (true) {

        // get image from sput
        read(socket, imagedata, (int)length);
        write(socket, response, 1);
        
        // display image:
        imshow("Image", imagedata);
        
    }
    
    printf("finished.\n");
    


	return 0;
}
