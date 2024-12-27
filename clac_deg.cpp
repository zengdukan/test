#include <cmath>
#include <iostream>

int main(int argc, char* argv[])
{
    float a = -8662734602240;
    float ret = fmod(a, 2*M_PI);
    float ret1 = ret;
    if (ret < 0)
        ret1 = ret + 2*M_PI;
    std::cout << ret << ", " << ret1 << "\n";

    return 0;
}