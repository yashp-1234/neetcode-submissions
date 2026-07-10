#include <unordered_map>
#include <vector>
using namespace std;

class CountSquares {
private:
    unordered_map<int, unordered_map<int,int>> pts;
public:
    CountSquares() { }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        pts[x][y]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        auto itRow = pts.find(x1);
        if (itRow == pts.end()) return 0;

        // helper to safely get count without creating entries
        auto getCount = [&](int x, int y) -> int {
            auto itx = pts.find(x);
            if (itx == pts.end()) return 0;
            auto ity = itx->second.find(y);
            if (ity == itx->second.end()) return 0;
            return ity->second;
        };

        for (auto &p : itRow->second) {
            int y2 = p.first;
            int cnt = p.second;
            int side = y2 - y1;
            if (side == 0) continue;

            int x3 = x1 + side;
            int x4 = x1 - side;

            res += cnt * getCount(x3, y1) * getCount(x3, y2);
            res += cnt * getCount(x4, y1) * getCount(x4, y2);
        }

        return res;
    }
};