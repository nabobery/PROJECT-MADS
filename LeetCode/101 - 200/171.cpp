// 171. Excel Sheet Column Number
// naive O(n) solution
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        if(n == 1) return (columnTitle[0] - 'A' + 1);
        int base = 1;
        int result = 0;
        for(int i = n-1; i > -1;i--){
            int temp = columnTitle[i] - 'A' + 1;
            temp *= base;
            result += temp;
            if(i != 0) base *= 26;
        }
        return result;
    }
};
