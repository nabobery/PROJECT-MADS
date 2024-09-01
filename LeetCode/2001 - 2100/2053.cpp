// 2053. Kth Distinct String in an Array

// Solution 1 using  map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        vector<int> dis;
        int n = arr.size();
        for(int i = 0; i < n;i++){
            if(!mp.count(arr[i])) mp[arr[i]] = i;
            else mp[arr[i]] = -1;
        }
        for(auto it : mp) if(it.second != -1) dis.push_back(it.second);
        if(dis.size() < k) return "";
        sort(dis.begin(), dis.end());
        return arr[dis[k-1]];
    }
};
