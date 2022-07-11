#include <iostream>

using namespace std;

int main() {
    int t,x,n;
    cin >> t;
    while(t--){
        cin >> n;
        bool flag = false;
        long long int sum = 0;
        for(int i = 0; i < n;i++){
            cin >> x;
            if(x == 1) flag = true;
            if(x > 2) sum += (x-2);
        }
        if(flag) cout<<"CHEF\n";
        else{
            if((sum+2)%2 == 0) cout<<"CHEFINA\n";
            else cout<<"CHEF\n";
        }
    }
	return 0;
}
