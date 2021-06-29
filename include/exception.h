#include <iostream>

namespace MyException {
class SectionTextDoesntExistException : public std::exception {
   public:
    virtual const char* what() const noexcept;
};

class SectionDoesntExistException : public std::exception {
   public:
    virtual const char* what() const noexcept;
};
}  // namespace MyException