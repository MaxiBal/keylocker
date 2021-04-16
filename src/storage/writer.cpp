#include <storage/writer.hpp>

namespace keylocker {
namespace storage {

void writer::operator <<(const std::string& data) { output_file << data; }

writer::~writer()
{
	// copy the temp file to the main file location
	std::ifstream src (TEMP_KEYLOCKER_FILE,      std::ios::binary);
	std::ofstream dest(PERMANENT_KEYLOCKER_FILE, std::ios::binary);

	dest << src.rdbuf();
}

} /* storage */
} /* keylocker */
