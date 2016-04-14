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

    T {
        ll a[3],k;
        cin>>a[0]>>a[1]>>a[2]>>k;

        sort(a,a+3);

        ll ans=1;
        k--;
        if(a[0]>=k){
            ans+=3*k;
        }else{
            ans+=3*a[0];
            k-=a[0];

            if(a[1]-a[0]>=k){
                ans+=k*2;
            }else{
                ans+=2*(a[1]-a[0]);
                k-=a[1]-a[0];
                ans+=k;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
