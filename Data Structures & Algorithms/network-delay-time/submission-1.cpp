/*
Dijkstra's algorithm based approach.

1 - Transform times matrix into an adjacency matrix (more usual and humanly understandable).
Each row represents a source node (0-indexed), and the content of each row will be a vector
of {destination-weight pairs}.

2 - Apply Dijkstra's algorithm, and return a vector of minimum costs (cumulative weights
from) source node to any other node within the graph traversing it by using provided
adjacency matrix. Further explanations about the algorithm's implementation are provided
within function's body.

3 - Since the aim is to return the minimum time for all nodes to receive the signal incoming
from the source node, the value to return is the maximum among them.
*/

class Solution
{
private:
    // Set some custom type aliases so as to shorten function prototypes.
    using dist_vector   = std::vector<int>;
    using time_vector   = std::vector<int>;
    using times_matrix  = std::vector<time_vector>;
    using adj_matrix    = std::vector<std::vector<std::pair<int, int>>>;
    using wn_par        = std::pair<int, int>;
    using wn_vector     = std::vector<wn_par>;
    using nw_par        = std::pair<int, int>;

    /*
    Returns a matrix where for each node (associated to each row), a vector of pairs
    representing adjacent nodes and their weights.
    */
    adj_matrix _getAdjacencyMatrixFromTimes(const times_matrix& times, const int num_of_nodes)
    {
        adj_matrix ret(num_of_nodes);

        int src_node, dst_node, weight;

        for(time_vector t_vec : times)
        {
            // Make both source and destination 0-indexed.
            src_node    = t_vec[0] - 1;
            dst_node    = t_vec[1] - 1;
            weight      = t_vec[2];

            // For each row (source-node related), add a destination-weight pair.
            ret[src_node].push_back({dst_node, weight});
        }

        return ret;
    }

    dist_vector _dijkstra(const adj_matrix& adj, const int src)
    {
        // NUmber of nodes is equal to number of rows in adjacency matrix.
        const int num_of_nodes = static_cast<int>(adj.size());

        /*
        Declare a distance vector. This will represent the distance from source node
        to every other node. Initialize distances as INT_MAX (resembling infinity)
        except for source node (distance to itself is 0).
        */
        dist_vector dist(num_of_nodes, INT_MAX);
        dist[src] = 0;

        /*
        Create a sorting criterion for the heap to be initialized afterwards. The
        heap in question will be a min heap in which the top {weight, node}-type
        pair will be the less weighted one.
        */
        auto sort_crit = [](const wn_par& a, const wn_par& b) -> bool
        {
            return a.first > b.first;
        };

        std::priority_queue<wn_par, wn_vector, decltype(sort_crit)> min_heap(sort_crit);

        // Start by pushing {0, source-node} pair.
        min_heap.push({0, src});

        /*
        Declare some variables to be used later. Each of them represent, respectively:
        current node, current cumulative weight, adjacent node, adjacent node weight.
        */
        int u, d, v, w;

        // While heap contains at least one pair, follow the steps below.
        while(!min_heap.empty())
        {
            // Extract current node and its cumulative distance / weight from heap.
            d = min_heap.top().first;
            u = min_heap.top().second;

            // Pop current pair from the heap (there's no need to keep waiting).
            min_heap.pop();

            /*
            If found cumulative distance does not improve nor equal the one already
            stored in distances vector, then cut it short and go ahead with the
            following element.
            */
            if(d > dist[u])
                continue;
            
            // Iterate through all adjacent nodes.
            for(const nw_par next : adj[u])
            {
                // Retrieve node and weight. Keep in mind that the order in adjacency matrix.
                v = next.first;
                w = next.second;

                /*
                If distance until current node plus adjacent node's weight improves already
                stored distance to adjacent node, then push improved distance pair to the heap.
                Also, update cumulative distance to adjacent node.
                */
                if((dist[u] + w) < dist[v])
                {
                    dist[v] = dist[u] + w;
                    min_heap.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    // Get maximum element in distance vector (returned after applying Dijkstra's algorithm).
    int _getMaxInVector(const dist_vector& dst)
    {
        int ret = 0;

        for(int d : dst)
            if(d > ret)
                ret = d;
        
        return ret;
    }

public:
    int networkDelayTime(times_matrix& times, int n, int k)
    {
        adj_matrix adj = this->_getAdjacencyMatrixFromTimes(times, n);
        dist_vector dst = this->_dijkstra(adj, k - 1);
        int max_dist = this->_getMaxInVector(dst);

        return ((max_dist == INT_MAX) ? -1 : max_dist);
    }
};
