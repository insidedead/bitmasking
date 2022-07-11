#include <iostream>

enum Flags: char {
	jump = 1 << 0, // 0000 0001
	crouch = 1 << 1, // 0000 0010
	walk = 1 << 2, // 0000 0100
	sprint = 1 << 3, // 0000 1000
	stand = 1 << 4 // 0001 0000
};

int main()
{
	char flag = 1 << 1; // 0000 0010
	
	if(flag & jump) // 0000 0010 & 0000 0001 = 0000 0000
	{
		std::cout << "jumping";
	}

	flag = jump | walk | crouch; // 0000 0001 | 0000 0100 | 0000 0010 = 0000 0111
	
	if((flag & (walk | crouch)) == (walk | crouch)) // 0000 0111 & 0000 0110 = 0000 0110
	{
		std::cout << "walking while crouched";
	}

	flag <<= 1; // 0000 1110 ( sprint | walk | crouch)
	
	if(flag & sprint) // 0000 1110 & 0000 1000 = 0000 1000
	{
		std::cout << "sprinting";
	}

}
