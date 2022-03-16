// Introductory Problems : Bit Strings
#include "iostream"
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    int result = 1;
    for(int i = 0; i < n;i++){
        result = (2*result) % MOD;
    }
    cout<<result<<"\n";
    return 0;
}

