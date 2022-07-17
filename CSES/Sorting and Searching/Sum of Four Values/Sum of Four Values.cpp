#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct element{
    int elem,index;
};

bool customCompare(element e1, element e2){
    return e1.elem < e2.elem;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<element> elements(n);
    for(int i = 0; i < n;i++){
        cin >> elements[i].elem;
        elements[i].index = i+1;
    }
    bool flag = false;
    sort(elements.begin(),elements.end(), customCompare);
    for(int i = 0; i < n-3;i++){
        for(int j = i+1; j < n-2;j++){
            int l = j+1, h = n-1;
            while(l < h){
                if(elements[i].elem + elements[j].elem + elements[l].elem + elements[h].elem == x){
                    if(i != j && j != l && l != h){
                        cout<<elements[i].index<<" "<<elements[j].index<<" "<<elements[l].index<<" "<<elements[h].index<<"\n";
                        flag = true;
                        break;
                    }
                }
                else if(elements[i].elem + elements[j].elem + elements[l].elem + elements[h].elem > x) h--;
                else l++;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(!flag) cout<<"IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

