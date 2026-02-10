#include <iostream>

#include "shared_ptr.h"

int main()
{
    // TEST COUNT
    my::shared_ptr<int> ptr1(new int(5));
    std::cout << "ptr1 use_count = " << ptr1.use_count() << std::endl;

    // TEST COPY WITH COUNT
    std::cout << "Before copy ptr1 use_count = " << ptr1.use_count() << std::endl;
    my::shared_ptr<int> ptr2 = ptr1;
    std::cout << "After copy ptr1 use_count = " << ptr1.use_count() << std::endl;
    
    // TEST UNIQUE
    my::shared_ptr<double> ptr3(new double(5.8));
    std::string check1 = ptr1.unique() ? "True" : "False";
    std::string check3 = ptr3.unique() ? "True" : "False";
    std::cout << "ptr1 is unique - " << check1 << std::endl;
    std::cout << "ptr3 is unique - " << check3 << std::endl;

    // TEST MOVE
    my::shared_ptr<double> ptr4 = std::move(ptr3);
    std::cout << "Move ptr4 to ptr3, ptr4 use_count = " << ptr4.use_count() << std::endl;

    // TEST SWAP
    std::cout << "Before swap ptr1 = " << *ptr1 << " , " << "ptr2 = " << *ptr2 << std::endl;
    ptr1.swap(ptr2);
    std::cout << "After swap ptr1 = " << *ptr1 << " , " << "ptr2 = " << *ptr2 << std::endl;

    // TEST OPERATOR BOOL
    if (ptr4)
    {
        std::cout << "ptr4 is not nullptr!!!" << std::endl;
    }
    else
    {
        std::cout << "ptr4 is nullptr!!!" << std::endl;
    }
    return 0;
}