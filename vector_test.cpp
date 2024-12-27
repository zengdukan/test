#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    static const float STEP_PRECISION = 10.0f;
    int n = atoi(argv[1]);
    cout << (-STEP_PRECISION < n && n < STEP_PRECISION) << "\n";

    return 0;
}