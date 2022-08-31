#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    int result = 0;
    for(int i = 0; i < n;i++){
        // if ai is 0 it's a rest day
        if(arr[i] == 0) result++;
        // if ai is 1 or 2, we check the prev to see if it's possible to do it or not,if not then increment result
        else if(arr[i] == 1 || arr[i] == 2){
            if(i > 0 && arr[i] == arr[i-1]){
                arr[i] = 0;
                result++;
            }
        }
        // if ai is 3 then just change the current one based on prev to get min rest days
        else if(i > 0 && i < n-1 && (arr[i-1] == 1 || arr[i-1] == 2)){
            if(arr[i-1] == 1) arr[i] = 2;
            else arr[i] = 1;
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




