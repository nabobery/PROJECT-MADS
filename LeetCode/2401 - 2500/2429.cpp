// 2429. Minimize XOR

// Solution 1 using Bit Manipulation and Greedy
// Time Complexity: O(n * log(max(a, b)))
// Space Complexity: O(1)
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> bits1(num1), bits2(num2);
        int cnt1 = bits1.count(), cnt2 = bits2.count();
        if(cnt1 == cnt2) return num1;
        if(cnt1 > cnt2){
            int rem = cnt1 - cnt2;
            for(int i = 0; i < bits1.size(); i++){
                if(rem <= 0) break;
                if(bits1[i] == 1){
                    bits1.reset(i);
                    rem--;
                }
            }
        }
        else{
            int rem = cnt2 - cnt1;
            for(int i = 0; i < bits1.size();i++){
                if(rem <= 0) break;
                if(bits1[i] == 0){
                    bits1.set(i);
                    rem--;
                }
            }
        }
        return (int)(bits1.to_ulong());
    }
};