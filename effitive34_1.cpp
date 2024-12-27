#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() const {

    }

    int a;
};

class Rect : public Shape
{
public:
    
    void draw() const override
    {
        cout << __FUNCTION__ << ":" << __LINE__ << "\n";
    }

    int b;
    int c;
};

class Array
{
public:
    explicit Array(int low, int high) {}
    explicit Array(int size) {}
    int operator[](int index)
    {
        return 0;
    }
};
bool operator==(const Array& lhs, const Array& rhs)
{
    return true;
}

void print(const Shape array[], int n)
{
    cout << sizeof(array[0]) << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i].a << "\n";
    }
}

int main(int argc, char* argv[])
{
    Array a(10);
    Array b(10);

    for (int i = 0; i < 10; i ++)
    {
        if (a[i] == b[i])
        {

        }
    }

    return 0;
}