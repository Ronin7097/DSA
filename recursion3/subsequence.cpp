#include <iostream>
using namespace std;

void sub(string input,string output)
{
    if(input.length()==0)
    {
        cout << output<<endl;
        return;
    }

    sub(input.substr(1),output);
    sub(input.substr(1),output+input[0]);
}

void sub(string output,int i,string input)
{
    if(i==input.length())
    {
        cout << output<<endl;
        return;
    }
    sub(output,i+1,input);
    output.erase(output.begin()+output.find(input[i]));
    sub(output,i+1,input);

}

int main(void)
{
    system("clear");
    string input,output="";
    cout<<"Enter a String : ";
    cin >> input;
    sub(input,0,input);
    return 0;
}