#include<bits/stdc++.h>

using namespace std;

/*
- 3 dots
- no between 0-255
- only digits
*/

bool valid_ip(string st){
    int numbers=0;
    char *token;
    int n=st.length();
    char s[n+5];
    for(int i=0;i<n;i++) s[i]=st[i];
    s[n]='\0';
    cout<<s<<endl;

    token=strtok(s,".");

    while(token){
        numbers++;
        int no=0;
        if(strlen(token)==0) return 0;
        while(*token) {
            if(*token<'0' || *token>'9') return 0;
            no=no*10+(*token)-'0';
            token++;
        }
        if(no<0 || no>255) return 0;

        token=strtok(NULL,".");
    }
    if(numbers!=4) return 0;

    return 1;
}

int main()
{

    cout<<valid_ip("172.16.2.5")<<endl;
    cout<<valid_ip("172.a.2.5")<<endl;
    cout<<valid_ip(".16.2.5")<<endl;
    cout<<valid_ip("172.16.5")<<endl;
    cout<<valid_ip("172.565.2.5")<<endl;
    cout<<valid_ip("172.16.2.5.5")<<endl;

    return 0;
}
