#include <key.hpp>

namespace keylocker {

key_t generate_key(core::secure_string password)
{

	SHA256 sha;
	sha.update(std::string(password.c_str()));

	uint8_t* digest = sha.digest();

	std::string hash = SHA256::to_string(digest);

	delete[] digest;

	key_t key;

	std::copy(hash.begin(), hash.end(), key.data());

	return key;
}

} /* keylocker */
