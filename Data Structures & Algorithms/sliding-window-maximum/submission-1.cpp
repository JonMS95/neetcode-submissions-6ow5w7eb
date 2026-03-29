/*
·Naïve approach: use a max heap in which last element is discarded and new first element
is added. This is okay at first, but it does take too much computational effort to be
solved since last element would have to be removed. We do actually have no way to do so
hence the only viable startegy here would be creating a new heap per window.

·Smart approach: store every element alongside its index. For each window movement, push
the newest (rightmost) element within the current window to the heap. So as to retrieve
the top element, keep in mind it might not be valid since there's a chance it's not found
between current window's boundaries, then elements with not available indices should be
popped. After popping process is complete, store the top. Of course, there will be spare
smaler-than-top elements stored in the heap, but there's no point in discarding them since
doing so would corrupt the whole heap.
*/

class Solution
{
private:
    using vec_int = std::vector<int>;
    using par_int = std::pair<int, int>;
    using par_int_vec = std::vector<par_int>;

public:
    vec_int maxSlidingWindow(vec_int& nums, int k)
    {
        vec_int ret(nums.size() - k + 1);

        auto org_crit = [](const par_int& a, const par_int& b) -> bool
        {
            return (a.first < b.first);
        };

        using pq_max = std::priority_queue<par_int, par_int_vec, decltype(org_crit)>;
    
        pq_max max_heap;

        for(int i = 0; i < (k - 1); i++)
            max_heap.push({nums[i], i});

        for(int i = 0; i < static_cast<int>(nums.size() - k + 1); i++)
        {
            max_heap.push({nums[i + k - 1], (i + k - 1)});

            while(max_heap.top().second < i)
                max_heap.pop();
            
            ret[i] = max_heap.top().first;
        }

        return ret;
    }
};
