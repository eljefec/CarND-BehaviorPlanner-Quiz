#ifndef COSTFUNCTION_H
#define COSTFUNCTION_H

#include <functional>
#include <map>
#include <vector>

class Trajectory;

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

#endif
