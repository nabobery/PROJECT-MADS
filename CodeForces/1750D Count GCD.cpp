#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int mod = 998244353;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> primes;

// function to get prime factors of n
void getprimes(int n){
    int x = 2;
    while( x*x <= n){
        bool flag = false;
        while(n%x == 0){
            n /= x;
            flag = true;
        }
        if(flag) primes.push_back(x);
        x++;
    }
    if(n != 1) primes.push_back(n);
}

void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    bool flag = true;
    cin >> arr[0];
    for(int i = 1; i < n;i++){
        cin >> arr[i];
        if(arr[i-1] % arr[i] != 0) flag = false;
    }
    // if any ai/ai+1 not divisble then there's no possible b such that gcd(b1,b2...bi) = ai
    if(!flag) cout<<"0\n";
    // else if b is possible
    else{
        primes.clear();
        // get prime factors of a[0] as every other
        getprimes(arr[0]);
        // we check for all ai for i > 1 as for a1 we can onl select a1 therefore b1 = a1
        vector<int> res(n-1,0);
        // we need to choose x such that gcd(ai−1,x) = ai. Let's take x=ai*k => gcd((ai−1/ai)*ai,ai*k) = ai => gcd((ai−1/ai),k) = 1
        for(int i = 0; i < n-1;i++){
            // (ai−1/ai)
            int lhs = arr[i]/arr[i+1];
            //  k ≤ m/ai as m is the largest number possible
            int l = m/arr[i+1];
            // finding the prime factors of lhs
            vector<int> left;
            for(auto it : primes){
                if(lhs % it == 0){
                    left.push_back(it);
                }
            }
            int size = left.size();
            int temp = 0;
            // inclusion-exclusion principle
            for (int mask = 0; mask < (1 << size); ++mask)
            {
                int prod = 1;
                int cnt = 0;
                for (int j = 0; j < size; j++)
                {
                    // we include this prime
                    if (mask & (1 << j))
                    {
                        prod *= left[j];
                        cnt++;
                    }
                }
                // if even parity
                if (cnt % 2 == 0)
                {
                    temp += l / prod;
                }
                // if odd parity
                else
                {
                    temp -= l / prod;
                }
            }
            res[i] = temp;
        }
        ll result = 1;
        // calculating result by multiplying number of ways we can choose a2....an
        for(auto i : res){
            result *= i;
            result %= mod;
        }
        cout<<result<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}






