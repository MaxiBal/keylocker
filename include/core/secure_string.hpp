#ifndef KEYLOCKER_CORE_SECURE_STRING_HPP
#define KEYLOCKER_CORE_SECURE_STRING_HPP

#include <algorithm>
#include <string>

namespace keylocker {
namespace core {
template <class T> 
class secure_allocator : public std::allocator<T>
{
public:
    template<class U> 
    struct rebind { typedef secure_allocator<U> other; };

    secure_allocator() {}
    secure_allocator(const secure_allocator& allocator) { }

    template <class U> 
    secure_allocator(const secure_allocator<U>& allocator) { }

    void deallocate(pointer p, size_type n)
    {
        std::fill_n((volatile char*) p, n * sizeof(T), 0);
        std::allocator<T>::deallocate(p, n);
    }
};

// secure string provides a string that is disposed of as soon as the password is removed from memory
typedef std::basic_string<char, std::char_traits<char>, secure_allocator<char> > secure_string;

} /* core */
} /* keylocker */

#endif /* end of include guard: KEYLOCKER_CORE_SECURE_STRING_HPP */
