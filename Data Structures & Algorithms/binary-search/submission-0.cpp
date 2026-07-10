class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int mid = 0;
        while(l<=h){
            mid = (l+h)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return -1; 
    }
};