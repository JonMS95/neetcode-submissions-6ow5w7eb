/*
For each element, compute the running sum and store it somewhere.
[2, -1, 1, 2]
[2,  1, 2, 4]

For every element, if running sum is equal to the target number, then there's obviously
a suitable subarray there. Also, we should find whether there's any other (can be
multiple, actually) which comply with the condition: cur_run_sum - prev_run_sum == target.

Example:
target = 2
array = [0, 1, -1, 2, -2, 4]
r_sum = [0, 1,  0, 2,  0, 4]

The idea beneath can be explained as follows: for a given interval with a given running
sum, is there any subinterval with a running sum such that if the elements involved are
removed, then sum for the difference interval is equal to our target.

In the example above:
In index 3, running sum is equal to 2 (== target). Since there are two narrower
subintervals for which target - current_cumulative_sum, then 2 should be added. Also, the
current running sum itself is a target, so add it as well. Another valid index would be
5, since there is a previous sum which adds up to 4 - 2 == 2.
In total, 4 subarrays can be found for the given example.

Another example:
target = 2
array = [2, -1, 1, 2]
r_sum = [2,  1, 2, 4]
*/

class Solution
{
public:
    int subarraySum(std::vector<int>& nums, int k)
    {
        // Current running sum.
        int cur_sum = 0;

        // Maps a running sum to the number of times it has already been found.
        std::unordered_map<int, int> sum_times;

        // Global counter which counts number of valid subarrays.
        int ret = 0;

        for(int n : nums)
        {
            cur_sum += n;

            if(cur_sum == k)
                ++ret;
            
            if(sum_times.count(cur_sum - k))
                ret += sum_times[(cur_sum - k)];

            ++sum_times[cur_sum];
        }

        return ret;
    }
};