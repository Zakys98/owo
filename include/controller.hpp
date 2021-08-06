#pragma once

#include <cstring>
#include <iostream>
#include <section.hpp>
#include <vector>

namespace Zakys98::owo {

class Controller {
   public:
    void addDecision(const std::vector<std::string> &);
    void addSection(std::string &);
    void addSection(Section &);
    void addTextToSectionDecision(std::string &, std::string &);
    void printDecision(const std::vector<std::string> &);
    void deleteDecision(const std::vector<std::string> &argv);
    std::vector<Section> getSections();
    unsigned int getSectionsSize();

   private:
    std::vector<Section> sections;
    int sectionId;
    char *ptr;
    void checkSameSectionName(std::string &);
    void checkExistSectionName();
    void checkExistSectionName(const std::string &);
    void addTextToSection(std::string &);
    void printAllSections();
    void printSection();
    void printSectionIdAndName();
    void printLineOfSection(int);
    void deleteSection();
    void changeSectionsIdAfterDelete();
    void changeSectionTextsIdAfterDelete();
    void deleteLineOfSection(int);
    void checkIfSectionTextExists(int);
    void thirdArgumentStrtol(const std::string &);
};

}  // namespace Zakys98::owo