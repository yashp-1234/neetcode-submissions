class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n2 = s2.size();
        int n1 = s1.size();
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        for(int i=0; i<n1; i++){
            mpp1[s1[i]]++;
        }
        for(int i=0; i<n2; i++){
            if(mpp1.count(s2[i]) != 0){
                for(int j=0; j<n1; j++){
                    if(i+j < n2){
                        mpp2[s2[i+j]]++;
                    }
                }
                if(mpp1 == mpp2){
                    return true;
                }
                else{
                    mpp2.erase(mpp2.begin(), mpp2.end());
                }
            }
        }
        return false;
    }
};
