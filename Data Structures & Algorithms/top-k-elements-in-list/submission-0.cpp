class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        // for(auto it : mpp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<endl;

        vector<pair<int, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

        // for(int i=0; i<vec.size(); i++){
        //     cout<<vec[i].first<<" " << vec[i].second<< endl;
        // }

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
