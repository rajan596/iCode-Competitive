#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    string s[n];
    bool f=1;

    for(int i=0;i<n;i++) {
        cin>>s[i];
        if(f && s[i][0]=='O' && s[i][1]=='O') {
            s[i][0]=s[i][1]='+';
            f=0;
        }
        if(f && s[i][3]=='O' && s[i][4]=='O') {
            s[i][3]=s[i][4]='+';
            f=0;
        }
    }

    if(f) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<s[i]<<endl;

    return 0;
}
