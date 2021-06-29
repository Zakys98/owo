#include "../include/exception.h"

const char* MyException::SectionTextDoesntExistException::what() const noexcept {
    return "Section text doesnt exist\n";
}

const char* MyException::SectionDoesntExistException::what() const noexcept {
    return "Section doesnt exist\n";
}