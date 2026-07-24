#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,t;
  cin>>n>>t;
  vector<int> walls(n+2,0);
  while(t--){
    int l,r;
    cin>>l>>r;
    walls[l]++;
    walls[r+1]--;
  }
  int ans=INT_MAX;
  for(int w=1;w<=n;w++){
    walls[w]+=walls[w-1];
    ans=min(ans,walls[w]);
  }
  cout<<ans;
}