// foo.decl.hpp
#ifndef FOO_DECL_HPP
#define FOO_DECL_HPP
template <typename T>
class Foo
{
  public:
    void f1(const T& n);
};
template <typename T> void goo(T x);
#endif // FOO DECL HPP