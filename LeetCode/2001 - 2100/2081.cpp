// 2081. Sum of k-Mirror Numbers

// Solution 1 using Brute Force
// Time Complexity: O(n * k), where n is the number of k-mirror numbers and k is the base.
// Space Complexity: O(1)
class Solution {
public:
    bool check(long num, int k){
        vector<int> digits;
        while(num > 0){
            digits.push_back(num%k);
            num /= k;
        }
        int l = 0, r = digits.size()-1;
        while(l < r){
            if(digits[l] != digits[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long res = 0;
        for(int sz = 1; sz <= 18;sz++){
            if(sz %2 == 1){
                long l = pow(10, sz/2), r = pow(10, sz/2+1);
                for(int i = l ; i < r;i++){
                    long num10 = i*l, ti = i/10, base = l;
                    while(base > 1){
                        num10 += ((base/10)* (ti%10));
                        ti /= 10;
                        base /= 10;
                    }
                    if(check(num10, k)){
                        res += num10;
                        n--;
                        if(!n) break;
                    }
                }
                if(!n) break;
            }
            else{
                long l = pow(10, sz/2 - 1), r = pow(10, sz/2);
                for(int i = l ; i < r;i++){
                    long num10 = i*r, ti = i, base = r;
                    while(base > 1){
                        num10 += ((base/10)* (ti%10));
                        ti /= 10;
                        base /= 10;
                    }
                    if(check(num10, k)){
                        res += num10;
                        n--;
                        if(!n) break;
                    }
                }
                if(!n) break;
            }
        }
        return res;
    }
};