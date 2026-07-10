class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int r = k - 1;
        int l = 0;
        multiset<int, greater<int>> myset(nums.begin(), nums.begin() + k);
        vector<int> ans;
        ans.push_back(*myset.begin());
        while (r + 1 < n) {
            auto it = myset.find(nums[l]); 
            if (it != myset.end()) {
                myset.erase(it); 
            }
            l++;
            r++;
            myset.insert(nums[r]);
            if (nums[r] > *myset.begin()) {
                ans.push_back(nums[r]);
            } else {
                ans.push_back(*myset.begin());
            }
        }
        return ans;
    }
};
