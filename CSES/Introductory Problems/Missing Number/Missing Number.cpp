// Introductory Problems : Missing Number
#include <iostream>
using namespace std;

int main(){
    int n,x;
    long long sum = 0;
    cin >> n;
    for(int i = 0; i < n - 1;i++){
        cin >> x;
        sum += x;
    }
    long long result = ((long long)(n)*(n+1)/2) - sum;
    cout<<result<<"\n";
    return 0;
}

