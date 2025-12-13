// 3606. Coupon Code Validator

// Solution 1: Simple and Straightforward (filtering + Sorting)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    bool isValidCode(string code){
        for(auto&ch : code){
            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch == '_')) continue;
            return false;
        }
        return !code.empty();
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        unordered_set<string> validBusinesses = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<pair<string,string>> bussinessLineAndCode;
        for(int i = 0; i < n;i++){
            if(!isActive[i]) continue;
            if(!validBusinesses.count(businessLine[i])) continue;
            if(!isValidCode(code[i])) continue;
            bussinessLineAndCode.push_back({businessLine[i], code[i]});
        }
        sort(bussinessLineAndCode.begin(), bussinessLineAndCode.end());
        vector<string> res(bussinessLineAndCode.size());
        for(int i = 0; i < res.size();i++){
            res[i] = bussinessLineAndCode[i].second;
        }
        return res;
    }
};