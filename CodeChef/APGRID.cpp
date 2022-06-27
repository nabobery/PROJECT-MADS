#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t,n,m,d,c;
    cin >> t;
    while(t--){
        cin >> n >> m;
        bool flag = false;
        if(m > n){
            swap(n,m);
            flag = true;
        }
        d = m + n;
        c = m;
        int arr[n][m];
        arr[0][0] = 1;
        for(int i = 1; i < m;i++){
            arr[0][i] = arr[0][i-1] + d;
        }
        for(int i = 1; i < n;i++){
            arr[i][0] = arr[i-1][0] + c;
        }
        d--;
        for(int i = 1;i < n;i++){
            for(int j = 1; j < m;j++){
                arr[i][j] = arr[i][j-1] + d;
            }
            d--;
        }
        if(!flag){
            for(int i = 0; i < n;i++){
                for(int j = 0; j < m;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else{
            for(int i = 0; i < m;i++){
                for(int j = 0; j < n;j++){
                    cout<<arr[j][i]<<" ";
                }
                cout<<"\n";
            }
        }
        
    }
	return 0;
}
