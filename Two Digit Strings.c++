#include<iostream>
#include<vector>
using namespace std;
int solve(){
    string x,y;
    cin>>x>>y;
    int r=x.length(),c=y.length();
    vector<int>mx(r),my(c);
    mx[0]=x[0]-'0';
    my[0]=y[0]-'0';
    for(int i=1;i<r;i++){
        mx[i]=(mx[i-1]+(x[i]-'0'))%10;
    }
    for(int i=1;i<c;i++){
        my[i]=(my[i-1]+(y[i]-'0'))%10;
    }
    if(mx[r-1]!=my[c-1]){
        cout<<"-1"<<endl;
        return -1;
    }
    int f[r+1][c+1];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            f[i][j]=0;
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(mx[i-1]==my[j-1]){
                f[i][j]=f[i-1][j-1]+1;
            }
            else{
                f[i][j]=max(f[i][j-1],f[i-1][j]);
            }
        }
    }
    return f[r][c];

    
    
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ans=solve();
        cout<<ans;
    }
}