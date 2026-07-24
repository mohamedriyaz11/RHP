#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long>books(n);
        for(int i=0;i<n;i++){
            cin>>books[i];
        }

        long long excess_forward=0;
        long long prev=0;
        bool neat =true;

        for(int i=0;i<n;i++){
            long long total= books[i]+excess_forward;
            long long need =prev+1;

            if(total<need){
                neat = false;
                break;
            }

            excess_forward=total-need;

            prev=need;
        }
        cout<<(neat ?"YES\n":"NO\n");
    }

    return 0;
}