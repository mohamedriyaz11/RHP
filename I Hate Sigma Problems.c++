#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),prev(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0,last=0;
    for(int i=n-1;i>=0;i--){
        last-=prev[a[i]];
        last+=(prev[a[i]]=n-i);
        sum+=last;
    }
    cout<<sum;
}