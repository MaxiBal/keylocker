#include <password.hpp>

namespace keylocker {
std::string combine_password(const password& pass)
{
	std::string delimiter = "|";
	// seperate items by a '.'
	return  pass.salt     + delimiter +
			pass.username + delimiter +
			pass.location + delimiter +
			std::string(pass.password.c_str());
}

password unlock_password(const std::string raw_data, const key_t& key)
{
	// aes encryption to unlock a password

	crypto::ByteArray new_key(key.begin(), key.end());
	crypto::ByteArray data(raw_data.begin(), raw_data.end());
	crypto::ByteArray decrypted;

	auto size = crypto::Aes256::decrypt(new_key, data, decrypted);

	std::string s(decrypted.begin(), decrypted.end());

	std::string delimiter = "|";

	std::array<std::string, 3> pass_data;

	// split the string based on the delimiter '.'
	size_t pos = 0;
	size_t iterations = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    pass_data[iterations] = token;
	    s.erase(0, pos + delimiter.length());
		iterations++;
	}

	core::secure_string password = s.c_str();

	return {pass_data[0], pass_data[1], pass_data[2], password};
}

std::string lock_password(const password& pass, const key_t& key)
{
	std::string to_encrypt(combine_password(pass));

	crypto::ByteArray key_(key.begin(), key.end());
	crypto::ByteArray text(to_encrypt.begin(), to_encrypt.end());
	crypto::ByteArray enc;

	auto size = crypto::Aes256::encrypt(key_, text, enc);

	return std::string(enc.begin(), enc.end());
}

} /* keylocker */
