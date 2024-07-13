#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int &n, int i, vector<int> &store)
{
    if (i == n)
        return;

    if (arr[i] == 5)
        store.push_back(i);

    print(arr, n, i + 1, store);
}

int main(void)
{
    system("clear");
    int n = 0;
    cout << "enter a number : ";
    cin >> n;
    int arr[n];
    cout << "Enter the value of element : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> store;
    print(arr, n, 0, store);
    for (int i = 0; i < store.size(); i++)
        cout << store.at(i) << " ";

    return 0;
}