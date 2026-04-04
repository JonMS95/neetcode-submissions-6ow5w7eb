/*
Key idea: if elements are sorted, we can check whether current element is equal to the prior one.
If that's the case, there's no reason to keep traversing as it will repeat values.
*/

class Solution
{
private:
    // Tries every combination and stores it if successful as priorly explained.
    void _backtracking( const std::vector<int>& nums            ,
                        const int target                        ,
                        std::vector<int>& used                  ,
                        std::vector<std::vector<int>>& known    ,
                        const int idx = -1                      )
    {
        // If target < 0, then it means thatcurrent combination is not suitable.
        if(target < 0)
            return;

        // If target == 0, then store current combination and exit.
        if(target == 0)
        {
            known.emplace_back(used);
            return;
        }

        // Otherwise, there's still work to do.
        for(int i = idx + 1; i < static_cast<int>(nums.size()); i++)
        {
            if(i > idx + 1 && nums[i] == nums[i - 1])
                continue;

            used.emplace_back(nums[i]);
            this->_backtracking(nums, target - nums[i], used, known, i);
            used.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        std::vector<int> used;
        std::vector<std::vector<int>> ret;
        std::sort(candidates.begin(), candidates.end());

        this->_backtracking(candidates, target, used, ret);
        
        return ret;
    }
};
