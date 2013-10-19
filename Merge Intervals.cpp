/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b){
    return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int n = intervals.size();
        if (n == 0) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        int l = intervals[0].start, r = intervals[0].end;
        for (int i = 1; i<n; i++){
            Interval &x = intervals[i];
            if (r<x.start){
                res.push_back(Interval(l, r));
                l = x.start, r = x.end;
            }else{
                r = max(r, x.end);
            }
        }
        res.push_back(Interval(l, r));
        return res;
    }
};

