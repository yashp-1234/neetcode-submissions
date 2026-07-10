class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool fir = false;
        bool sec = false;
        bool thi = false;
        for(int i=0; i<n; i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                continue;
            }
            if(triplets[i][0] == target[0]){
                fir = true;
            }
            if(triplets[i][1] == target[1]){
                sec = true;
            }
            if(triplets[i][2] == target[2]){
                thi = true;
            }
        }

        if(fir == false || sec == false || thi == false){
            return false;
        }
        else{
            return true;
        }
    }
};
