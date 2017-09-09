// server side for porting the images received by the camera on
// sput. it first sends the size of the images, and then sends the 
// the images over sockets.

// ------------------ includes --------------------

// system includes:
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// my includes:
#include "r.cpp"


// -------------------- main -----------------
int main(void) {

    std::cout << "this is a server program which reads from the retina and transmits it to dwrr.\n";
    
    // port:
    int portno = 6001;    
    
    // used for giving the length of the image container:
    unsigned char length_buffer[4];
    unsigned long length = 0;
    unsigned char response[1];
    
    // socket setup:
    
    int thesocket;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;     
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    // accept one connection:
    thesocket = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    printf("socket: %d\n", socket);
    
    if (thesocket < 0) {
        printf("connection failed.\n");
        exit(1);
    }
    else {
        printf("connected.\n");
    }
    
    
    // --------- do some length stuff ---------- 
    
    // get length from retina, and set up retina:
    printf("initializing retina...\n");
    retina_set_size(small);
    retina_initialize();

    length = (unsigned long)retina_length;
    
    // set up image container:
    unsigned char* imagedata = (unsigned char*) malloc(length);
    
    // give length to dwrr:
    length_buffer[0] = (length >> 24) & 0xFF; // coverting a long to a byte[4]
    length_buffer[1] = (length >> 16) & 0xFF;
    length_buffer[2] = (length >> 8) & 0xFF;
    length_buffer[3] = length & 0xFF;
    write(thesocket, length_buffer, 4);
    
    read(thesocket, response, 1);
    if (response[0] != 1) {
        printf("error in sending length.\n");
    }
    
    // -------- start sending image data: --------
    while (true) {
        
        // get image from the retina:

        write(thesocket, retina(), (int)length);
        sleep(3);
        read(thesocket, response, 1);        
    }
    

    printf("finished.\n");
    retina_clean();

    return 0;
    
}
    
    
    

