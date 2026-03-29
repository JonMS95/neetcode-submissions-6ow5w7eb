class Solution {
private:
    std::unordered_map<char, char> par_pairs =
    {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    inline bool isOpeningPar(const char c)
    {
        return c == '(' || c == '[' || c == '{';
    }

    inline bool isClosingPar(const char c)
    {
        return c == ')' || c == ']' || c == '}';
    }

public:
    bool isValid(string s)
    {
        std::stack<char> st;

        for(char c : s)
        {
            // If current parentheses turns to be an opening one, then simply add it to the stack.
            if(this->isOpeningPar(c))
            {
                st.push(c);
            }
            // If found parentheses is a closing one, then:
            else if(this->isClosingPar(c))
            {
                // Check whether the stack is empty. If so, then parentheses are not valid at all.
                if(st.empty())
                    return false;
                
                // If it's not empty, then check whether the one at the top matches current one (closing).
                if(this->par_pairs[st.top()] != c)
                    return false;
                
                // If a match was found, then simply remove the one at the stack's top and go ahead.
                st.pop();
            }
            else
            {
                throw std::runtime_error("A character different from parentheses was found.");
            }
        }

        // If the stack is emtpy, then it's okay. If it's not (filled only with opening parentheses),
        // then no "false" value may have been returned so far, but parentheses are still invalid.
        return st.empty();
    }
};
