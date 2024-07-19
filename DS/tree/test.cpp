#include "Generic_tree.cpp"

int main(void)
{
    // 1 3 2 3 4 2 5 6 1 7 1 9 0 0 0 0 0
    system("clear");
    Functions<int> *f = new Functions<int>;
    Treenode<int> *root = f->take_input();
    cout << endl;
    f->print(root);
    // for (int i = 0; i < f->height(root); i++){
    //   f->depth(root, i);
    //     cout<<endl;
    // }
    // cout<<f->count_leaf(root)<<endl;
    delete root;
    f->print(root);
    delete f;
    return 0;
}