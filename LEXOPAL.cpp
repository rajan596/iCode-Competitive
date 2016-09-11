#include<bits/stdc++.h>

using namespace std;

string solve(string s){
    int n=s.length();

    int i=0,j=n-1;

    while(j>=i) {
        if(s[i]=='.' && s[j]=='.') {
            s[i]=s[j]='a';
        }
        else if(s[i]=='.' && s[j]!='.') {
            s[i]=s[j];
        }
        else if(s[i]!='.' && s[j]=='.'){
            s[j]=s[i];
        }
        else if(s[i]!=s[j]) {
            return "-1";
        }


        i++;
        j--;
    }

    return s;
}

int main(){

    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }

    return 0;
}
