#include<bits/stdc++.h>

using namespace std;

#define fin freopen("A-large.in","r",stdin)
#define fout freopen("apac_A.txt","w",stdout)

void solve(int T){
    long long l,r;
    cin>>l>>r;

    long long ans=0;

    long long y=min(l,r);

    ans=y*(y+1)/2;

    cout<<"Case #"<<T<<": "<<ans<<endl;
}

int main(){

    fin;
    fout;

    int t;
    cin>>t;

    for(int T=1;T<=t;T++){
        solve(T);
    }

    return 0;
}
