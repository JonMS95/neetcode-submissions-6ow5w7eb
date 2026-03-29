class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int fast = 0;
        int slow = 0;
        int ret = 0;
        int cur;

        std::unordered_set<char> known;

        while(fast < static_cast<int>(s.size()))
        {
            if(!known.count(s[fast]))
            {
                if((cur = fast - slow + 1) > ret)
                    ret = cur;

                known.insert(s[fast++]);
                continue;
            }

            while(s[slow] != s[fast])
            {
                known.erase(s[slow]);
                ++slow;
            }

            known.erase(s[slow]);
            ++slow;
        }

        return ret;
    }
};
