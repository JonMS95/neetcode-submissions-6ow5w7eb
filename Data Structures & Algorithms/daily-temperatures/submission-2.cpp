/*
For each elemement, we should keep track of all greater elements rightwards.
This gives us quite a straightforward clue: we should use a monotonic-decreasing
stack, which will be filled while traversing the vector leftwards

This would be a nice approach if we were asked to retrieve the first higher
temperature to the right of each element, but that's not what we are prompted for.
In this case, both the temperature as well as the index in which it was found are
required.
*/

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        const int temp_size = static_cast<int>(temperatures.size());
        std::stack<std::pair<int, int>> grt; // Greatest rightwards temperatures, stored as temp-idx pairs.
        std::vector<int> ret(temp_size);

        for(int i = (temp_size - 1); i >= 0; i--)
        {
            // While stack is not empty, keep removing elements which first member (temperature) is
            // equal or greater than current.
            while(!grt.empty() && grt.top().first <= temperatures[i])
                grt.pop();
            
            ret[i] = grt.empty() ? 0 : (grt.top().second - i);
            
            grt.push({temperatures[i], i});
        }

        return ret;
    }
};
