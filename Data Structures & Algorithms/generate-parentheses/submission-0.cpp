class Solution {
private:
    using vec_str = std::vector<std::string>;

    /*
    Each opening parentheses is countered by a closing one. We can have
    a counter for such purpose.
    */

    void _backtracking(vec_str& ret, std::string& cur, const int remaining, const int op_cl = 0)
    {
        if(remaining < 0)
            throw std::runtime_error("Unexpected value for \'remaining\' found");

        if(!remaining)
        {
            ret.emplace_back(cur);
            return;
        }
        
        // The balance between opening and closing parenteheses (opening - closing)
        // cannot exceed the number of remaining characters and still be valid.
        // For instance, if opening - closing == 2 and remaining == 1, we need more
        // closing parentheses than what we need. If opening - closing == 2 and
        // remaining == 2, again, only closing parentheses can be added as the two
        // remaining elements. Therefore, we can only add opening parentheses if
        // there are more remaining parentheses than opening - closing.
        
        if(remaining > op_cl)
        {
            cur += '(';
            this->_backtracking(ret, cur, remaining - 1, op_cl + 1);
            cur.pop_back();
        }

        // If opening - closing == 0, then only opening parentheses can be added.
        // We cannot add closing parentheses to a string which has no matching
        // opening parentheses at all.
        if(!op_cl)
            return;

        cur += ')';
        this->_backtracking(ret, cur, remaining - 1, op_cl - 1);
        cur.pop_back();
    }

public:
    vec_str generateParenthesis(int n)
    {
        vec_str ret;
        std::string cur = "";
        
        this->_backtracking(ret, cur, 2 * n);

        return ret;
    }
};
