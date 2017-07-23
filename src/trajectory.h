#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include "vehicle.h"

class Trajectory
{
public:
  Trajectory(const Vehicle& future)
    : future(future)
  {
  }

  Vehicle future;
};

#endif
