/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-23 13:28:32
 * @LastEditTime: 2024-11-23 13:34:36
 * @Description:
 *
 */

#include <iostream>
#include <memory>
#include <string>

int main(int argc, const char **argv)
{
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(5);
    auto q = p;

    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");

    while (q != p)
    {
        std::cout << *(--q) << std::endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, 5);

    return 0;
}
