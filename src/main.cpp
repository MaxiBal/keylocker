#include <key.hpp>

#include <sstream>
#include <iostream>

using namespace keylocker;

template<typename T>
std::string array_to_string(std::array<T, KEY_SIZE> arr)
{
	std::stringstream stream;
	for (auto it : arr)
	{
		stream << it;
	}
	return stream.str();
}

int main()
{
	key_t cool_key = generate_key("Hello World");

	std::cout << array_to_string(cool_key);
}
