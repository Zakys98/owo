#ifndef __controller_h__
#define __controller_h__

#include <vector>
#include <cstring>
#include <iostream>
#include "section.h"

class Controller {
   private:
    std::vector<Section> sections;
    void checkSameSectionName();
    void checkExistSectionName(int);
    int checkExistSectionName(char *);
    void addTextToSection(int, char *);
    void printAllSections();
    void printSection(int);
    void printSectionIdAndName(int);
    void deleteSpecificSection(int);
    void changeSectionsIdAfterDelete();
    void changeSectionTextsIdAfterDelete(int);
    void deleteLast();
    void printLineOfSection(int, int);
    void deleteLineOfSection(int, int);
    void deleteMemoryLeaksSection(int);
    void checkIfSectionTextExists(int, int);

   public:
    void addSection(char **);
    void addSection(Section &); 
    void addTextToSectionDecision(char **);
    void printDecision(int, char **);
    void deleteDecision(int, char **);
    std::vector<Section> getSections();
};

#endif