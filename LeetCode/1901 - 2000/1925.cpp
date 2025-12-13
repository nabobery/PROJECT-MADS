// 1925. Count Square Sum Triples

// Solution 1: Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(1)
class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n;j++){
                for(int k = 1; k <= n;k++){
                    if(i*i + j*j == k*k) res++;
                }
            }
        }
        return res;
    }
};

// Solution 2: Optimized using square root
// Time Complexity: O(n^2)
// Space Complexity O(1)
class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int a = 1; a <= n;a++){
            for(int b = 1; b <= n;b++){
                int cSq = a*a + b*b, c = sqrt(cSq);
                if(c <= n && c*c == cSq) res++;
            }
        }
        return res;
    }
};