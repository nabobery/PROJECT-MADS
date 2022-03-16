// 1200. Minimum Absolute Difference
// My naive solution using sort + 2 traversals
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        int min = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] < min)
                min = arr[i + 1] - arr[i];
        }
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] ==  min){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i + 1]);
                result.push_back(temp);
            }
        }
        return result;
    }
};

// memory efficient and sort + 1 treversal solution
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        int min = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++){
            int curr = arr[i + 1] - arr[i];
            if(curr == min)
                result.push_back({arr[i], arr[i + 1]});
            else if(curr < min){
                result = {};
                result.push_back({arr[i], arr[i + 1]});
                min = curr;                
            }
        }
        
        return result;
    }
};
