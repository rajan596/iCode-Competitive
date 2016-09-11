#include<bits/stdc++.h>

using namespace std;

#define fin freopen("B-large.in","r",stdin)
#define fout freopen("apac_B.txt","w",stdout)

const long long M=1e9+7;

long long binpow(long long a,long long b,long long mod){
    long long ans=1;

    while(b) {
        if(b&1) {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans%mod;
}
long long modInv(long long x){
    return binpow(x,M-2,M)%M;
}

void solve(int T){
    long long a,b,n,k;
    cin>>a>>b>>n>>k;

    vector<long long> A(k,0),B(k,0);

    for(long long i=1;i<=k;i++){
        long long r=binpow(i,a,k);
        long long num=(n-i+M)%M - (n-i+M)%k;
        long long y=(num*modInv(k)+1)%M;
        if(y>=0)
        A[r]=(A[r]+y)%M;
    }

    for(long long i=1;i<=k;i++){
        long long r=binpow(i,b,k);
        long long num=(n-i+M)%M - (n-i+M)%k;
        long long y=(num*modInv(k)+1)%M;
        if(y>=0)
        B[r]=(B[r]+y)%M;
    }
    /*
    for(int i=0;i<k;i++){
        cout<<A[i]<<" "<<B[i]<<endl;
    }
    */

    long long ans=0;
    ans=ans+A[0]*B[0];
    for(long long i=1;i<k;i++){
        ans=(ans+(A[i]*B[k-i])%M)%M;
    }
    //cout<<ans<<endl;

    for(long long i=1;i<=k;i++){
        long long r1=binpow(i,a,k);
        long long r2=binpow(i,b,k);

        if((r1+r2)%k==0) {
            long long num=(n-i+M)%M - (n-i+M)%k;
            long long y=(num*modInv(k)+1)%M;
            if(y>=0)
            ans=(ans-y+M)%M;
        }
    }

    cout<<"Case #"<<T<<": "<<(ans+M)%M<<endl;
}

int main(){

    fin;
    fout;

    //cout<<(10*modInv(3))%M<<endl;

    int t;
    cin>>t;

    for(int T=1;T<=t;T++){
        solve(T);
    }

    return 0;
}
