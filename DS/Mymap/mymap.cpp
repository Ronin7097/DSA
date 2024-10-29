#include <iostream>
#include "LL.cpp"
using namespace std;
class mymap
{
    Node **bucket;
    int count;
    int numbuc;
    int getBucketIndex(string key)
    {

        int hashcode=0;
        int size = key.size();
        int base = 1;
        for (int i = size; i >= 0; i--)
        {
            hashcode += key[i] * base;
            base *= 37; // effective
            hashcode %= numbuc; // effective
            base %= numbuc;
        }
        return hashcode % numbuc;
    }

public:
    mymap()
    {
        count = 0;
        numbuc = 5;
        bucket = new Node *[numbuc];
        for (int i = 0; i < numbuc; i++)
            bucket[i] = NULL;
    }
    ~mymap()
    {
        for (int i = 0; i < numbuc; i++)
            delete bucket[i];
        delete[] bucket;
    }
    int size()
    {
        return count;
    }
    int capacity()
    {
        return numbuc;
    }
    void add(string key, int value)
    {
        Node *temp = new Node(key, value);
        int index = getBucketIndex(key);
        Node *trav = bucket[index];
        while (trav != NULL)
        {
            if (trav->key == key)
            {
                trav->value = value;
                cout << trav->key << " updated: " << trav->value << endl;
                return;
            }
            trav = trav->next;
        }
        temp->next = bucket[index];
        bucket[index] = temp;
        count++;
        float loadfactor=(1.0*count)/numbuc;
        if (loadfactor>0.7) // rehashing
        {
            int oldnumbuc = numbuc;
            numbuc *= 2;
            Node**temp1=bucket;
            bucket= new Node*[numbuc];
            for(int i=0;i<numbuc;i++)
            bucket[i] =NULL;
            for (int i = 0; i <oldnumbuc; i++)
            {
                Node *head= temp1[i];
                while (head)
                {
                    int index = getBucketIndex(head->key);
                    add(head->key,head->value);                    
                    head = head->next; 
                }
            }
            for(int i=0;i<oldnumbuc;i++)
            delete temp1[i];
            delete[]temp1;
        }
    }

    int remove(string key)
    {
        int index = getBucketIndex(key);
        Node *trav = bucket[index], *prev = NULL;

        while (trav)
        {

            if (trav->key == key)
            {
                if (prev == NULL)
                    bucket[index] = trav->next;
                else
                    prev->next = trav->next;
                trav->next = NULL;
                delete trav;
                count--;
                return trav->value;
            }
            prev = trav;
            trav = trav->next;
        }
        return 0;
    }

    int getValue(string key)
    {
        int index = getBucketIndex(key);
        Node *trav = bucket[index];
        while (trav)
        {
            if (trav->key == key)
                return trav->value;
            trav = trav->next;
        }
        return -1;
    }

    double getLoadFactor()
    {
        return (1.0*count)/numbuc;
    }
};