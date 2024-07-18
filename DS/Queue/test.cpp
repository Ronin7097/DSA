#include "queue_ll.cpp"

int main(void)
{
    system("clear");
    Queue<char> q;
    int count=65;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 ; j++)
        {
            q.push(count);
            q.print();
            count++;
        }
        for(int k=0; k < 3; k++)
        q.pop();
        cout<<q.front()<<endl;
        cout<<endl;
    }
}