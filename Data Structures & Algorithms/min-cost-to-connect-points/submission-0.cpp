/*
Approach: Prim's algorithm.

Each time a node is added to the visited nodes set, generate all the edges
that link such node to all of the other non-visited nodes. Add those edges
to a heap. In that heap, the top element is the one with the least cost.
While the number of visited nodes is lower than the number of points, keep
choosing the top element as log as it's not in the visited nodes set.
*/

class Solution
{
private:
    inline int _getManhattanDistance(const std::vector<std::vector<int>>& points, const int i, const int j)
    {
        return (std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]));
    }

    std::vector<std::vector<int>> _generateEdgesForNode(const std::vector<std::vector<int>>& points, const int idx)
    {
        std::vector<std::vector<int>> ret;
        int md;

        for(int i = 0; i < static_cast<int>(points.size()); i++)
        {
            if(i == idx)
                continue;
            
            md = _getManhattanDistance(points, idx, i);
            ret.push_back({idx, i, md});
        }

        return ret;
    }

public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points)
    {
        const int points_size = static_cast<int>(points.size());

        std::unordered_set<int> visited;

        auto sort_crit = [](const std::vector<int>& a, const std::vector<int>& b) -> bool
        {
            return a[2] > b[2];
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(sort_crit)> min_heap(sort_crit);

        visited.insert(0);

        int cur = 0;
        int ret = 0;

        while(visited.size() < points_size)
        {
            for(std::vector<int> edge : _generateEdgesForNode(points, cur))
                min_heap.push(edge);
            
            while(visited.count(min_heap.top()[1]))
                min_heap.pop();

            cur = min_heap.top()[1];
            ret += min_heap.top()[2];

            min_heap.pop();

            visited.insert(cur);
        }

        return ret;
    }
};
