#include <iostream>
using namespace std;

class Fraction
{
    int num;
    int dem;

public:
    Fraction() {}
    Fraction(int num, int dem) : num(num), dem(dem) {}
    Fraction(Fraction const &f1) // copy construcor
    {
        this->num = f1.num;
        this->dem = f1.dem;
    }

    void simplify()
    {
        int i;
        for (i = min(num, dem); i >= 1; i--)
        {
            if (num % i == 0 && dem % i == 0)
                break;
        }
        num /= i;
        dem /= i;
    }

    void print()
    {
        cout << num << "/" << dem << endl;
    }

    Fraction &operator++()
    {
        this->num = num + dem;
        simplify();
        return *this;
    }
};

////////////////////////////////////////////////////////////////////////////////////////
class Arrays
{

    int n;
    int *arr, count;

public:
    Arrays()
    {
        n = 2;
        arr = new int[n];
        count = 0;
    }

    Arrays(int n)
    {
        this->n = n;
        count = 0;
        arr = new int[n];
    }

    // copy consturctor

    Arrays(Arrays const &v1)
    {
        this->n = v1.n;
        this->count = v1.count;
        // this->arr=v1.arr;//shalow copy
        // deep copy
        arr = new int[this->n];
        for (int i = 0; i < this->n; i++)
            arr[i] = v1.arr[i];
    }

    // copy assiment opreator

    void operator=(Arrays const &v1)
    {
        this->n = v1.n;
        this->count = v1.count;
        // this->arr=v1.arr;//shalow copy
        // deep copy
        int *arr = new int[this->n];
        for (int i = 0; i < this->n; i++)
            arr[i] = v1.arr[i];
    }

    void push_back(int a)
    {
        if (n <= count)
        {
            n = count + 2;
            int *arr1 = new int[n];
            for (int i = 0; i < n; i++)
                arr1[i] = arr[i];
            delete[] arr;
            arr = arr1;
        }
        arr[count] = a;
        count++;
    }

    void pop_back()
    {
        count--;
    }
    int size() const
    {
        return n;
    }

    void info() const
    {
        for (int i = 0; i < count; i++)
            cout << "" << arr[i]<<" ";
        cout << endl;
        cout << this->size()<<" "<<sizeof(arr);
    }
};
