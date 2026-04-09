/*
Traverse the number representing string inversely, and check the previous
(the one immediately on the right). If such previous element is smaller,
then do nothing. Otherwise, subtract it.
*/

class Solution
{
private:
    std::unordered_map<char, int> nums_ =
    {
        {'I', 1     },
        {'V', 5     },
        {'X', 10    },
        {'L', 50    },
        {'C', 100   },
        {'D', 500   },
        {'M', 1000  },
    };

public:
    int romanToInt(std::string s)
    {
        const int s_size = static_cast<int>(s.size());

        int ret = 0;

        for(int i = s_size - 1; i >= 0; i--)
            if(i == s_size - 1 || nums_[s[i]] >= nums_[s[i + 1]])
                ret += nums_[s[i]];
            else
                ret -= nums_[s[i]];

        return ret;
    }
};