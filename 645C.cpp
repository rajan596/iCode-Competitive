#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n,k;
string s;

ll nextRoom(ll i) {
    do{
        i++;
    }while(i<s.length() && s[i]!='0');
    return i;
}

int main(){
    //freopen("i1.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k>>s;

    ll l,r,m;

    l=nextRoom(-1);
    m=l;
    r=-1;
    ll ans=n;

    for(ll i=0;i<=k;i++) {
        r=nextRoom(r);
    }

    while(r<n){
        while(max(m-l,r-m) > max(nextRoom(m) -l, r-nextRoom(m)) ){
            m=nextRoom(m);
        }
        ans=min(ans,max(r-m,m-l));
        l=nextRoom(l);
        r=nextRoom(r);
    }

    cout<<ans<<endl;

    return 0;
}
