#include <iostream>
#include <string>
#include <Eigen/Core>
#include "slam.h"
#include "../Icontrollers/IGPSController.h"
#include "../Icontrollers/IGyroController.h"
#include "../Icontrollers/ILidarController.h"

using namespace SLAM;

Slam::Slam(){
    start();
}

Slam::Slam(controllers::GPSController gps_cont, controllers::GyroController gyro_cont, controllers::LidarController lidar_cont){
    this->gps_cont = gps_cont;
    this->gyro_cont = gyro_cont;
    this->lidar_cont = lidar_cont;

    start();
}

bool Slam::start(){
    setLidarData(lidar_cont.requestData());

    bool gps_result = doSomethingWithGPSData();
    bool lidar_result = doSomethingWithLidarData();
    bool gyro_result = doSomethingWithGyroData();
    return false;
}

/* TODO:
     - make classes for the 3 components, each with their needed methods and calculations:
     - GPS   
     - Gyro
     - Lidar
     - Maybe one for pure math functions
     - Visualisation?
     - Map Making
     - Also a separate instance of the pathfinding, since our structure tells us that pathfinding starts requests the SLAM map
*/     
bool Slam::doSomethingWithGPSData(){
    int data = getGPSData();
    std::cout << data << std::endl;
    return false;
}

bool Slam::doSomethingWithGyroData(){
    int data = getGyroData();
    std::cout << data << std::endl;
    return false;
}

bool Slam::doSomethingWithLidarData(){
    Eigen::Matrix3Xf data = getLidarData();
    std::cout << data << std::endl;
    return false;
}

// Setting the data should not be necessary
void Slam::setGPSData(int gps_data){
    this->gps_data = gps_data;
}

int Slam::getGPSData(){
    return this->gps_data;
}

// Setting the data should not be necessary
void Slam::setGyroData(int gyro_data){
    this->gyro_data = gyro_data;
}

int Slam::getGyroData(){
    return this->gps_data;
}

// Setting the data should not be necessary
void Slam::setLidarData(Eigen::Matrix3Xf lidar_data){
    this->lidar_data = lidar_data;
}

Eigen::Matrix3Xf Slam::getLidarData(){
    return this->lidar_data;
}