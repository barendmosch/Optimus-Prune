// This is just the interface of the corresponding controller class
#include "../Iservices/IGPSService.h"

#ifndef _gpscontroller_h
#define _gpscontroller_h

class GPSController {
    private:
        GPSService gps_service;
    public:
        GPSController();
        int requestData();
};

#endif