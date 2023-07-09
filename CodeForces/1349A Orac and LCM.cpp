#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
 
void solve(){
    int n, ma = -1;
    cin >> n;
    vector<int> primes;
    ll result = 1;
    int counter[n], a[n];
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < n;i++){
        cin >> a[i];
        ma = max(a[i], ma);
    }
    for(int i = 2; i <= ma;i++){
        if (isPrime(i)) primes.push_back(i);
    }
    for(int i = 0; i < primes.size();i++){
        int k = n, mi = 1e6, smi = 1e6;
        for(int j = 0; j < n;j++){
            int temp = a[j];
            while(temp % primes[i] == 0){
                counter[j]++;
                temp /= primes[i];
            }
            if(counter[j] == 0) k--;
            if(k <= n-2) break;
        }
        if(k >= n-1){
            for(int j = 0; j < n;j++){
                if (counter[j] < mi) {
                    smi = mi;
                    mi = counter[j];
                } else if (counter[j] < smi) {
                    smi = counter[j];
                }
            }
            result *= pow(primes[i], smi);
        }
        memset(counter, 0, sizeof(counter));
    }
    cout<<result<<"\n";
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