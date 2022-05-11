#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

int arr[2001], c[2001];

int main() {
    int t,n,K;
    cin >> t;
    ordered_set s;
    for(int i = 0; i < t;i++){
        cin >> n >> K;
        for(int j = 0; j < n;j++) cin >> arr[j];
        int result = 0;
        for(int j = 0; j < n;j++){
            s.clear();
            memset(c,0,sizeof(c));
            for(int k = j; k < n;k++){
                s.insert({arr[k],k});
                c[arr[k]]++;
                int l = k - j + 1;
                int m = (K+l-1)/l;
                int f = (K+m-1)/m;
                auto itr = s.find_by_order(f-1);
                int x = itr->first;
                if(c[c[x]]){
                    result++;
                } 
            }
        }
        cout<<result<<"\n";
    }
	return 0;
}
