#include "../include/exception.h"

const char* MyException::exceptionSectionTextDoesntExist::what() const noexcept {
    return "Section text doesnt exist\n";
}

const char* MyException::exceptionSectionDoesntExist::what() const noexcept {
    return "Section doesnt exist\n";
}

const char* MyException::exceptionSameSectionName::what() const noexcept {
    return "Same section name\n";
}

const char* MyException::exceptionMissingArgument::what() const noexcept {
    return "Missing argument!\n";
}