// 6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result;
        int n = s.size();
        int factor = 2*(numRows - 1);
        for(int i = 0; i < numRows;i++){
            int ind = i;
            while(ind < n){
                result += s[ind];
                if(i != 0 && i != numRows-1){
                    int t = factor - 2*i, sind = ind + t;
                    if(sind < n){
                        result += s[sind];
                    }
                }
                ind += factor;
            }
        }
        return result;
    }
};

