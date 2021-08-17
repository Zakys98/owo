#pragma once

#include <Section.hpp>
#include <cstring>
#include <iostream>
#include <vector>

namespace Zakys98::owo {

class Controller {
   public:
    void addSection(Section &);
    void addTextToSectionDecision(std::string &, std::string &);
    void deleteDecision(const std::vector<std::string> &argv);
    const std::vector<Section> &getSections() const;
    unsigned int getSectionsSize();
    void deleteSection(Zakys98::owo::Section &);
    void readAndParseFile();
    void openAndWriteToFile();
    void checkSameSectionName(const std::string &);
    const Zakys98::owo::Data &checkExistsSectionText(Zakys98::owo::Section &, int);
    Zakys98::owo::Section &checkExistsSectionName(int);
    Zakys98::owo::Section &checkExistsSectionName(const std::string &);

   private:
    std::vector<Section> sections;
    void addTextToSection(std::string &);
    void changeSectionsIdAfterDelete();
    void changeSectionTextsIdAfterDelete();
    void deleteLineOfSection(int);
};

}  // namespace Zakys98::owo