#include "cost_function.h"

void CostFunctions::setup()
{
    CostFunctionType wrong_lane = [=] (const Trajectory& t, const map<int, vector<vector<int>>>& predictions)
    {
        double cost = static_cast<double>(abs(t.future.lane - t.future.goal_lane)) / t.future.lanes_available;
        // cout << "cost:" << cost;
        return cost;
    };

    cost_functions.emplace_back(CostFunction(1.0, wrong_lane));
}
