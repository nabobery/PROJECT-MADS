//149. Max Points on a Line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 1;
        int result = 2;
        for(int i = 0; i < n;i++){
            unordered_map<double,int> mp;
            for(int j = 0; j < n;j++){
                if(j != i) mp[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
            }
            for(auto it : mp){
                result = max(result, it.second + 1);
            }
        }
        return result;
    }
};