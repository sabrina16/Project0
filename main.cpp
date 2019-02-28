//compile with g++ main.cpp -std=c++11 -pthread

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <unistd.h>

void Marco() //each thread loops 10 times
{
	for (int i=1; i<=10; i++)
	{
		std::cout << "ID:" << i << " Marco\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1 second
	}
}

void Polo() //add character return
{
	for (int i=1; i<=10; i++)
	{
		std::cout << "ID:" << i << " Polo\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1 second
	}
}



int main()
{
    int n = 0;
    std::thread t1(Marco);
    std::thread t2(Polo);
		t1.join();
		t2.join();

    std::cout << "That's all, folks\n";
		return 0;
}
