class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> myset;
        for (int i = 0; i < n; i++) {
            myset.insert(nums[i]);
        }
        if( myset.size() == 0)  {return 0;}
        if( myset.size() == 1)  {return 1;}

        int maxlen = 1;
        int ans = 0;
        // bool cont = false;
        auto prev = myset.begin();
        auto curr = next(myset.begin());

        for (; curr != myset.end(); ++curr, ++prev) {
            cout << "Prev: " << *prev << ", Curr: " << *curr << endl;

            if (*curr == *prev + 1) {
                maxlen++;
            } else {
                maxlen = 1;
            }
            ans = max(maxlen, ans);
        }
        return ans;
    }
};
