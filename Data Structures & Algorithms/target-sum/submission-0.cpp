class Solution {
public:
    unordered_map<long long, int> dp;

    int helper(int i, int n, vector<int>& nums, int rem) {
        if (i == n) {
            return rem == 0;
        }

        // Create a unique key from (i, rem)
        long long key = ((long long)i << 32) | (rem + 100000);

        if (dp.count(key)) {
            return dp[key];
        }

        int left  = helper(i + 1, n, nums, rem - nums[i]);
        int right = helper(i + 1, n, nums, rem + nums[i]);

        return dp[key] = left + right;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return helper(0, nums.size(), nums, target);
    }
};

