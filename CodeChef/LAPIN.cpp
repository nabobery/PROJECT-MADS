#include <iostream>
#include<map>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t;i++){
        cin >> s;
        int n = s.size();
        map <char,int> m1;
        for(int j = 0; j < n/2;j++){
            if(m1.find(s[j]) == m1.end()){
                m1[s[j]] = 1;
            }
            else{
                m1[s[j]]++;
            }
        }
        map <char,int> m2;
        int temp = n/2;
        if(n % 2 != 0){
            temp += 1;
        }
        for(int j = temp; j < n;j++){
            if(m2.find(s[j]) == m2.end()){
                m2[s[j]] = 1;
            }
            else{
                m2[s[j]]++;
            }
        }
        if(m1 == m2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
	return 0;
}
