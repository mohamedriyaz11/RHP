#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>a1(n);
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    vector<long long>pre(n+1,0);
    for(int i=1;i<=n;i++){
        int cu;
        cin>>cu;
        pre[i]=pre[i-1]+cu;
    }
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int s=lower_bound(a1.begin(),a1.end(),x)-a1.begin();
        int e=upper_bound(a1.begin(),a1.end(),y)-a1.begin();
        cout<<pre[e]-pre[s]<<endl;
    }
}