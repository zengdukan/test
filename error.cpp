#include <stdio.h>
#include <string>
#include <iostream>

struct Type {
    constexpr static const char* Bool = "bool";
    constexpr static const char* Int = "int";
    constexpr static const char* Float = "float";
    constexpr static const char* Color = "color";
};

enum VT
{
    FIRST = 0,
    SECOND,
};

enum MT
{
    MT_FIRST = 100,
    MT_SECOND,
};

int main(int argc, char* argv[])
{
    std::string str = "bool";
    std::cout << (str == Type::Bool) << "\n";

    VT vt = VT::FIRST;
    std::cout << (vt == static_cast<VT>(MT::MT_FIRST)) << "\n";

    return 0;
}