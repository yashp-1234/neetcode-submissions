#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void makeCombinations(int i, const vector<string>& dialpad, const string& digits, string& currCom, vector<string>& ans){
        if(i == digits.size()){
            ans.push_back(currCom);
            return;
        }
        int currDigit = digits[i] - '0';
        for(char c : dialpad[currDigit - 2]){
            currCom.push_back(c);
            makeCombinations(i+1, dialpad, digits, currCom, ans);
            currCom.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        const vector<string> dialpad = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string currCom;
        makeCombinations(0, dialpad, digits, currCom, ans);
        return ans;
    }
};

