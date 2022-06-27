#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);   
}

int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        int Prefix[n + 2],Suffix[n + 2];
        for(int i = 0; i < n;i++) cin >> arr[i];
        Prefix[1] = arr[0];
        for (int i = 2; i <= n; i++) {
            Prefix[i] = gcd(Prefix[i - 1], arr[i - 1]);
        }
        Suffix[n] = arr[n - 1];
        for (int i = n - 1; i >= 1; i--) {
            Suffix[i] = gcd(Suffix[i + 1], arr[i - 1]);
        }
        int result = 0;
        for(int i = 1; i < n-1;i++){
            if(gcd(Prefix[i],Suffix[i+2]) != 1) result++;
        }
        if(Suffix[2] != 1) result++;
        if(Prefix[n-1] != 1) result++;
        cout<<result<<"\n";
    }
	return 0;
}
