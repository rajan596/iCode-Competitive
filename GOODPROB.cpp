#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    int n;
    cin>>n;

    long long A[n];

    for(int i=0;i<n;i++) cin>>A[i];

    long long ans=0;
    for(int i=0;i<n;i++){
        long long mx=A[i];
        for(int j=i+1;j<n;j++){
            mx=max(mx,A[j]);
            if((A[i]&A[j])==A[i] || (A[i]&A[j])==A[j]) {
                ans+=mx;
                //cout<<A[i]<<" "<<A[j]<<" "<<mx<<endl;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
