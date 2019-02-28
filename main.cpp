//compile with g++ main.cpp -std=c++11 -pthread

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <unistd.h>

void Marco(int id) //reorder loop to go around thread?
{
	for (int i=0; i<10; i++)
	{
		std::cout << "Marco\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1 second
	}
}

void Polo(int id)
{
	for (int i=0; i<10; i++)
	{
		std::cout << "Polo\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1 second
	}
}



int main()
{
    int n = 0;
    std::thread t1(Marco, n);
    std::thread t2(Polo, n);
		t1.join();
		t2.join();

    std::cout << "That's all, folks";
}
