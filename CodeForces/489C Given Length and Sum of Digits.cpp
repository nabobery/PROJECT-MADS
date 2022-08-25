#include <iostream>
using namespace std;

void solve(){
    int m,s;
    cin >> m >> s;
    if(s == 0 && m == 1) cout<<"0 0\n";
    else if((s == 0 && m > 1) || (double)s/9 > m) cout<<"-1 -1\n";
    else{
        string largest(m,'0');
        int temp = s;
        for(int i = 0; i < m && temp > 0;i++){
            if(temp < 9){
                largest[i] = temp + '0';
                temp = 0;
            }
            else{
                largest[i] = '9';
                temp -= 9;
            }
        }
        string t = largest,smallest = "";
        while(!t.empty()){
            smallest += t.back();
            t.pop_back();
        }
        if(smallest[0] == '0'){
            smallest[0] = '1';
            for(int i = 1; i < m;i++){
                if(smallest[i] == '0') continue;
                else{
                    smallest[i] -= 1;
                    break;
                }
            }
        }
        cout<<smallest<<" "<<largest<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



