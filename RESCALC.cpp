#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector< pair<int,int> > score; // {score,player}

        for(int i=0;i<n;i++){
            int k;
            cin>>k;

            int A[6]={0,0,0,0,0,0};

            for(int j=0;j<k;j++) {
                int x;
                cin>>x;
                x--;
                A[x]++;
            }

            int total=k;
            // for 6
            sort(A,A+6);
            total+=4*A[0] + 2*(A[1]-A[0]) + (A[2]-A[1]) ;

            score.push_back(make_pair(total,i+1));
        }

        if(n==1) {
            cout<<"chef"<<endl;
            continue;
        }

        sort(score.begin(),score.end());

        if(score[n-1].first==score[n-2].first){
            cout<<"tie"<<endl;
        }
        else if(score[n-1].second==1){
            cout<<"chef"<<endl;
        }
        else {
            cout<<score[n-1].second<<endl;
        }
    }

    return 0;
}
