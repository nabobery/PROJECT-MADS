#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map <string,string> chef_country; 
	unordered_map <string,int> country;
	unordered_map <string,int> chef;
	string ch, co;
	for(int i = 0; i < n; i++){
	    cin >> ch >> co;
	    chef_country[ch] = co;
	}
	for(int i = 0; i < m;i++){
	    cin >> ch;
	    chef[ch]++;
	    country[chef_country[ch]]++;
	}
	int best_chef = -1, best_country  = -1;
	for(auto itr : chef){
	    best_chef = max(best_chef, itr.second);
	}
	for(auto itr : country){
	    best_country = max(best_country, itr.second);
	}
	ch = "zzzzzzzzzz", co = "zzzzzzzzzz";
	for(auto itr : chef){
	    if(best_chef == itr.second){
	       if(ch > itr.first) ch = itr.first;
	    }
	}
	for(auto itr : country){
	    if(best_country == itr.second){
            if(co > itr.first) co = itr.first;
	    }
	}
	cout<<co<<"\n";
	cout<<ch<<"\n";
	return 0;
}
