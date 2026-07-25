#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    vector<long long>que(a+1);
    for(int i=1;i<=a;i++){
        cin>>que[i];
    }
    vector<long long>ans(a+2,0);
    for(int i=1;i<=a;i++){
        ans[i]=ans[i-1]+que[i];
    }
    for(int i=0;i<b;i++){
        int x,y;
        cin>>x>>y;
        cout<<ans[y]-ans[x-1]<<endl;
    }
}