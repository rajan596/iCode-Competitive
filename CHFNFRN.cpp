    #include<bits/stdc++.h>

    using namespace std;

    int main(){

        int t;
        cin>>t;

        while(t--) {
            int n,m;
            cin>>n>>m;

            int adj[n+5][n+5];
            int degree[n+5];
            int table[n+5];
            bool visited[n+5];

            memset(adj,0,sizeof(adj));
            memset(degree,0,sizeof(degree));
            memset(table,0,sizeof(table));
            memset(visited,0,sizeof(visited));

            for(int i=1;i<=n;i++) {
                adj[i][i]=1;
            }

            for(int i=0;i<m;i++) {
                int a,b;
                cin>>a>>b;

                adj[a][b]=adj[b][a]=1;
            }

            queue<int> q;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    degree[i]+=adj[i][j];
                }
            }

            for(int i=1;i<=n;i++){
                if(degree[i]<n) {
                    q.push(i);
                    break;
                }
            }

            if(q.empty()) {
                cout<<"YES"<<endl;
                continue;
            }

            table[q.front()]=1;

            while(!q.empty()) {
                int i=q.front();
                q.pop();
                visited[i]=1;
                for(int j=1;j<=n;j++) {
                    if(i!=j && degree[j]!=n && table[j]==0 && !adj[i][j]) {
                        q.push(j);
                        table[j]=(table[i]==1?2:1);
                        visited[j]=1;
                    }
                }
            }

            for(int i=1;i<=n;i++){
                if(!visited[i]) {
                        q.push(i);
                        visited[i]=1;
                        table[q.front()]=1;

                        while(!q.empty()) {
                            int i=q.front();
                            q.pop();
                            visited[i]=1;
                            for(int j=1;j<=n;j++) {
                                if(i!=j && degree[j]!=n && table[j]==0 && !adj[i][j]) {
                                    q.push(j);
                                    table[j]=(table[i]==1?2:1);
                                }
                            }
                        }
                }
            }

            string ans="YES";
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++) {
                    if(i==j || degree[i]==n || degree[j]==n) continue;
                    if(table[i]==table[j] && !adj[i][j]) ans="NO";
                }
            }

            cout<<ans<<endl;
        }

        return 0;
    }
