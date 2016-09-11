#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin>>s;

    int n=s.length();

    string ss=s;

    for(int i=0;i<n;i++){
        if(s[i]=='a') {}
        else {
            for(int j=i;j<n;j++){
                if(s[j]=='a') {
                    break;
                }
                s[j]=s[j]-1;
            }
            i=n;
        }
    }

    if(ss==s) {
        s[n-1]='z';
    }
    cout<<s<<endl;

    return 0;
}
