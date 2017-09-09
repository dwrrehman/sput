wakeup: source/main.cpp
	gcc -std=c++11 -lstdc++ -lpthread -o wakeup -O3 -lwiringPi -lraspicam -I/home/pi/sput/ source/main.cpp

 