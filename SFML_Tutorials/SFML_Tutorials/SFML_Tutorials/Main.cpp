#include <SFML/System.hpp>
#include <iostream>


sf::Mutex mutex;


void func()
{
	//This function will run in a thread

	for (int i = 0; i < 10; i++)
	{
		mutex.lock();
		std::cout<<"I'm thread number one!"<<std::endl;
		mutex.unlock();
	}
}

int main ()
{
	//Create a thread with func as its entry point
	sf::Thread thread(&func);

	//Run it
	thread.launch();

	//The main thread continues to run

	for (int j=0; j < 10; j++)
	{
		mutex.lock();
		std::cout<<"I am the main thread."<<std::endl;
		mutex.unlock();
	}

	return 0;
}