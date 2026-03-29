class Solution {
private:
    std::unordered_map<int, std::string> int_to_chars_ = 
    {
        {2, "abc"   },
        {3, "def"   },
        {4, "ghi"   },
        {5, "jkl"   },
        {6, "mno"   },
        {7, "pqrs"  },
        {8, "tuv"   },
        {9, "wxyz"  },
    };

    // From digits and index, select current characters. If final idx, then add to
    // global return variable. Otherwise, increment index and go ahead with the
    // following characters.
    void _backtrack(const std::string& digits       ,
                    std::string& cur                ,
                    std::vector<std::string>& ret   ,
                    const int idx = 0               )
    {
        if(idx >= static_cast<int>(digits.size()))
            return;

        int current_number = digits[idx] - '0';

        for(char c : this->int_to_chars_[current_number])
        {
            cur += c;

            if(digits.size() == cur.size())
                ret.emplace_back(cur);
            else
                this->_backtrack(digits, cur, ret, idx + 1);

            cur.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::string cur = "";
        std::vector<std::string> ret;

        this->_backtrack(digits, cur, ret);

        return ret;
    }
};
