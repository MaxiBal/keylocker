#ifndef KEYLOCKER_PASSWORD_HPP
#define KEYLOCKER_PASSWORD_HPP

#include <core/secure_string.hpp>
#include <crypto/AES.hpp>
#include <crypto/SHA256.hpp>
#include <key.hpp>

#include <algorithm>
#include <string>

#define SALT_LEN 32

struct password;

namespace {
std::string combine_password(const password& pass);
}

namespace keylocker {

struct password
{
	std::string salt;
	std::string username;
	std::string location;
	core::secure_string password; // encrypted password
};

std::string generate_salt(size_t len = SALT_LEN);

password unlock_password(const std::string raw_data, const key_t& key);
std::string lock_password(const password& pass, const key_t& key);
} /* keylocker */

#endif /* end of include guard: KEYLOCKER_PASSWORD_HPP */
