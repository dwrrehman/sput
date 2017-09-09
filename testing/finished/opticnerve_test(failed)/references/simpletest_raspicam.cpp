// references:
// example program for using raspicam with rbg format. 

/*


compile me with:

    g++ simpletest_raspicam.cpp -o simpletest_raspicam -I/usr/local/include -lraspicam


*/

#include <unistd.h>
#include <ctime>
#include <time.h>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
using namespace std;

int main(int argc, char **argv) {

    raspicam::RaspiCam Camera; 
    Camera.open();
    sleep(2);
    unsigned char* data = new unsigned char[Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)];

    Camera.grab();
    Camera.retrieve(data, raspicam::RASPICAM_FORMAT_RGB);

    
    std::ofstream outFile("raspicam_image.ppm", std::ios::binary);
    outFile<<"P6\n"<<Camera.getWidth() << " " << Camera.getHeight() << " 255\n";
    outFile.write((char*)data, Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));

    delete data;
    return 0;
}
