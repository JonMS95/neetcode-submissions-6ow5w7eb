class Solution {
private:
    using vec_int    = std::vector<int>;
    using mat_int    = std::vector<vec_int>;
    using set_int    = std::unordered_set<int>;
    using node_guide = std::unordered_map<int, set_int>;

    node_guide _makeGuideFromReqs(int num_courses, const mat_int& reqs)
    {
        node_guide ret;

        for (int i = 0; i < num_courses; i++)
            ret[i] = {};

        for (const vec_int& req : reqs)
            ret[req[1]].insert(req[0]);

        return ret;
    }

    vec_int order;
    std::vector<int> state;

    bool _dfs(int node, node_guide& guide)
    {
        if (state[node] == 1) return false; // cycle detected
        if (state[node] == 2) return true;  // already processed

        state[node] = 1; // visiting

        for (int next : guide[node])
        {
            if (!_dfs(next, guide))
                return false;
        }

        state[node] = 2; // done
        order.push_back(node); // postorder add

        return true;
    }

public:
    vec_int findOrder(int numCourses, mat_int& prerequisites)
    {
        node_guide guide = _makeGuideFromReqs(numCourses, prerequisites);

        state.assign(numCourses, 0);
        order.clear();

        for (int i = 0; i < numCourses; i++)
        {
            if (state[i] == 0)
            {
                if (!_dfs(i, guide))
                    return {};
            }
        }

        std::reverse(order.begin(), order.end());
        return order;
    }
};