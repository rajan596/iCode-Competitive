#include<bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node *left,*right,*eq;
    bool isEnd;

    Node(char c){
        data=c;
        left=right=eq=NULL;
        isEnd=0;
    }
};

class TernarySearchTree{
    public:

    Node *root;
    TernarySearchTree():root(NULL){  // initializer
    }

    Node *insertUtil(Node *root,char *s);
    void insertWord(char *word);
    void print(Node *root,string s);
    void display();
    bool Search(Node *root,char *s);
    void searchWord(char *s);
};

bool TernarySearchTree::Search(Node *root,char *s){

    if(root==NULL){
        return 0;
    }
    if(root->data > *s) {
        return Search(root->left,s);
    }
    else if(root->data < *s){
        return Search(root->right,s);
    }
    else {
        if(*(s+1)==NULL && root->isEnd) {
            return 1;
        }
        return Search(root->eq,s+1);
    }
}

void TernarySearchTree::searchWord(char *s){
    if(Search(root,s)){
        printf("%s found\n",s);
    }
    else {
        printf("%s not found\n",s);
    }
}

void TernarySearchTree::display(){
    print(root,"");
}

void TernarySearchTree::print(Node *root,string s){
    if(root==NULL) return;
    print(root->left,s);
    string ss=s+root->data;
    if(root->isEnd) {
        cout<<ss<<endl;
    }
    print(root->eq,ss);
    print(root->right,s);
}

Node *TernarySearchTree::insertUtil(Node *root,char *s){

    if(root==NULL) {
        root=new Node(*s);
    }

    if(root->data > *s){
        root->left=insertUtil(root->left,s);
    }
    else if(root->data < *s) {
        root->right=insertUtil(root->right,s);
    }
    else {
        if(*(s+1)){
            root->eq=insertUtil(root->eq,s+1);
        }
        else {
            root->isEnd=1;
        }
    }
    return root;
}

void TernarySearchTree::insertWord(char *s){
    if(s==NULL) return;
    root=insertUtil(root,s);
}

int main()
{
    TernarySearchTree *t=new TernarySearchTree();
    t->insertWord("CAT");
    t->insertWord("DOG");
    t->insertWord("DS");
    t->display();
    t->searchWord("DOG");
    t->searchWord("D");
    t->searchWord("CA");
    t->searchWord("CAT");
    t->searchWord("CATT");

    return 0;
}
