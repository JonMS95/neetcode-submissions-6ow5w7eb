class Solution {
private:
    using vec_int = std::vector<int>;

    int multiplyAllExceptIndex(vec_int& nums, const int target_idx)
    {
        int ret = 1;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            if(i != target_idx)
                ret *= nums[i];
        
        return ret;
    }

public:
    vec_int productExceptSelf(vec_int& nums)
    {
        // Brute force approach: for every element in the vector, multiply all of the elements
        // within the vector except for the current.
        vec_int ret;
        
        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            ret.emplace_back(this->multiplyAllExceptIndex(nums, i));
    
        return ret;
    }
};
