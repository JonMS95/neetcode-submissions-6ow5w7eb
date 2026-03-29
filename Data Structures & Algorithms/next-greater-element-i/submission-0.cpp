class Solution {

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        std::unordered_map<int, int> known_answers;

        for(int n: nums1)
            known_answers[n] = -1;

        std::stack<int> dmst; // Decreasing monotonic stack.

        for(int i = static_cast<int>(nums2.size() - 1); i >= 0; i--)
        {
            // Keep popping elements until stack is empty or a strictly greater element is at its top.
            while(!dmst.empty() && dmst.top() <= nums2[i])
                dmst.pop();
            
            if(known_answers.count(nums2[i]))
                if(dmst.empty())
                    known_answers[nums2[i]] = -1;
                else
                    known_answers[nums2[i]] = dmst.top();
        
            // Since stack is either empty or contains an element greater than current at its top,
            // we can simply push it to the top.
            dmst.push(nums2[i]);
        }

        std::vector<int> ret;

        for(int n : nums1)
            ret.emplace_back(known_answers[n]);
        
        return ret;
    }
};