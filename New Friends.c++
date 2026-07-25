#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int find(vector<int> &ldr,int id){
    if(ldr[id]==id){
        return id;
    }
    ldr[id]=find(ldr,ldr[id]);
    return ldr[id];
}
void join(vector<int> &ldr,int lt,int rt){
    int ldrlt=find(ldr,lt);
    int ldrrt=find(ldr,rt);
    ldr[ldrrt]=ldrlt;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>ldr(n+1);
    for(int i=1;i<=n;i++){
        ldr[i]=i;
    }
    vector<int>edge(m+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        edge[i]=x;
        join(ldr,x,y);
    }
    vector<int>g(n+1,0),e(n+1,0);
    for(int i=1;i<=n;i++){
        g[find(ldr,i)]++;
    }
    for(int i=1;i<=m;i++){
        e[find(ldr,edge[i])]++;
    }
    long sum=0;
    for(int i=1;i<n+1;i++){
        sum+=(g[i]*(g[i]-1))/2-e[i];
    }
    cout<<sum;
}