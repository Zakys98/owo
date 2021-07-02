#ifndef __controller_h__
#define __controller_h__

#include <vector>
#include <cstring>
#include <iostream>
#include "section.h"

class Controller {
   private:
    std::vector<Section> sections;
    int sectionId;
    char *ptr;
    void checkSameSectionName(std::string &);
    void checkExistSectionName();
    void checkExistSectionName(std::string &);
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
    void thirdArgumentStrtol(std::string &);

   public:
    void addSection(std::string &);
    void addSection(Section &); 
    void addTextToSectionDecision(std::string &, std::string &);
    void printDecision(std::vector<std::string> &);
    void deleteDecision(std::vector<std::string> &argv);
    std::vector<Section> getSections();
    unsigned int getSectionsSize();
};

#endif