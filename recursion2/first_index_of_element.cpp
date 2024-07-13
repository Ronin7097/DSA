#include <iostream>
#include <vector>

using namespace std;

int first(int const  arr[], int &n, int &key, int i)
{
    if(i==n)
    return -1;

    if(key==arr[i])
    return i;

    return first(arr,n,key,i+1);

}

int last (int const arr[], int &n, int &key,int i,int temp)
{
    if(i==n)
    return temp;

    if(key==arr[i])
    temp=i;

    return last(arr,n,key,i+1,temp);
}

int main()
{
    system("clear");
    int n=0;
    cout << "Enter the number : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " Elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key = 0;
    cout << "Enter the key : ";
    cin >> key;

    cout << "Found on index : " << last(arr, n, key, 0,-1)+1;
}