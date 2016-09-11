#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

void answer(int x){
    cout<<"2"<<endl;
    cout<<x<<endl;
}

int main(){
    int ans;
    cout<<"1"<<endl;
    cout<<"3 1 2 2"<<endl;
    cout<<"3 4 5 5"<<endl;
    cin>>ans;

    if(ans==0){
        answer(3);
    }
    else if(ans==1){
        answer(1);
    }
    else if(ans==2){
        answer(2);
    }
    else if(ans==-1){
        answer(4);
    }
    else {
        answer(5);
    }

    return 0;
}
