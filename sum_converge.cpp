#include <iostream>
#include <cstdint>

int main()
{
    uint64_t step_amount{100000000000}; //1e11
    uint64_t step{1};
    double f{1};
    while (step_amount > step)
    {
        f = f + 1.0 / step;
        step++;
    }
    std::cout << f <<std::endl;
    return 0;
}