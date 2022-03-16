// 452. Minimum Number of Arrows to Burst Balloons
// my naive solution O(nlog n) time and O(1) space
class Solution {
public:
    // sorting based on end points
    static bool comp(const vector<int> &a, const vector<int> &b){
        return (a[1] < b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int result = 1;
        sort(points.begin(),points.end(),comp);
        int end = points[0][1];
        for(int i = 1; i < points.size();i++){
            if(points[i][0] <= end){
                continue;
            }
            else{
                result++;
                end = points[i][1];
            }
        }
        return result;
    }
};


