#ifndef KEYLOCKER_STORAGE_READER_HPP
#define KEYLOCKER_STORAGE_READER_HPP

#include <string>
#include <iostream>
#include <fstream>

namespace keylocker {
namespace storage {
class reader {
private:
	/* data */
	const std::string file;
	std::ifstream input_file;

public:
	reader (std::string& file_) : file(file_) { input_file.open(file); }
	reader (const reader& other) = delete;
	virtual ~reader ();

	std::string get_file_name() const { return file; }

	void operator =(const reader& other) = delete;
};
} /* storage */
} /* keylocker */

#endif /* end of include guard: KEYLOCKER_STORAGE_READER_HPP */
