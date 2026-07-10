class Solution {
public:

    void makePurmutations(int n, vector<int>& nums, map<int, int>& mpp, vector<vector<int>>& ans, vector<int>& prtm){
        if(prtm.size() == n){
            ans.push_back(prtm);
            return;
        }

        for(int i=0; i<n; i++){
            if(mpp[i] == 0){
                prtm.push_back(nums[i]);
                mpp[i] = 1;
                makePurmutations(n, nums, mpp, ans, prtm);
                mpp[i] = 0;
                prtm.pop_back();
            }
        }
    };
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        vector<vector<int>> ans;
        vector<int> prtm;
        for(int i=0; i<n; i++){
            mpp[i] = 0;
        }
        makePurmutations(n, nums, mpp, ans, prtm);
        return ans;
    }
};