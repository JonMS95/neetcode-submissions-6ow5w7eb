class Solution {
private:
    using vec_int   = std::vector<int>;
    using pq_max    = std::priority_queue<int, std::vector<int>, std::less<int>>;

public:
    int lastStoneWeight(vec_int& stones)
    {
        pq_max max_heap(stones.begin(), stones.end());

        int x, y;

        while(max_heap.size() > 1)
        {
            y = max_heap.top(); max_heap.pop();
            x = max_heap.top(); max_heap.pop();

            if(x == y)
                continue;
            
            max_heap.push((y - x));
        }

        return (max_heap.size() ? max_heap.top() : 0);
    }
};
