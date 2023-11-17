// 1980. Find Unique Binary String

// Solution 1 - Brute Force
// Convert all binary strings to decimal and check if it is present in the set
// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
    int convertBinToDeci(string s){
        int res = 0, n = s.size();
        for(int i = 0; i < n;i++){
            if(s[i] == '1')
                res += (1 << (n-1-i));
        }
        return res;
    }
    string convertDeciToBin(int n, int sz){
        string res(sz, '0');
        int p = sz-1;
        while(n){
            if(n%2) res[p--] = '1';
            else res[p--] = '0';
            n /= 2;
        }
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> s;
        for(auto num : nums){
            s.insert(convertBinToDeci(num));
        }
        for(int i = 0;  i < 1 << nums.size(); i++){
            if(!s.count(i))
                return convertDeciToBin(i, nums.size());
        }
        return "";
    }
};

// Solution 2 - Generate binary strings recursively and check if it is present in the th given vector
// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
    int n;
    unordered_set<string> st;
    string generate(string s){
        if(s.size() == n){
            if(!st.count(s))
                return s;
            return "";
        }
        string res = generate(s + "0");
        if(res.size() > 0)
            return res;
        return generate(s + "1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for(auto num : nums)
            st.insert(num);
        return generate("");
    }
};

// Solution 3 - Randomly generate binary strings and check if it is present in the given vector
// Time Complexity - O(inf)
// Space Complexity - O(n)
class Solution {
public:
    unordered_set<int> st;
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(auto num : nums)
            st.insert(stoi(num, 0, 2));
        while(true){
            int num = rand() % (1 << n);
            if(!st.count(num))
                return bitset<16>(num).to_string().substr(16-n);
        }
        return "";
    }
};

// Solution 4 - Cantor's Diagonal Argument
// Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        for(int i = 0; i < n; i++){
            res += (nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }
};
