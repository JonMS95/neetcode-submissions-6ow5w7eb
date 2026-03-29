class Solution { 
public:
    int characterReplacement(string s, int k)
    {
        int fast = 0;
        int slow = 0;

        const int s_size = static_cast<int>(s.size());
        
        int max_freq = 0;
        int ret = 0;

        std::unordered_map<char, int> found_nums;

        int cur;
        int intruders;

        while(fast < s_size)
        {
            // Add new character to the window
            ++found_nums[s[fast]];
            
            if(found_nums[s[fast]] > max_freq)
                max_freq = found_nums[s[fast]];

            cur = fast - slow + 1;
            intruders = cur - max_freq;

            // Shrink window if invalid
            while(intruders > k)
            {
                --found_nums[s[slow]];
                slow++;

                cur = fast - slow + 1;
                intruders = cur - max_freq;
            }

            if(cur > ret)
                ret = cur;

            fast++;
        }

        return ret;
    }
};