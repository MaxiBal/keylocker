#ifndef KEYLOCKER_STORAGE_WRITER_HPP
#define KEYLOCKER_STORAGE_WRITER_HPP

#include <storage/reader.hpp>

#include <fstream>
#include <iostream>

#define TEMP_KEYLOCKER_FILE "./temp.keylocker"
#define PERMANENT_KEYLOCKER_FILE "~/.keylocker"

namespace keylocker {
namespace storage {

// Provides a writer that writes all saved data on destroy.
// Does not save data immediately, only when the class is destroyed.
// Creates a file .keylocker at the %HOMEPATH%.
// When writing immediately to the writer, it writes to a temporary storage file in the program's location.
// Finally, when the class gets destroyed, it saves all temporary data to .keylocker, and deletes the temporary file.
class writer {
private:
	/* data */
	reader& read;
	std::ofstream output_file;

public:
	explicit writer (reader& read_) : read(read_) { output_file.open(TEMP_KEYLOCKER_FILE); }
	writer (const writer& other) = delete;

	void operator <<(const std::string& data);
	void operator =(const writer& other) = delete;

	~writer ();
};

} /* storage */
} /* keylocker */

#endif /* end of include guard: KEYLOCKER_STORAGE_WRITER_HPP */
