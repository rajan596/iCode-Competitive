/*
Wrong Answer
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,m,k;
    cin>>n>>m>>k;

    long long c[n+1];

    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }

    long long cost[n+1][m+1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>cost[i][j];

    long long dp[n+1][m+1][k+1];

    memset(dp,1e15+7,sizeof(dp));

    if(c[1]==0) {
        for(int j=1;j<=m;j++){
            dp[1][j][1]=cost[1][j];
        }
    }
    else {
        dp[1][c[1]][1]=0;
    }

    for(int i=2;i<=n;i++){
        for(int kk=1;kk<=k;kk++){
            if(c[i]==0) {
                for(int color=1;color<=m;color++){
                    for(int j=1;j<=m;j++){
                        if(color==j) {
                            dp[i][color][kk]=min(dp[i][color][kk],dp[i-1][j][kk] + cost[i][color]);
                        }
                        else {
                            dp[i][color][kk]=min(dp[i][color][kk],dp[i-1][j][kk-1] + cost[i][color]);
                        }
                    }
                }
            }
            else {
                for(int j=1;j<=m;j++){
                    if(j==c[i]) {
                        dp[i][c[i]][kk]=min(dp[i][c[i]][kk],dp[i-1][j][kk]);
                    }
                    else {
                        dp[i][c[i]][kk]=min(dp[i][c[i]][kk],dp[i-1][j][kk-1]);
                    }
                }
            }
        }
    }

    long long mn=1e16;
    for(int j=1;j<=m;j++){
        mn=min(mn,dp[n][j][k]);
    }

    //if(mn>=1e15) mn=-1;

    cout<<mn<<endl;

    return 0;
}
