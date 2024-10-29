#include "mymap.cpp"
string getString(char x)
{
    string s(1, x);
    return s;
}
int main()
{
    system("clear");
    mymap *my = new mymap();
    string temp = "abc";
    int num=10;
    for (int i = 0; i < num; i++)
    {
        temp = "abc";
        temp = temp + getString('0' + i);
        my->add(temp, i);
        cout<<my->getLoadFactor()<<endl;
    }
    temp = "abc";
    for (int i = 0; i < num; i++)
    {
        temp = "abc";
        temp = temp + getString('0' + i);
        cout << temp << ": " << my->getValue(temp) << " " << endl;
    }
    my->add(temp, 10);
    my->remove("abc1");
for (int i = 0; i < num; i++)
    {
        temp = "abc";
        temp = temp + getString('0' + i);
        cout << temp << ": " << my->getValue(temp) << " " << endl;
    }
    return 0;
}