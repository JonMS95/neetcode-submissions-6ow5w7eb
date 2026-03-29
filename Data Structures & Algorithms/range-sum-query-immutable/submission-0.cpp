class NumArray {
private:
    std::vector<int> cum_sums_;

public:
    NumArray(std::vector<int>& nums)
    {
        // For each element, store the cumulative sum:
        int cum_sum = 0;

        for(int n : nums)
        {
            cum_sum += n;
            this->cum_sums_.emplace_back(cum_sum);
        }
    }
    
    int sumRange(int left, int right)
    {
        if(!left)
            return this->cum_sums_[right];
        else
            return (this->cum_sums_[right] - this->cum_sums_[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */