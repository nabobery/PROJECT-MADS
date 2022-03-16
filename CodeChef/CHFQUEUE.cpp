#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	int MOD = 1000000007;
	for(int i = 0; i < n;i++){
	    cin >> arr[i];
	}
	long long int result = 1;
	stack<pair<int,int>> stk;
	for(int i = 0; i < n;i++){
	    if(stk.empty()) stk.push(make_pair(arr[i],i));
	    else if(stk.top().first > arr[i]){
	        while(stk.top().first > arr[i]){
	            result *= i - stk.top().second + 1;
	            result %= MOD;
	            stk.pop();
	            if(stk.empty()) break;
	        }
	        stk.push(make_pair(arr[i],i));
	    }
	    else stk.push(make_pair(arr[i],i));
	}
	cout<< result <<"\n";
	return 0;
}
