#include "bInarytree.cpp"

BTNode<int> *createtree()
{
    int n;
    cin >>n;
    if(n==-1)
    return NULL;
    BTNode<int>* node=new BTNode<int>(n);
    node->left=createtree();
    node->right=createtree();
    return node;
}

int main()
{
    BTNode<int> *root=createtree();
    funtion<int> *f=new funtion<int>;
    f->print(root);
    delete root;
    delete f;
    return 0;
}