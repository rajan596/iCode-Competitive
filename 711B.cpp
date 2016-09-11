#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    long long a[n][n];
    vector<long long> v(n,0);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
            v[i]+=a[i][j];
        }
    }

    if(n==1) {
        cout<<"1"<<endl;
        return 0;
    }

    if(n==2) {
        vector<long long> vv;
        vv.push_back(a[0][0]);
        vv.push_back(a[1][0]);
        vv.push_back(a[0][1]);
        vv.push_back(a[1][1]);
        sort(vv.begin(),vv.end());
        if(vv[1]==vv[2] && vv[2]==vv[3]) {
            cout<<vv[1]<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
        return 0;
    }

    sort(v.begin(),v.end());

    bool possible=1;
    long long first=v[0];
    long long second=v[1];
    for(int i=2;i<n;i++) {
        if(v[i]!=second){
            cout<<"-1"<<endl;
            return 0;
        }
    }

    long long r=second-first;

    if(r<=0) {
        cout<<"-1"<<endl;
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0) {
                a[i][j]=r;
            }
        }
    }

    vector<long long> R(n,0),C(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            R[i]+=a[i][j];
            C[j]+=a[i][j];
        }
    }

    long long dia1=0,dia2=0;
    for(int i=0;i<n;i++){
        dia1+=a[i][i];
        dia2+=a[i][n-i-1];
    }

    if(dia1!=dia2) {
        cout<<"-1"<<endl;
        return 0;
    }

    for(int i=0;i<n;i++){
        if(R[i]!=dia1 || C[i]!=dia1) {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    cout<<r<<endl;

    return 0;
}
