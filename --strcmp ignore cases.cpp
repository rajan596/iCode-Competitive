#include<bits/stdc++.h>

using namespace std;

bool str_cmp(char *s1,char *s2){
    cout<<s1<<" "<<s2<<endl;

    while(*s1 && *s2) {
        int c1=(*s1)>='A' && (*s1)<='Z' ? (*s1)-'A'+'a' : *s1 ;
        int c2=(*s2)>='A' && (*s2)<='Z' ? (*s2)-'A'+'a' : *s2 ;

        if(c1!=c2) return 0;
        s1++;
        s2++;
    }
    if(*s1!=*s2) return 0;
    return 1;
}

int main()
{

    cout<<str_cmp("Hello","hello")<<endl;
    cout<<str_cmp("He5648","he5648")<<endl;
    cout<<str_cmp("MyGOd","myGOD")<<endl;
    cout<<str_cmp("que","Question")<<endl;
    cout<<str_cmp("hllo","hello")<<endl;

    return 0;
}
