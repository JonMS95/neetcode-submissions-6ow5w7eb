/*
Approach: use Kahn's algorithm so as to perform a topological sort. It's output, in fact,
is no other than a valid order in which the nodes in an adjacency matrix (regardless of
whether they represent a single graph or not).

In this case, we are provided with a list of adjacency in which we have a node and the
incoming node paired.

We can start by creating a map linking nodes to both the number of incoming nodes as well
as a set with the outcoming ones.
*/

class Solution
{
private:
    std::unordered_map<int, std::pair<int, std::unordered_set<int>>> _createMapFromReqs(int num_courses, std::vector<std::vector<int>>& reqs)
    {
        std::unordered_map<int, std::pair<int, std::unordered_set<int>>> ret;

        for(int i = 0; i < num_courses; i++)
            ret[i] = {0, {}};
        
        for(const std::vector<int>& req : reqs)
        {
            ret[req[1]].second.insert(req[0]);
            ++ret[req[0]].first;
        }

        return ret;
    }

public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        std::unordered_map<int, std::pair<int, std::unordered_set<int>>> guide = _createMapFromReqs(numCourses, prerequisites);
        std::queue<int> q;
        std::vector<int> ret;
        int cur;

        // Add the elements with 0 indegree.
        for(auto it = guide.begin(); it != guide.end(); it++)
            if(!it->second.first)
                q.push(it->first);
    
        // If no elements with 0 indegree, then there's a loop.
        if(!q.size())
            return {};
        
        while(q.size())
        {
            cur = q.front();
            q.pop();

            /*
            For the current node, do the following:
            Push the node to the vector of visited nodes.
            For each of its neighbors, decrease their indegree.
            If the indegree of any of those neighbors turns out to be
            zero after decreasing it, then push it to the queue.
            */

            ret.emplace_back(cur);

            for(int n : guide[cur].second)
            {
                --guide[n].first;
                if(!guide[n].first)
                    q.push(n);
            }
        }

        // If the number of nodes in the list of visited nodes is different from the total
        // number of nodes, then a cycle/loop has been found somewhere. In that case, return
        // an empty vector.

        if(static_cast<int>(ret.size()) != numCourses)
            return {};
        
        return ret;
    }
};
