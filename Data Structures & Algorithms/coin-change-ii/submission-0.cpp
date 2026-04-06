class Solution {
private:
    inline int _makeKeyFromIntegers(const int a, const int b)
    {
        return ((a << 16) | b);
    }

    int _dfs(int amount, const std::vector<int>& coins, std::unordered_map<int, int>& known_values, int idx = 0)
    {
        int ret = 0;
        int key = this->_makeKeyFromIntegers(amount, idx);

        if(known_values.count(key))
            return known_values[key];

        if(amount < 0)
        {
            ret = 0;
        }
        else if(amount == 0)
        {
            ret = 1;
        }
        else
        {
            const int coins_size = static_cast<int>(coins.size());

            for(int i = idx; i < coins_size; i++)
                ret += this->_dfs(amount - coins[i], coins, known_values, i);
        }

        known_values[key] = ret;

        return ret;
    }

public:
    int change(int amount, std::vector<int>& coins)
    {
        std::sort(coins.begin(), coins.end());
        std::unordered_map<int, int> known_values;

        return this->_dfs(amount, coins, known_values);
    }
};
