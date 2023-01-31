// 1137. N-th Tribonacci Number

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1 || n==2) return 1;
        else{
            int t1 = 0, t2 = 1, t3 = 1, ans;
            for(int i = 3; i <= n;i++){
                ans = t1 + t2 + t3;
                t1 = t2;
                t2 = t3;
                t3 = ans;
            }
            return ans;
        }
    }
};
