#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){
    //fin;

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<long long> path1,path2;

        long long r[n];
        for(int i=0;i<n;i++) cin>>r[i];

        long long a,b;
        cin>>a>>b;

        a--,b--;

        long long mn1=0,mn2=0;
        long long sum1=0,sum2=0;
        long long node=a;
        long long ans;

        // clockwise : 1
        do{
            sum1+=r[node];
            path1.push_back(r[node]);
            mn1=min(mn1,sum1);
            node=(node+1LL);
        }while(node!=b);

        // anti clock wise : 2
        node=a;
        do {
            node=(node-1LL+n)%n;
            sum2+=r[node];
            path2.push_back(r[node]);
            mn2=min(mn2,sum2);
        }while(node!=b);

        // mn11
        long long mn11=0,mn22=0,temp=0;
        node=b;
        while(node-1!=a) {
            node=(node-1)%n;
            temp+=r[node];
            mn11=min(mn11,temp);
        }

        // mn22
        node=b;
        temp=0;
        while((node+1)%n!=a) {
            temp+=r[node];
            mn22=min(mn22,temp);
            node=(node+1LL)%n;
        }

        // max contiguous path on on left side using path2
        long long pos_path2=0,pos_path1=0;
        temp=0;
        for(int i=0;i<path2.size();i++){
            temp=max(0LL,temp+path2[i]);
            pos_path2=max(pos_path2,temp);
        }

        // max contiguous path on on right side using path1
        temp=0;
        for(int i=0;i<path1.size();i++){
            temp=max(0LL,temp+path1[i]);
            pos_path1=max(pos_path1,temp);
        }

        vector<long long> v;

        //cout<<mn1<<" "<<mn2<<" "<<sum1<<" "<<sum2<<" "<<mn11<<" "<<mn22<<" "<<pos_path1<<" "<<pos_path2<<endl;

        v.push_back(2*mn1+sum2);
        v.push_back(2*mn2+sum1);
        v.push_back(2*sum1+sum2);
        v.push_back(2*sum2+sum1);
        v.push_back(2*mn22+sum1);
        v.push_back(2*mn11+sum2);
        v.push_back(sum1+2*sum2-2*pos_path2);
        v.push_back(sum2+2*sum1-2*pos_path1);

        /*
        for(int i=0;i<v.size();i++){
                cout<<v[i]<<endl;
        }
        */

        sort(v.begin(),v.end());

        cout<<v[0]<<endl;
    }

    return 0;
}
