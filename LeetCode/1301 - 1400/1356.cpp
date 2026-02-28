// 1356. Sort Integers by The Number of 1 Bits

// Solution 1: Using custom comparator
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if we ignore the space used by the sorting algorithm
class Solution {
public:
    int countBits(int n) {
        int cnt = 0;
        while (n) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int bitA = countBits(a);
            int bitB = countBits(b);
            if (bitA != bitB) {
                return bitA < bitB;
            }
            return a < b;
        });
        return arr;
    }
};

// Solution 2: Using a vector of pairs to store the count of bits and the original number
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) due to the additional vector of pairs
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


