class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::sort(nums.begin(), nums.end()); // sort first

        const int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // skip duplicate first element
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});

                    // skip duplicates for l and r
                    int left_val = nums[l], right_val = nums[r];
                    while (l < r && nums[l] == left_val) ++l;
                    while (l < r && nums[r] == right_val) --r;

                } else if (sum < 0) {
                    ++l; // need bigger number
                } else {
                    --r; // need smaller number
                }
            }
        }

        return ret;
    }
};