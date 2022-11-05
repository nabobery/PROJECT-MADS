#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// the nobles who are not vulnerable  or have everyone weaker than them are the ones that survive at the end because they're the ones who kill all their friends weaker than them
void solve(){
    int n, m,x,y,q,t;
    cin >> n >> m;
    vector<int> edges(n+1,0), weaker(n+1,0);
    for(int i = 0; i < m;i++){
        cin >> x >> y;
        edges[x]++;
        edges[y]++;
        if(x > y) weaker[x]++;
        else weaker[y]++;
    }
    int result = 0;
    for(int j = 1; j <= n;j++){
        if(edges[j] == weaker[j]) result++;
    }
    cin >> q;
    for(int i = 0; i < q;i++){
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            int e1 = edges[x], e2 = edges[y], w1 = weaker[x], w2 = weaker[y];
            edges[x]++;
            edges[y]++;
            if(x > y) weaker[x]++;
            else weaker[y]++;
            if(e1 == w1 && edges[x] != weaker[x]) result--;
            if(e2 == w2 && edges[y] != weaker[y]) result--;
        }
        else if(t == 2){
            cin >> x >> y;
            int e1 = edges[x], e2 = edges[y], w1 = weaker[x], w2 = weaker[y];
            edges[x]--;
            edges[y]--;
            if(x > y) weaker[x]--;
            else weaker[y]--;
            if(e1 == w1 && edges[x] != weaker[x]) result--;
            else if(e1 != w1 && edges[x] == weaker[x]) result++;
            if(e2 == w2 && edges[y] != weaker[y]) result--;
            else if(e2 != w2 && edges[y] == weaker[y]) result++;
        }
        else{
            cout<<result<<"\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






