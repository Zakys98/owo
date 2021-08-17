#pragma once

#include <iostream>

namespace Zakys98::owo {

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