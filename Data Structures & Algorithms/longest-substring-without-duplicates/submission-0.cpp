/*
slow = 0, fast = 0
·            ·            ·            ·                  
zxyzxyz ->  zxyzxyz ->  zxyzxyz ->  zxyzxyz ->  zxyzxyz 
·           ·           ·            ·                    

·           ·           ·           ·         ·          ·
abcb    -> abcb    -> abcb    -> abcb   -> abcb   ->  abcb
·          ·          ·          ·          ·           ·
*/

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int slow = 0;
        int fast = 0;

        std::unordered_set<char> known;
        const int s_size = static_cast<int>(s.size());

        int ret = 0;

        while(fast < s_size)
        {
            // Is current fast character known?
            // If not, add it
            if(!known.count(s[fast]))
            {
                if(ret < (fast - slow + 1))
                    ret = (fast - slow + 1);

                known.insert(s[fast]);
                ++fast;
            }
            else
            {
                while(s[slow] != s[fast])
                {
                    known.erase(s[slow]);
                    ++slow;
                }
                
                known.erase(s[slow]);
                ++slow;
            }
        }

        return ret;
    }
};
