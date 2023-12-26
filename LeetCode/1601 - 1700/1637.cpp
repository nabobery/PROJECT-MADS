// 1637. Widest Vertical Area Between Two Points Containing No Points

// Solution 1 using sorting and comparing adjacent elements to get max width
// Time complexity: O(nlogn)
// Space complexity: O(logn)
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int result = 0;
        sort(points.begin(),points.end(), compare);
        for(int i = 1; i < points.size();i++){
            result = max(points[i][0]-points[i-1][0], result);
        }
        return result;
    }
};

// Solution 2 using set
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int result = 0;
        set<int> s;
        for(auto& point: points){
            s.insert(point[0]);
        }
        auto it = s.begin();
        auto it2 = s.begin();
        it2++;
        while(it2 != s.end()){
            result = max(result, *it2 - *it);
            it++;
            it2++;
        }
        return result;
    }
};

