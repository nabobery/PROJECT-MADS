#include <iostream>
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int min = a < b ? a : b;
    for(int i = 0; i < min;i++){
        cout<<"10";
    }
    if(a != b){
        if(a == min){
            for(int i = 0; i < b-a;i++) cout<<"1";
        }
        else{
            for(int i = 0; i < a-b;i++) cout<<"0";
        }
    }
    cout<<"\n";
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




