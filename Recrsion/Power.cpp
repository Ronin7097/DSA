#include <iostream>
using namespace std;

int power(int num,int n){
    if(n==1)return num;
    if(n<1)return 1;

    if(n%2)
     return power(num,(n+1)/2)*power(num,n/2);   
     else
     return power(num,n/2)*power(num,n/2);
}

int main()
{
    system("clear");
    int num=0,n=0;
    cout<<"Enter number : ";cin>>num;
    cout<<"And its power : ";cin>>n;
    cout<<endl;
    cout<<"Answer : "<<power(num,n)<<endl;
}