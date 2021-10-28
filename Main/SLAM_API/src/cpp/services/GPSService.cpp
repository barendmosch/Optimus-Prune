// here we call the hardware layer to get data
// Also the service layer is responsible for doing things with said data, normalise it, make it readable etc

#include <iostream>
#include <string>
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Iservices/IGPSService.h"
#include "/home/sfp/Documents/source/repos/SLAM_API/src/cpp/Ihardware/GPS.h"

using namespace std;

GPSService::GPSService() {
    
}

bool GPSService::requestData(){
    // Call the hardware layer to get the raw data
    // Do something with raw data to make it something where we can work with
    int data = gps.readRawData();

    return false;
}