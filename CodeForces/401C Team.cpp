#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n, m;
    cin >> n >> m;
    int diff = m - n;
    if(diff > 0){
        if(m > (2*n + 2)) cout<<"-1\n";
        else{
            int p = n, q = m;
            for(int i = 0; i < diff && p > 0;i++){
                cout<<"110";
                p--;
                q -= 2;
            }
            while(p > 0 || q > 0){
                if(q > 0){
                    cout<<"1";
                    q--;
                }
                if(p > 0){
                    cout<<"0";
                    p--;
                }
            }
            cout<<"\n";
        }
    }
    else{
        if(diff == 0){
            for(int i = 0; i < n;i++) cout<<"01";
            cout<<"\n";
        }
        else if(diff == -1){
            for(int i = 0; i < m;i++) cout<<"01";
            cout<<"0\n";
        }
        else cout<<"-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


