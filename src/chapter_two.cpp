#include <chapter_two.h>
#include <iostream>
#include <thread>

inline int something(int & i)
{
    return i;
};

struct func
{
    int & i;
    func(int & i_):i(i_){}

    void operator()()
    {
        std::cout << "Inside Thread" << std::endl;
        for(unsigned j=0; j < 1000000; j++)
	{
	    i = something(i);
	}
    }
};

void chapter_2_example_1()
{
    std::cout << "Starting chapter 2 example 1" << std::endl;
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    
    try
    {
        std::cout << "Outside Thread" << std::endl;
    }
    catch(...)
    {
        t.join();
	throw;
    }
    t.join();
    
    std::cout << "Ending chapter 2 example 1" << std::endl;
}
