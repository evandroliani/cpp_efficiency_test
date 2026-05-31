/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::cout << "Declare int and build shared pointers that point to it" << std::endl;
    int i = 5;
    std::shared_ptr<int> aptr = std::make_shared<int>(i);
    std::shared_ptr<int> bptr = std::make_shared<int>(i);
    std::cout << "address of i is " << &i << std::endl;
    std::cout << "aptr is pointing to " << aptr.get() << std::endl;
    std::cout << "bptr is pointing to " << bptr.get() << std::endl;
    aptr = bptr;
    std::cout << "address of i is " << &i << std::endl;
    std::cout << "aptr is pointing to " << aptr.get() << std::endl;
    std::cout << "bptr is pointing to " << bptr.get() << std::endl;
    aptr = nullptr;
    std::cout << "address of i is " << &i << std::endl;
    std::cout << "aptr is pointing to " << aptr.get() << std::endl;
    std::cout << "bptr is pointing to " << bptr.get() << std::endl;
    std::cout << "****************" << std::endl;
    int j = 3; 
    std::shared_ptr<int> q = std::make_shared<int>(j);
    std::shared_ptr<int> p = std::make_shared<int>(j);
    //  what i want "int*q = &i;"
    j = 5;
    std::cout << p << std::endl;
    std::cout << q << std::endl;
    //
    std::cout << "****************  Declare a int and assign the address to the shared pointer  ****************" << std::endl;
    int k = 10;
    int * ptrk = &k;
    std::cout << *ptrk << std::endl;
    std::cout << k << std::endl;
    k = 5;
    std::cout << *ptrk << std::endl;
    std::cout << k << std::endl;
    
    std::cout << "********* Use of make_shared and move to avoid second allocation **********" << std::endl;
    int l = 5;
    std::cout << &l << std::endl;
    auto my_ptr = std::make_shared<int>(std::move(l));
    std::cout << &l << std::endl;
    std::cout << my_ptr << std::endl;
    std::shared_ptr<int> copy_ptr = my_ptr;
    std::cout << copy_ptr << std::endl;
    std::cout << *copy_ptr << std::endl;
    std::cout << *my_ptr << std::endl;
    return 0;

}
