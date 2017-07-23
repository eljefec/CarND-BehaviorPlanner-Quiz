#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <functional>
#include <random>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <iterator>

#include "cost_function.h"

using namespace std;

class Trajectory;

class Vehicle {
public:
  struct collider{
    bool collision ; // is there a collision?
    int  time; // time collision happens
  };
  int L = 1;
  int preferred_buffer = 6; // impacts "keep lane" behavior.
  int lane;
  int s;
  int v;
  int a;
  int target_speed;
  int lanes_available;
  int max_acceleration;
  int goal_lane;
  int goal_s;
  string state;
  std::vector<CostFunction> cost_functions;
  /**
  * Constructor
  */
  Vehicle(int lane, int s, int v, int a);
  Vehicle(const Vehicle& other)
    : lane(other.lane),
      s(other.s),
      v(other.v),
      a(other.a),
      target_speed(other.target_speed),
      lanes_available(other.lanes_available),
      max_acceleration(other.max_acceleration),
      goal_lane(other.goal_lane),
      goal_s(other.goal_s),
      state(other.state)
  {
  }
  /**
  * Destructor
  */
  virtual ~Vehicle();
  void update_state(map<int, vector <vector<int> > > predictions);
  Trajectory generate_trajectory(const string& state, const map<int, vector <vector<int> > >& predictions);
  void configure(vector<int> road_data);
  string display();
  void increment(int dt);
  vector<int> state_at(int t);
  bool collides_with(Vehicle other, int at_time);
  collider will_collide_with(Vehicle other, int timesteps);
  void realize_state(map<int, vector < vector<int> > > predictions);
  void realize_constant_speed();
  int _max_accel_for_lane(map<int,vector<vector<int> > > predictions, int lane, int s);
  void realize_keep_lane(map<int, vector< vector<int> > > predictions);
  void realize_lane_change(map<int,vector< vector<int> > > predictions, string direction);
  void realize_prep_lane_change(map<int,vector< vector<int> > > predictions, string direction);
  vector<vector<int> > generate_predictions(int horizon);
private:
  void setup_cost_functions();
};

#endif
