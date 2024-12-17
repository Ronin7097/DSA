#include "CBT.cpp"

int main()
{
    system("clear");
    PriorityQueue *q = new PriorityQueue();
    for (int i = 5; i >=1; i--)
    {
        q->insert(i);
    }
    q->print();
    while(!q->isEmpty())
    {
        cout<<q->RemoveMin()<<" ";
    }

}
