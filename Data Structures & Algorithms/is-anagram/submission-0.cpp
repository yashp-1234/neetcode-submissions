class Solution {
public:
    bool isAnagram(string s, string t) {
         unordered_map<char, int> smpp;
        unordered_map<char, int> tmpp;
        int n = s.size();
        int m = t.size();
        for(int i=0; i<n; i++){
            smpp[s[i]]++;
        }
        for(int i=0; i<m; i++){
            tmpp[t[i]]++;
        }
        if(smpp == tmpp){
            return true;
        }
        else{
            return false;
        }
    }
};
