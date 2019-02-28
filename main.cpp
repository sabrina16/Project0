//compile with g++ main.cpp -std=c++11 -pthread

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <unistd.h>

void Marco()
{
	for (int i=0; i<10; i++)
	{
		std::cout << "Marco\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void Polo()
{
	for (int i=0; i<10; i++)
	{
		std::cout << "Polo\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}



int main()
{
    int n = 0;
    std::thread t1(Marco); // t1 is not a thread
    std::thread t2(Polo); // pass by value
		t1.join();
		t2.join();

    std::cout << "We're done" << '\n';
}
