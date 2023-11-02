// 1356. Sort Integers by The Number of 1 Bits

// Solution 1 - Using inbuilt sort function and custom comparator
class Solution {
public:
    static int bits(int a){
        int cnt = 0;
        while(a){
            if(a%2) cnt++;
            a /= 2;
        }
        return cnt;
    }
    static bool comparator(int a, int b){
        int p = bits(a), q = bits(b);
        if(p != q) return p < q;
        return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
};

// Solution 2 - Using inbuilt sort function
class Solution {
public:
    int bits(int a){
        int cnt = 0;
        while(a){
            if(a%2) cnt++;
            a /= 2;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;
        for(int i=0; i<arr.size(); i++){
            v.push_back({bits(arr[i]), arr[i]});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<v.size(); i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};


