class Solution {
private:
    std::unordered_map<int, int> _makeHistFromVec(const std::vector<int>& nums)
    {
        std::unordered_map<int, int> ret;

        for(int n : nums)
            ++ret[n];
        
        return ret;
    }

public:
    void sortColors(std::vector<int>& nums)
    {
        std::unordered_map<int, int> hist = this->_makeHistFromVec(nums);

        for(int i = 0; i < hist[0]; i++)
            nums[i] = 0;
        
        for(int i = hist[0]; i < (hist[0] + hist[1]); i++)
            nums[i] = 1;
        
        for(int i = (hist[0] + hist[1]); i < (hist[0] + hist[1] + hist[2]); i++)
            nums[i] = 2;
    }
};