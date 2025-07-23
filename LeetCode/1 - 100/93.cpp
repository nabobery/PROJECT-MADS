// 93. Restore IP Addresses

class Solution {
public:
    vector<string> result;
    bool isValid(string s, int start, int length){
        if(s[start] == '0') return length == 1;
        if(length == 3) return s.substr(start,length) < "256";
        return true;
    }
    void helper(string s, int start, vector<int>& dots){
        int remlength = s.size() - start, remints = 4 - dots.size();
        if (remlength > remints * 3 || remlength < remints) {
            return;
        }
        if(dots.size() == 3){
            if (isValid(s, start, remlength)) {
                string temp;
                int last = 0;
                for (int dot : dots) {
                    temp.append(s.substr(last, dot));
                    last += dot;
                    temp.append(".");
                }
                temp.append(s.substr(start));
                result.push_back(temp);
            }
            return;
        }
        for(int i = 1; i <= 3;i++){
            dots.push_back(i);
            if(isValid(s,start,i)){
                helper(s,start+i,dots);
            }
            dots.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return result;
        vector<int> dots;
        helper(s,0,dots);
        return result;
    }
};