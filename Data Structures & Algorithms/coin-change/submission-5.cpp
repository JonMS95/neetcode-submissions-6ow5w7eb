class Solution {
private:
    int _coinChange(std::vector<int>& coins, int amount, std::unordered_map<int,int>& memo)
    {
        if(memo.count(amount))
            return memo[amount];

        if(amount < 0)
            return -1;

        if(amount == 0)
            return 0;

        int minCoins = -1;

        for(int coin : coins)
        {
            int res = _coinChange(coins, amount - coin, memo);

            if(res >= 0)
            {
                int candidate = res + 1;

                if(minCoins < 0)
                    minCoins = candidate;
                else
                    minCoins = std::min(minCoins, candidate);
            }
        }

        memo[amount] = minCoins;
        return minCoins;
    }

public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::unordered_map<int,int> memo;
        return _coinChange(coins, amount, memo);
    }
};