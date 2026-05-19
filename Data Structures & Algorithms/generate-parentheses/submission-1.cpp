class Solution
{
private:
    void _backtrack(std::string& cur, std::vector<std::string>& ret, const int n, const int balance = 0)
    {
        if(!n)
        {
            if(!balance)
                ret.emplace_back(cur);
            
            return;
        }

        if(!balance)
        {
            cur += '(';
            _backtrack(cur, ret, n - 1, balance + 1);
            cur.pop_back();
        }
        else
        {
            cur += '(';
            _backtrack(cur, ret, n - 1, balance + 1);
            cur.pop_back();

            cur += ')';
            _backtrack(cur, ret, n - 1, balance - 1);
            cur.pop_back();
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::string cur = "";
        std::vector<std::string> ret;
        _backtrack(cur, ret, (2 * n));

        return ret;
    }
};
