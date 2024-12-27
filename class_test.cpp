class Foo
{
public:
    Foo(int& a, int b): _a(a), _b(b) {}  
    Foo& operator=(const Foo& other) = delete;
    int& _a;
    int _b;


};

int main(int argc, char* argv[])
{
    int a = 100;
    int b = 200;

    Foo fa(a, b);
    Foo fb(b, a);

    fa = fb;
}