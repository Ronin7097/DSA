#include "Stack_libLL.cpp"

int main(void)
{
    system("clear");
    Stack<int> *s=new Stack<int>;
    s->push(10);
   cout<< s->top();
   cout<<s->size();
   cout<<s->empty();
    s->pop();
    delete s;
    return 0;
}