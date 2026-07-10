class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        multiset<double> myset;

        for (int i = 0; i < n; i++) {
            myset.insert((double)nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            myset.insert((double)nums2[i]);
        }

        auto it = myset.begin();
        if (total % 2 == 1) {
            advance(it, total / 2);
            return *it;
        } else {
            auto it1 = myset.begin();
            auto it2 = myset.begin();
            advance(it1, total / 2 - 1);
            advance(it2, total / 2);
            return (*it1 + *it2) / 2.0;
        }
    }
};
