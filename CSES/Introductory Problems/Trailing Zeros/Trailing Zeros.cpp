// Introductory Problems : Trailing Zeros
#include "iostream"
using namespace std;

int main(){
    int n;
    cin >> n;
    int temp = n;
    int k = 0, l = 0;
    while(temp){
        k += temp/5;
        temp /= 5;
    }
    temp = n;
    while(temp){
        l += temp/2;
        temp /= 2;
    }
    int result = (k < l) ? k : l;
    cout<<result<<"\n";
    return 0;
}

