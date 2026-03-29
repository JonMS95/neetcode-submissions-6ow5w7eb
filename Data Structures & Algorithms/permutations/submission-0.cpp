class Solution {
private:
    using u_set_int = std::unordered_set<int>;
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

    vec_int _makePermutationFromVectorAndIndices(vec_int& vec, vec_int& indices)
    {
        const int vec_size = static_cast<int>(vec.size());

        vec_int ret(vec_size);

        for(int i = 0; i < vec_size; i++)
            ret[i] = vec[indices[i]];
        
        return ret;
    }

    void _backtracking(vec_int& nums, vec_int& indices, u_set_int& known_indices, mat_int& ret)
    {
        if(known_indices.size() == nums.size())
        {
            ret.emplace_back(this->_makePermutationFromVectorAndIndices(nums, indices));

            return;
        }

        const int nums_size = static_cast<int>(nums.size());

        for(int i = 0; i < nums_size; i++)
        {
            if(known_indices.count(i))
                continue;
            
            known_indices.insert(i);
            indices.emplace_back(i);

            this->_backtracking(nums, indices, known_indices, ret);

            indices.pop_back();
            known_indices.erase(i);
        }
    }

public:
    mat_int permute(vec_int& nums)
    {
        vec_int indices;
        u_set_int known_indices;
        mat_int ret;

        this->_backtracking(nums, indices, known_indices, ret);

        return ret;
    }
};
