// 986. Interval List Intersections
// Slow Solution
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0 , j = 0;
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> result;
        while(i < n && j < m){
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if(start <= end){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                result.push_back(temp);
            }
            if(firstList[i][1] < secondList[j][1])
                i++;
            else 
                j++;
        }
        return result;        
    }
};