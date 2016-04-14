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

    T{
        ll n;
        cin>>n;

        string s;
        cin>>s;

        ll r=0,g=0,b=0;

        for(ll i=0;i<n;i++){
            if(s[i]=='R') r++;
            if(s[i]=='G') g++;
            if(s[i]=='B') b++;
        }

        cout<<min( r+g ,  min( r+b , g+b ) )<<endl;
    }

    return 0;
}
