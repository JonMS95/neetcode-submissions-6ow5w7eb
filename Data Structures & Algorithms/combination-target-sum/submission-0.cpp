class Solution {
private:
    void backtrack( vector<int>& nums                                   ,
                    int target                                          ,
                    std::vector<int>& combination                       ,
                    std::vector<std::vector<int>>& known_combinations   )
    {
        if(target == 0)
        {
            std::vector<int> aux = combination;
            std::sort(aux.begin(), aux.end());

            if(!std::count(known_combinations.begin(), known_combinations.end(), aux))
                known_combinations.emplace_back(aux);

            return;
        }

        if(target < 0)
            return;
        
        for(int n : nums)
        {
            combination.emplace_back(n);
            this->backtrack(nums, target - n, combination, known_combinations);
            combination.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> ret;

        std::vector<int> cur;
        this->backtrack(nums, target, cur, ret);
        return ret;
    }
};
