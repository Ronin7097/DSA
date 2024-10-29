#include <iostream>
using namespace std;
class Node
{
    string key;
    int value;
    Node *next;
    Node(string key, int value) 
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~Node(){
        delete next;
    }
    friend class mymap;
};