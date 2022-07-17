#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    int arr[n], pos[n+2];
    pos[0] = 0;
    pos[n+1] = n + 1;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        pos[arr[i]] = i+1;
    }
    int rounds = 1, index = pos[1];
    for(int i = 2;i <= n; i++){
        if(pos[i] < index){
            rounds++;
        }
        index = pos[i];
    }
    int a,b;
    for(int i = 0; i < m;i++){
        cin >> a >> b;
        int x = arr[a-1], y = arr[b-1];
        if(pos[x-1] > pos[x]) rounds--;
        if(pos[x] > pos[x+1]) rounds--;
        if((y-1 != x) && pos[y-1] > pos[y]) rounds--;
        if((y+1 != x) && pos[y] > pos[y+1]) rounds--;
        swap(arr[a-1], arr[b-1]);
        swap(pos[x],pos[y]);
        if(pos[x-1] > pos[x]) rounds++;
        if(pos[x] > pos[x+1]) rounds++;
        if((y-1 != x) && pos[y-1] > pos[y]) rounds++;
        if((y+1 != x)&& pos[y] > pos[y+1]) rounds++;
        cout<<rounds<<"\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





