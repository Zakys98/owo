#pragma once

#include <Section.hpp>
#include <cstring>
#include <iostream>
#include <vector>

namespace Zakys98::owo {

class Controller {
   public:
    void addDecision(const std::vector<std::string> &);
    void addSection(std::string &);
    void addSection(Section &);
    void addTextToSectionDecision(std::string &, std::string &);
    void deleteDecision(const std::vector<std::string> &argv);
    const std::vector<Section> &getSections() const;
    unsigned int getSectionsSize();
    void checkSameSectionName(std::string &);
    const Zakys98::owo::Data &checkIfSectionTextExists(Zakys98::owo::Section &, int);
    Zakys98::owo::Section &checkExistSectionName(int);
    Zakys98::owo::Section &checkExistSectionName(const std::string &);

   private:
    std::vector<Section> sections;
    int sectionId;
    char *ptr;
    void addTextToSection(std::string &);
    void deleteSection();
    void changeSectionsIdAfterDelete();
    void changeSectionTextsIdAfterDelete();
    void deleteLineOfSection(int);
    void thirdArgumentStrtol(const std::string &);
};

}  // namespace Zakys98::owo