class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0; 
        int r=heights.size()-1;
        int ans =0;
        int currwater =0;
        while(l<r){
            currwater = min(heights[l], heights[r]) * (r-l);
            ans = max(currwater, ans);

            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
