#ifndef STATECOST_H
#define STATECOST_H

class StateCost
{
public:
    StateCost(double cost, const string& state)
        : cost(cost),
          state(state)
    {
    }

    const string& get_state()
    {
        return state;
    }

private:
    double cost;
    string state;

    friend bool operator<(const StateCost& a, const StateCost& b);
};

bool operator<(const StateCost& a, const StateCost& b)
{
    return (a.cost < b.cost);
}

class StateCosts
{
public:
    string get_best_state()
    {
        std::make_heap(state_costs.begin(), state_costs.end());
        return state_costs.back().get_state();
    }

    void add(const StateCost&& state_cost)
    {
        state_costs.emplace_back(state_cost);
    }

private:
    std::vector<StateCost> state_costs;
};

#endif
