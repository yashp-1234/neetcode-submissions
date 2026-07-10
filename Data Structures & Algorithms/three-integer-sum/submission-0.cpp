class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l=0;
        int r = 0;
        set<vector<int>> ans;
        int currsum = 0;
        for(int i=0; i<n-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l=i+1;
            r=n-1;
            while(l<r){
                currsum = nums[i] + nums[l] + nums[r];
                if(currsum > 0){
                    r--;
                }
                else if(currsum < 0){
                    l++;
                }
                else{
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>> vec(ans.begin(), ans.end());
        return vec;
    }
};
