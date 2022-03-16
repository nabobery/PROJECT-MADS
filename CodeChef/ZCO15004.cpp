#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> points(n);
	for(int i = 0; i < n;i++)
	    cin >> points[i].first >> points[i].second;
	sort(points.begin(),points.end());
	int x[n + 2], y[n + 2];
	x[0] = 0, y[0] = 0;
	x[n + 1] = 100000, y[n + 1] = 0;
	for(int i = 1; i <= n;i++){
	    x[i] = points[i-1].first;
	    y[i] = points[i-1].second;
	}
	stack<int> stk;
	stk.push(0);
	int left[n + 2], right[n + 2];
	for(int i = 1; i <= n;i++){
	    while(y[stk.top()] >= y[i]) stk.pop();
	    left[i] = stk.top();
	    stk.push(i);
	}
	while(!stk.empty()) stk.pop();
	stk.push(n+1);
	for(int i = n; i > 0;i--){
	    while(y[stk.top()] >= y[i]) stk.pop();
	    right[i] = stk.top();
	    stk.push(i);
	}
	int result = 0;
	for(int i = 1; i <= n;i++){
	    result = max(result, (x[right[i]] - x[left[i]]) * y[i]);
	}
	for(int i = 1; i <= n + 1;i++){
	    result = max(result, (x[i] - x[i-1]) * 500);
	}
	cout<<result<<"\n";
	return 0;
}
