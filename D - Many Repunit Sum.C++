#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),ans;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long cwd=0;
    for(int i=1;i<=a[n-1];i++){
        auto it=lower_bound(a.begin(),a.end(),i);
        int cnt=a.end()-it;
        cwd+=cnt;
        ans.push_back(cwd%10);
        cwd=cwd/10;
    }
    while(cwd!=0){
        ans.push_back(cwd%10);
        cwd/=10;
    }
    reverse(ans.begin(),ans.end());
    for(int v:ans){
        cout<<v;
    }
}