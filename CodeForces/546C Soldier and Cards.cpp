#include <iostream>
#include <queue>
using namespace std;

#pragma GCC optimize("Ofast")

// maximum number of war states possible is (n+1)! combinations as we have n! ways of arranging card and n+1 ways of dividing them between 2 players.
int maxNumberOfFights(int n){
    int result = 1;
    for(int i = 2; i <= (n+1);i++) result *= i;
    return result;
}

void solve(){
    int n, k,x,l,counter = 0;
    cin >> n;
    queue<int> stk1, stk2;
    cin >> k;
    for(int i = 0; i < k;i++){
        cin >> x;
        stk1.push(x);
    }
    cin >> k;
    for(int i = 0; i < k;i++){
        cin >> x;
        stk2.push(x);
    }
    l = maxNumberOfFights(n);
    while(counter <= l){
        int t1 = stk1.front(), t2 = stk2.front();
        stk1.pop();
        stk2.pop();
        if(t1 > t2){
            stk1.push(t2);
            stk1.push(t1);
        }
        else{
            stk2.push(t1);
            stk2.push(t2);
        }
        counter++;
        if(stk1.empty()){
            cout<<counter<<" 2\n";
            break;
        }
        if(stk2.empty()){
            cout<<counter<<" 1\n";
            break;
        }
    }
    if(counter > l) cout<<"-1\n";
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




