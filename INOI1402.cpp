#include<bits/stdc++.h>

using namespace std;

int main(){

    int c,f;
    cin>>c>>f;

    long long dp[c+5][c+5];

    for(int i=0;i<=c;i++)
        for(int j=0;j<=c;j++)
            dp[i][j]=1e7;

    while(f--) {
        int a,b,p;
        cin>>a>>b>>p;

        dp[a][b]=dp[b][a]=p;
    }

    for(int i=1;i<=c;i++)
        dp[i][i]=0;

    for(int k=1;k<=c;k++){
        for(int i=1;i<=c;i++){
            for(int j=1;j<=c;j++){
                dp[i][j]=min(dp[i][j] , dp[i][k] + dp[k][j]);
            }
        }
    }

    long long ans=INT_MIN;

    for(int i=1;i<=c;i++) {
        for(int j=1;j<=c;j++) {
            ans=max(ans,dp[i][j]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
