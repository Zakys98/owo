#include <exception.hpp>

const char* Zakys98::owo::exceptionSectionTextDoesntExist::what() const noexcept {
    return "Section text doesnt exist\n";
}

const char* Zakys98::owo::exceptionSectionDoesntExist::what() const noexcept {
    return "Section doesnt exist\n";
}

const char* Zakys98::owo::exceptionSameSectionName::what() const noexcept {
    return "Same section name\n";
}

const char* Zakys98::owo::exceptionMissingArgument::what() const noexcept {
    return "Missing argument!\n";
}