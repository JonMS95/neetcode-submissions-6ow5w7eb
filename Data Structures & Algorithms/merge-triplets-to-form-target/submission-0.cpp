class Solution {
private:
    const int triplet_size_ = 3;
    const int target_mask_  = 0b111;

    int _getTripletMask(const std::vector<int>& triplet, const std::vector<int>& target)
    {
        int ret = 0;

        for(int i = 0; i < triplet_size_; i++)
            if(triplet[i] > target[i])
                return -1;
            else
                if(triplet[i] == target[i])
                    ret |= (1 << i);

        return ret;
    }

public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target)
    {
        int mask = 0;
        int cur;

        for(const std::vector<int>& tr : triplets)
        {
            cur = _getTripletMask(tr, target);

            if(cur < 0)
                continue;
            
            mask |= cur;

            if(mask == target_mask_)
                return true;
        }

        return false;
    }
};
