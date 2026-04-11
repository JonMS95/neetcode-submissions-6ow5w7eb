class Edge
{
public:
    int src_;
    int dst_;
    int wgt_;

    Edge(const int src, const int dst, const int wgt): src_(src), dst_(dst), wgt_(wgt) {}
};

class Solution
{
private:
    // Get Manhattan distance from a couple of points.
    inline int _getManDist(const std::vector<int>& p1, const std::vector<int>& p2)
    {
        return (std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]));
    }

    // Get all possible edges from the set of points.
    std::vector<Edge> _getEdgesFromPoints(const std::vector<std::vector<int>>& points)
    {
        const int num_of_points = static_cast<int>(points.size());
        std::vector<Edge> ret;

        for(int i = 0; i < num_of_points; i++)
            for(int j = (i + 1); j < num_of_points; j++)
                ret.push_back(Edge(i, j, _getManDist(points[i], points[j])));
        
        // After generating all nodes, sort them by their weight.
        auto sort_crit = [](const Edge& a, const Edge& b) -> bool
        {
            return a.wgt_ < b.wgt_;
        };

        std::sort(ret.begin(), ret.end(), sort_crit);

        return ret;
    }

    // Recursively update node parent until parent's value is equal to the node itself.
    int _find(const int node_id, std::vector<int>& parents)
    {
        if(node_id != parents[node_id])
            parents[node_id] = _find(parents[node_id], parents);
        return parents[node_id];
    }

    // Unite a couple of nodes only if their roots differ.
    bool _union(const int node_a, const int node_b, std::vector<int>& parents)
    {
        const int root_a = _find(node_a, parents);
        const int root_b = _find(node_b, parents);

        // If we come across a cycle, then refuse to unite provided nodes.
        if(root_a == root_b)
            return false;
        
        parents[root_a] = root_b;
    
        return true;
    }

public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points)
    {
        const int num_of_points = static_cast<int>(points.size());
        std::vector<int> parents(num_of_points);
        for(int i = 0; i < num_of_points; i++)
            parents[i] = i;

        std::vector<Edge> edges = _getEdgesFromPoints(points);

        int num_of_edges = 0;
        int ret = 0;

        for(int i = 0; i < static_cast<int>(edges.size()); i++)
        {
            if(_union(edges[i].src_, edges[i].dst_, parents))
            {
                ret += edges[i].wgt_;
                ++num_of_edges;
            }

            if(num_of_edges == (num_of_points - 1))
                break;
        }

        return ret;
    }
};
