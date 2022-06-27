#include <iostream>
#include <map>

using namespace std;

int main() {
    int t,n,x;
    cin >> t;
    while(t--){
        cin >> n;
        int temp = 0, max;
        map<int,int> mp;
        for(int i = 0; i < n;i++){
            cin >> x;
            mp[x]++;
            if(mp[x] > temp){
                max = x;
                temp = mp[x];
            }
        }
        int result = 0;
        for(auto itr: mp){
            if(itr.first != max) result += itr.second;
        }
        cout<<result<<"\n";
    }
	return 0;
}
