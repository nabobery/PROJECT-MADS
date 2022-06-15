#include <iostream>
#include<cmath>

using namespace std;

int numberOfDivisors(int n){
    int res = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) res++;
            else res += 2;
        }
    }
    return res;
}

int main() {
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int diff = a - b;
        if(diff < 0) diff = -diff;
        cout<<numberOfDivisors(diff)<<"\n";
    }
	return 0;
}
