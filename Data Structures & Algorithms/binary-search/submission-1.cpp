class Solution {
private:
    using vec_int = std::vector<int>;

    int _recursiveBinarySearch( const vec_int& nums ,
                                const int target    ,
                                const int l         ,
                                const int r         )
    {
        if(l > r)
            return -1;

        const int m = l + (r - l) / 2;

        if(nums[m] == target)
            return m;
        
        if(target < nums[m])
            return this->_recursiveBinarySearch(nums, target, l, m - 1);
        else
            return this->_recursiveBinarySearch(nums, target, m + 1, r);
    }

public:
    int search(vec_int& nums, int target) 
    {
        return this->_recursiveBinarySearch(nums, target, 0, static_cast<int>(nums.size() - 1));
    }
};
