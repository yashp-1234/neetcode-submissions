class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for(int i=0;i<n;i++){
            if(65 <= s[i] && s[i]<= 90){
                str+= (s[i]+32);
            }
            else if(97 <= s[i] && s[i]<= 122){
                str+=(s[i]);
            }
            else if(48 <= s[i] && s[i]<= 57){
                str+=(s[i]);
            }
            else{
                continue;
            }
        }

        int l = 0;
        int r = str.size()-1;

        for(l; l<str.size()/2; l++){
            if(str[l] != str[r]){
                return false;
            }
            r--;
        }
        return true;
    }
};
