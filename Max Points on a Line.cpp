/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool cmp(const Point &a, const Point &b){
    return (long long)a.x*b.y<(long long)a.y*b.x;
}
class Solution {
public:
    bool same(const Point &a, const Point &b){
        return (long long)a.x*b.y==(long long)a.y*b.x;
    }
    int maxPoints(vector<Point> &points) {
        if (points.size()==0) return 0;
        int maxpt = 1;
        for (auto o : points){
            vector<Point> a;
            int zero = 0;
            for (auto p : points){
                if (p.x == o.x && p.y == o.y){
                    zero++;
                    continue;
                }
                Point r(p.x-o.x, p.y-o.y);
                if (r.y<0 || (r.y==0 && r.x<0)){
                    r.x *=-1;
                    r.y *=-1;
                }
                a.push_back(r);
            }
            maxpt = max(maxpt, zero);
            if (a.size() == 0) continue;
            sort(a.begin(), a.end(), cmp);
            for (int i = 0, j = 0; i<a.size(); i=j){
                while (j<a.size() && same(a[i], a[j])){
                    j++;
                }
                maxpt = max(maxpt, zero + j-i);
            }
        }
        return maxpt;
    }
};
