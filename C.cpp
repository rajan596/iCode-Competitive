#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define fout freopen("i2.txt","w",stdout)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

double f(ll c[],ll m,double mid){
    double result=0;
    double r=1;

    for(int i=m;i>=0;i--){
        result += c[i] * r;
        r*=(1+mid);
    }
    //cout<<mid <<" "<< result<<endl;
    return result;
}

int main(){
    fin;
    //fout;

    ll t;
    cin>>t;

    for(int test=1;test<=t;test++) {
        ll m;
        cin>>m;

        ll c[m+5];
        for(int i=0;i<m;i++){
            cin>>c[i];
        }
        c[0]=-c[0];

        double ans=0;

        double l=-1.00;
        double r=1.00;
        double mid=0;
        int z=200;

        while(z--){
            mid=(l+r)/2;
            double ans=f(c,m,mid);
            //cout<<ans<<endl;
            if(ans==0) {
                break;
            }
            else if(ans>0){
                r=mid;
            }
            else {
                l=mid;
            }
            if(l==r) break;
        }

        cout<<"Case #"<<test<<": "<<mid<<endl;
    }

    return 0;
}
