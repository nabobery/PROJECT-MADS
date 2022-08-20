#include <iostream>

using namespace std;

int arr[] = {1,2,4,8,16,32};

int main() {
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a >= b){
            if(a % b != 0) cout<<"NO\n";
            else{
                bool flag = false;
                for(int i = 0; i < 6;i++){
                    if(arr[i] == a/b){
                        flag = true;
                        break;
                    }
                }
                if(flag) cout<<"YES\n";
                else cout<<"NO\n";
            }
            
        }
        else{
            if(b % a != 0) cout<<"NO\n";
            else{
                bool flag = false;
                for(int i = 0; i < 6;i++){
                    if(arr[i] == b/a){
                        flag = true;
                        break;
                    }
                }
                if(flag) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
        
    }
	return 0;
}
