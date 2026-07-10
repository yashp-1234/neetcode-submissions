#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            vector<int> empty_ans;
            return empty_ans;
        }
        int n = matrix[0].size();

        vector<vector<int>> vis (m, vector<int> (n, 0));
        int i = 0;
        int j = 0;
        // right -> 0, down -> 1, left -> 2, up -> 3
        int dir = 0;
        vector<int> ans;
        int u = 0;
        int d = m - 1;
        int l = 0;
        int r = n - 1;

        // Continue until we've collected all elements
        while (ans.size() < (size_t)(m * n)) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = 1;

            if (dir == 0) { // moving right
                if (j == r) {
                    // reached right boundary, turn down
                    dir = 1;
                    u = u + 1;
                    // move down if there are still elements left to take
                    if (ans.size() < (size_t)(m * n)) {
                        i = i + 1;
                    }
                } else {
                    // keep moving right
                    j = j + 1;
                }
            } else if (dir == 1) { // moving down
                if (i == d) {
                    // reached bottom boundary, turn left
                    dir = 2;
                    r = r - 1;
                    if (ans.size() < (size_t)(m * n)) {
                        j = j - 1;
                    }
                } else {
                    // keep moving down
                    i = i + 1;
                }
            } else if (dir == 2) { // moving left
                if (j == l) {
                    // reached left boundary, turn up
                    dir = 3;
                    d = d - 1;
                    if (ans.size() < (size_t)(m * n)) {
                        i = i - 1;
                    }
                } else {
                    // keep moving left
                    j = j - 1;
                }
            } else if (dir == 3) { // moving up
                if (i == u) {
                    // reached top boundary, turn right
                    dir = 0;
                    l = l + 1;
                    if (ans.size() < (size_t)(m * n)) {
                        j = j + 1;
                    }
                } else {
                    // keep moving up
                    i = i - 1;
                }
            }
        }

        return ans;
    }
};

