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
    void checkSameSectionName();
    void checkExistSectionName();
    int checkExistSectionName(char *);
    void addTextToSection(char *);
    void printAllSections();
    void printSection();
    void printSectionIdAndName();
    void printLineOfSection(int);
    void deleteSection();
    void changeSectionsIdAfterDelete();
    void changeSectionTextsIdAfterDelete();
    void deleteLast();
    void deleteLineOfSection(int);
    void deleteMemoryLeaksSection();
    void checkIfSectionTextExists(int);
    void thirdArgumentStrtol(char *);
    bool isThirdArgumentInt();

   public:
    void addSection(char **);
    void addSection(Section &); 
    void addTextToSectionDecision(char **);
    void printDecision(int, char **);
    void deleteDecision(int, char **);
    std::vector<Section> getSections();
    unsigned int getSectionsSize();
};

#endif