/*
Logic (with example):

nums=[2,10,10,30,30,30]

slow = 0
fast = 1 (slow + 1)

While fast < nums_size, keep doing the following:
    ·If both are different, then slow = fast, fast += 1
    ·If both are the same, erase the one at nums[fast]

Example:
[2,10,10,30,30,30]
 s f
[2,10,10,30,30,30]
   s  f
[2,10,30,30,30]
   s  f
[2,10,30,30,30]
      s  f
[2,10,30,30]
      s  f
[2,10,30]
      s  f
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int slow = 0;
        int fast = 1;

        while(fast < static_cast<int>(nums.size()))
            if(nums[slow] == nums[fast])
                nums.erase(nums.begin() + fast);
            else
                slow = fast++;
        
        return static_cast<int>(nums.size());
    }
};