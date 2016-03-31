#include<bits/stdc++.h>

using namespace std;

#define ll int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){
    //fin;

    ll n,d,h;
    cin>>n>>d>>h;

    if(h<=d && d<=2*h){
        if((d==1) && n>2){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    else{
        cout<<"-1"<<endl;
        return 0;
    }

    ll id=2;

    for(ll i=0;i<h;i++){
        cout<<id-1<<" "<<id<<endl;
        id++;
    }

    for(ll i=0;i<d-h;i++){
        if(i==0) {
            cout<<"1 "<<id<<endl;
            id++;
        }
        else {
            cout<<id-1<<" "<<id<<endl;
            id++;
        }
    }

    while(id!=n+1){
        cout<<(h==1?1:2)<<" "<<id<<endl;
        id++;
    }

    return 0;
}
