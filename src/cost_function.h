#ifndef COSTFUNCTION_H
#define COSTFUNCTION_H

#include <functional>
#include <map>
#include <vector>

#include "trajectory.h"

using namespace std;

typedef std::function<double(const Trajectory& t,
                             const std::map<int, vector<vector<int>>>& predictions)> CostFunctionType;

class CostFunction
{
public:
  CostFunction(double weight, const CostFunctionType& func)
    : weight(weight),
      func(func)
  {
  }
  double calculate_cost(const Trajectory& t,
                        const std::map<int, vector<vector<int>>>& predictions) const
  {
    return weight * func(t, predictions);
  }
private:
  double weight;
  CostFunctionType func;
};

class CostFunctions
{
public:
  CostFunctions()
  {
    setup();
  }

  double calculate_cost(const Trajectory& t,
                        const std::map<int, vector<vector<int>>>& predictions) const
  {
    double cost_for_state = 0;
    for (const auto& cost_function : cost_functions)
    {
      cost_for_state += cost_function.calculate_cost(t, predictions);
    }
    return cost_for_state;
  }

private:
  void setup();

  std::vector<CostFunction> cost_functions;
};

#endif
