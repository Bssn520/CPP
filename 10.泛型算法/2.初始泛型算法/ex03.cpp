#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<int> iv{1, 2, 3, 45, 66, 3, 5, 2234, 5437, 43};

    int sum = std::accumulate(iv.cbegin(), iv.cend(), 0);
    std::cout << sum << std::endl;

    return 0;
}
