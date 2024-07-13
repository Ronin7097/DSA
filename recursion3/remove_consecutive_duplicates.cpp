#include <iostream>
using namespace std;

void remove(char arr[])
{
    if(arr[0]=='\0')
    return;

    if(arr[0]==arr[1])
    {
        for(int i=0;arr[i]!='\0'; i++)
        arr[i] = arr[i+1];
        remove(arr);
    }
    else
    remove(arr+1);

}

int main(void)
{
    system("clear");
    char arr[100];
    cout<<"Enter a string : ";
    cin >> arr;
    remove(arr);
    cout<<arr<<endl;

}
