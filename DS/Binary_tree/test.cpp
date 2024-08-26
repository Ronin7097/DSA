#include "bInarytree.cpp"
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    system("clear");
    funtion<int> *f = new funtion<int>;
    BTNode<int> *root=f->take_input();
    vector<int>p=f->path(root,9);
    for(int i=0;i<p.size();i++)
    cout<<" "<<p[i];
    delete f;
    delete root;
    return 0;
}
