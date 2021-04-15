#ifndef KEYLOCKER_KEY_HPP
#define KEYLOCKER_KEY_HPP

#include <core/secure_string.hpp>
#include <crypto/SHA256.hpp>

#include <algorithm>

#define KEY_SIZE 64 // hold 64 bit key

namespace keylocker {

typedef std::array<unsigned char, KEY_SIZE > key_t;

// NOTE: AES uses a vector<unsigned char> so conversions have to be made
// preferably return std::array and convert later to keep constant key sizes

/**
* Generates a key from a secure_string
* @param password the master password
*/
key_t generate_key(core::secure_string password);

} /* keylocker */

#endif /* end of include guard: KEYLOCKER_KEY_HPP */
