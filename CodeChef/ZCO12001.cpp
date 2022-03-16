#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int temp;
	stack<char> stk;
	vector<int> times;
	times.push_back(0);
	int depth = 0;
	int start = 0;
	for(int i = 0; i < n;i++){
	    cin >> temp;
	    if(temp == 1){
	        stk.push('(');
	    }
	    else if(temp == 2) stk.pop();
	    if(stk.empty()) times.push_back(i+1);
	    if(depth < stk.size()) start = i+1;
	    int tmp = stk.size();
	    depth = max(depth,tmp);
	}
	int length = 0, first;
	for(int i = 1; i < times.size();i++){
	    length = max(length, times[i] - times[i-1]);
	}
	for(int i = 1; i < times.size();i++){
	    if(length == times[i] - times[i-1]){
	        first = times[i-1] + 1;
	        break;
	    }
	}
	cout<<depth<<" "<< start<<" "<<length<<" "<<first<<"\n";
	return 0;
}
