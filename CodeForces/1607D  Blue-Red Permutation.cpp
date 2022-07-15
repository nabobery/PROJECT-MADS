#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct element{
    int val;
    char color;
};

bool customCompare(element a, element b){
    if(a.color != b.color) return (a.color == 'B' && b.color == 'R');
    return a.val < b.val;
}

void solve(){
    int n;
    cin >> n;
    vector<element> elements(n);
    for(int i = 0; i < n;i++) cin >> elements[i].val;
    for(int i = 0; i < n;i++) cin >> elements[i].color;
    sort(elements.begin(),elements.end(), customCompare);
    bool flag = false;
    for(int i = 0; i < n;i++){
        int curr = i+1;
        if((elements[i].val >= curr && elements[i].color == 'B') || (elements[i].val <= curr && elements[i].color == 'R')) continue;
        else{
            flag = true;
            break;
        }
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
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


