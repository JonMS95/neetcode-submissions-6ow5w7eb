/*
Approach: use Prim's algorithm to generate a Minimum Spanning Tree (MST).
The generated MST is a set of edges that connects all of the nodes in a
given graph with a minimum cumulative cost.
After generating the tree, calculate the sum of all costs and return it.
*/

class Edge
{
public:
    int src_; // Source index
    int dst_; // Destination index
    int wgt_; // Weight (distance)

    Edge(const int src, const int dst, const int wgt): src_(src), dst_(dst), wgt_(wgt) {}
};

class Solution
{
private:
    std::vector<Edge> _getEdgesForNode(std::vector<std::vector<int>>& points, const int idx, const std::unordered_set<int>& visited)
    {
        std::vector<Edge> ret;
        std::pair<int, int> source_point = {points[idx][0], points[idx][1]};
        int dist;

        for(int i = 0; i < static_cast<int>(points.size()); i++)
        {
            if(i == idx || visited.count(i))
                continue;
            
            dist = std::abs(points[idx][0] - points[i][0]) + std::abs(points[idx][1] - points[i][1]);

            ret.push_back(Edge(idx, i, dist));
        }

        return ret;
    }

public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points)
    {
        const int num_of_points = static_cast<int>(points.size());
        std::unordered_set<int> visited;
        visited.insert(0);

        auto org_crit = [](const Edge& a, const Edge& b) -> bool
        {
            return a.wgt_ > b.wgt_;
        };
        std::priority_queue<Edge, std::vector<Edge>, decltype(org_crit)> min_heap(org_crit);

        int cur_idx = 0;
        int ret = 0;

        while(visited.size() < num_of_points)
        {
            // Push current node's edges to the min heap.
            for(Edge e : _getEdgesForNode(points, cur_idx, visited))
                min_heap.push(e);
            
            while(visited.count(min_heap.top().dst_))
                min_heap.pop();
            
            cur_idx = min_heap.top().dst_;
            visited.insert(cur_idx);
            ret += min_heap.top().wgt_;

            min_heap.pop();
        }

        return ret;
    }
};
