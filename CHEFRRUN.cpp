#include<bits/stdc++.h>

using namespace std;

int ans=0;

int main(){

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int a[n],degree[n],child[n];
        memset(degree,0,sizeof(degree));

        for(int i=0;i<n;i++) {
            cin>>a[i];
            int y=(i+a[i]+1)%n;
            child[i]=y;
            degree[y]++;
        }
        int cnt=0;

        queue<int> q;

        for(int i=0;i<n;i++){
            if(degree[i]==0) q.push(i);
        }

        while(!q.empty()) {
            int x=q.front();
            q.pop();
            cnt++;
            degree[child[x]]--;
            if(degree[child[x]]==0) {
                q.push(child[x]);
            }
        }

        cout<<n-cnt<<endl;
    }

    return 0;
}
