#include<bits/stdc++.h>

using namespace std;

void printLastLines(char *s,int n){
    if(n<=0) {
        fprintf(stderr , " N must be >=0 ");
        return;
    }
    char *pos=strrchr(s,'\n');
    int cnt=n;

    while(cnt--) {
        while(pos>s && *pos!='\n'){
            pos--;
        }
        while(pos>s && *pos=='\n'){
            pos--;
        }
        if(pos==s) break;
    }
    if(pos!=s) pos+=2;

    cout<<pos;
}

int main(){

    char *str = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";
    char *s2 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7";
    printLastLines(str,10);
    printf("\n");
    printLastLines(s2,10);
    return 0;
}
