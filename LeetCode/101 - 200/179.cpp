// 179. Largest Number

//Solution 1 using Custom Comparator
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    static bool comparator(int a, int b){
        string p = to_string(a), q = to_string(b);
        int m = p.size(), n = q.size();
        for(int i = 0; i < max(m, n)*2;i++)
            if(p[i%m] != q[i%n]) return p[i%m] > q[i%n];
        return m < n;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), comparator);
        for(int num : nums)
            res += to_string(num);
        return (res.find_first_not_of('0') == string::npos) ? "0" : res;
    }
};

// Solution 2 using Lambda Function
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int& a, int& b){
            string p = to_string(a), q = to_string(b);
            return p + q > q + p;
        });
        for(int num : nums)
            res += to_string(num);
        return (res.find_first_not_of('0') == string::npos) ? "0" : res;
    }
};