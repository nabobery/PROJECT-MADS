// 739. Daily Temperatures
/* TLE Solution
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
        
    }
};
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;
        for(int i = 0; i < n;i++){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return result;
        
    }
};