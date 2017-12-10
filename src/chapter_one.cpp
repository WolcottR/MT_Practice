#include <chapter_one.h>
#include <iostream>
#include <thread>

void chapter_1_example_1_helper()
{
    std::cout << "Inside chapter 1 example 1 helper" << std::endl;
}

void chapter_1_example_1()
{
    std::cout << "Starting chapter 1 example 1 example" << std::endl;

    std::thread t(chapter_1_example_1_helper);
    t.join();

    std::cout << "Ending chapter 1 example 1 example" << std::endl; 
}
