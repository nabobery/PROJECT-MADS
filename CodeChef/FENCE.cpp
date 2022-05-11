#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t;i++){
	    int n,m,k,r,c;
    	cin >> n >> m >> k;
    	int result = 0;
    	set<pair<int,int>> field;
    	for(int j = 0; j < k;j++){
    	    cin >> r >> c;
    	    field.insert(make_pair(r,c));
    	}
    	for(auto itr : field){
    	    r = itr.first;
    	    c = itr.second;
    	    result += 4;
    	    if(field.find({r+1,c}) != field.end()){
    	        result -= 1;
    	    }
    	    if(field.find({r-1,c}) != field.end()){
    	        result -= 1;
    	    }
    	    if(field.find({r,c+1}) != field.end()){
    	        result -= 1;
    	    }
    	    if(field.find({r,c-1}) != field.end()){
    	        result -= 1;
    	    }
    	}
    	cout<<result<<"\n";
	}
	return 0;
}
