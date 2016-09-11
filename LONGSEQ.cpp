#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int a[2]={0,0};

        for(int i=0;i<s.length();i++){
            a[s[i]-'0']++;
        }

        if(a[0]==1 || a[1]==1) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
