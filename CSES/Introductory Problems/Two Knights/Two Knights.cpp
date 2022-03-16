// Introductory Problems : Two Knights
/*
Note that when we have two knights threatening each other, it actually forms either a 2×3 or 3×2 board. And for each of 2×3 and 3×2 boards,
there are 2 ways of placing two knights so that they threaten each other. So, what we should do is to count how many 2×3 and 3×2 squares on
 n×n board. For general n, the answer is (n−1)(n−2)+(n−2)(n−1)=2(n−1)(n−2)
And for each 2×3 and 3×2 board, there are 2 ways of placing the knights so that they threaten each other. Therefore, in total there are
2⋅2(n−1)(n−2)=4(n−1)(n−2)
ways of placing two knights so that they threaten each other. So what you are looking for is n^2*(n^2−1)/2−4(n−1)(n−2) or n^2C2 - 4(n−1)(n−2)
 */
#include "iostream"
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int result;
    for(int i = 1; i <= n;i++){
        if(i == 1){
            cout<<0<<"\n";
        }
        else{
            result = i*i;
            result = result*(result - 1)/2;
            result -= 4*(i-1)*(i-2);
            cout<<result<<"\n";
        }
    }
    return 0;
}