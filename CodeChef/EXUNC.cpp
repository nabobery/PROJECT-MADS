#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n+1];
    set <int> s;
    for(int i = 1; i <= n;i++) cin >> arr[i];
    s.insert(1);
    int d = arr[0], count;
    for(int i = 2; i <= n;i++){
        if(arr[i] % arr[i-1] != 0){
            s.insert(i);
        }
    }
    string str;
    for(int i = 0; i < q;i++){
        getline(cin >> ws, str);
        stringstream ss(str);
        ss >> d;
        if(d == 1){
            int k, x, temp;
            for(int j = 1 ;ss >> temp; j++){
                if(j == 1) k = temp;
                else x = temp;
            }
            arr[k] = x;
            s.insert(k);
            s.insert(k+1);
            if((k > 1) && (arr[k] % arr[k-1] == 0)){
                s.erase(k);
            } 
            if((k < n) && (arr[k+1] % arr[k] == 0)){
                s.erase(k+1);
            } 
        }
        else if(d == 2){
            int k;
            while(ss >> d) k = d;
            auto it = s.upper_bound(k);
            it--;
            cout<<*it<<"\n";
        }
    }
	return 0;
}
