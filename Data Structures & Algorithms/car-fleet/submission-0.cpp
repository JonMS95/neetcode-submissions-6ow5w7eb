/*
Approach: sort speed and position by position's value in descending order.
For each car, calculate the time needed to reach target position.
Now, for each element, check whether it needs less time than prior car (if any).
If so, they are a fleet. The criterion to add a fleet should be the following:
·If no prior element, then add 1 to the num_of_fleets variable.
·If element needs less or equal time than prior, then get to the following car.
·Otherwise (time strictly greater than prior car), add +1 to the number of
fleets.
*/

class CarData
{
public:
    int pos_;   // Initial position
    int spd_;   // Speed.
    double t2t_;   // Time to target.

    CarData(const int pos, const int spd, const double t2t): pos_(pos), spd_(spd), t2t_(t2t) {}
};

class Solution
{
private:
    std::vector<CarData> _getVectorOfCars(  const std::vector<int>& position,
                                            const std::vector<int>& speed   ,
                                            const int target                )
    {
        const int num_of_cars = static_cast<int>(position.size());
        std::vector<CarData> cars;

        for(int i = 0; i < num_of_cars; i++)
            cars.push_back(CarData(position[i], speed[i], (static_cast<double>(target - position[i]) / speed[i])));
        
        return cars;
    }

public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed)
    {
        std::vector<CarData> cars = _getVectorOfCars(position, speed, target);

        auto sort_crit = [](const CarData& a, const CarData& b) -> bool
        {
            return a.pos_ > b.pos_;
        };
        std::sort(cars.begin(), cars.end(), sort_crit);

        int ret = 0;

        for(int i = 0; i < static_cast<int>(cars.size()); i++)
        {
            if(!i)
            {
                ++ret;
                continue;
            }

            if(cars[i - 1].t2t_ >= cars[i].t2t_)
            {
                cars[i].t2t_ = cars[i - 1].t2t_;
                continue;
            }

            ++ret;
        }

        return ret;
    }
};
