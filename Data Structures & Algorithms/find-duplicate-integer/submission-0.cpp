class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> myset;
        for(int i=0; i<n; i++){
            if(myset.find(nums[i]) == myset.end()){
                myset.insert(nums[i]);
            }
            else{
                return nums[i];
            }
        }
        return 0;
    }
};
