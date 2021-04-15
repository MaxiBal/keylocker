#include <key.hpp>
#include <password.hpp>

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

void cout_password(const keylocker::password& pass)
{
	std::cout << "Salt: " << pass.salt << std::endl;
	std::cout << "Username: " << pass.username << std::endl;
	std::cout << "Location: " << pass.location << std::endl;
	std::cout << "Password: " << pass.password << std::endl;
}

int main()
{
	key_t key = generate_key("Hello World");

	std::cout << "Key: " << array_to_string(key) << std::endl;

	keylocker::password pass = { "asdf", "maxi.balabanski@gmail.com", "https://gmail.com", "asdfasdf" };

	std::string locked_pass = lock_password(pass, key);

	std::cout << "Locked Password: " << locked_pass << std::endl;
	std::cout << "Unlocked Password: " << std::endl;
	cout_password(unlock_password(locked_pass, key));
}
