#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    //fin;

    ll n,h,k;
    cin>>n>>h>>k;

    ll a[n];

    for(ll i=0;i<n;i++) cin>>a[i];

    ll sum=0,ans=0,carry=0;
    for(ll i=0;i<=n;i++){
        if(i!=n && sum+a[i]<=h) {
            sum+=a[i];
            //ans++;
            //sum=max((ll)0,sum-k);
        }else {
            if(i==n) {
                ans+=ceil((double)sum/k);
                break;
            }
            else {
                ans+=sum/k;
                sum=sum%k;
                if(sum+a[i]>h) {
                    sum=0;
                    ans++;
                }
                i--;
            }
        }
        //cout<< i <<" "<<ans <<endl;
    }

    cout<<ans<<endl;

    return 0;
}
