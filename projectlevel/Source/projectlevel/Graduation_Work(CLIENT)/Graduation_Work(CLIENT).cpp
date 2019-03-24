#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 


	CLIENT->InitSock();
	auto con = CLIENT->Connect("127.0.0.1", 9000);

	if (con)
	{
		printf("Success\n");
	}

}
