#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 1) cout<<"FastestFinger\n";
    else if(n %2) cout<<"Ashishgup\n";
    else{
        int temp = n, even = 0, odd = 0;
        while (temp % 2 == 0)
        {
            even++;
            temp = temp/2;
        }
        for (int i = 3; i <= sqrt(temp); i = i + 2)
        {
            while (temp % i == 0)
            {
                odd++;
                temp = temp/i;
            }
        }
        if (temp > 2) odd++;
        if(odd == 0){
            if(even == 1) cout<<"Ashishgup\n";
            else cout<<"FastestFinger\n";
        }
        else if(even == 1){
            if(odd == 1) cout<<"FastestFinger\n";
            else cout<<"Ashishgup\n";
        }
        else if(even > 1) cout<<"Ashishgup\n";
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



