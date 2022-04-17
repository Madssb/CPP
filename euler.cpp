#include <iostream>



int main()
{
    int step_amount{2,147,483,647};
    int step{};
    float f{1};
    while(step_amount > step)
    {
        f = f +1/step;
        step++;
    }
    std::cout << step;
    return 0;
}