#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=make_pair(x,y);
    }
    sort(a.begin(),a.end(),greater<>());
    vector<int>ha,ta;
    int till=0;
    for(auto [ht,tt]:a){
        if(tt<=till) continue;
        till=tt;
        ha.push_back(ht);
        ta.push_back(tt);
    }
    int x;
    cin>>x;
    while(x--){
        int q;
        cin>>q;
        int it=upper_bound(ta.begin(),ta.end(),q)-ta.begin();
        cout<<ha[it]<<endl;
    }
}