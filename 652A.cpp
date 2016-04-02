#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){

    ll h1,h2,a,b;
    cin>>h1>>h2>>a>>b;


    ll days=0;

    h1+=8*a;

    if(h1>=h2){
        printf("0\n");
        return 0;
    }

    while(1){
        if(12*a-12*b<=0) {
            cout<<"-1"<<endl;
            return 0;
        }
        h1+=12*a-12*b;
        days++;
        if(h1>=h2)
            break;
    }

    cout<<days<<endl;

    return 0;
}
