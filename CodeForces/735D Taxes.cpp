#include <iostream>
#include <cmath>

using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
 
int nearest_prime(int n) {
    int prime = 0;
    for (int i = n-1; i >= 2; i--) {
        if (is_prime(i)) {
            prime = i;
            break;
        }
    }
    return prime;
}
 
void solve(){
    int n;
    cin >> n;
    //if the number is prime
    if(is_prime(n)) cout<<"1\n";
    // By Goldbach’s conjecture Every even number can be written as sum of 2 primes and as primes have the least maximum divisor which is 1 we choose to divide numbers into primes
    else if(n%2 == 0) cout<<"2\n";
    else{
        if(n - nearest_prime(n) == 2) cout<<"2\n";
        // By Goldbach’s conjecture
        else cout<<"3\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}