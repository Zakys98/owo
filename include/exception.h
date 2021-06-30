#include <iostream>

namespace MyException {
class exceptionSectionTextDoesntExist : public std::exception {
   public:
    virtual const char* what() const noexcept;
};

class exceptionSectionDoesntExist : public std::exception {
   public:
    virtual const char* what() const noexcept;
};

class exceptionSameSectionName : public std::exception {
   public:
    virtual const char* what() const noexcept;
};
}  // namespace MyException