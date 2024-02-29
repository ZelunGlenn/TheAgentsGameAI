#ifndef MISSIONPACKAGE_H
#define MISSIONPACKAGE_H
#include "mission.h"

 
class MissionPackage{
    public:
        MissionPackage();
        Mission** get_mission_package();
        ~MissionPackage();
    private:
        Mission** pacakge;
};
#endif