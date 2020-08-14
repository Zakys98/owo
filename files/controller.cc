#include "../headers/controller.h"

void Controller::addSection(char **arg) {
    Section s;
    std::string str(arg[2]);
    s.setName(str);
    s.setId(sections.size());
    sections.push_back(s);
    checkSameSectionName();
}

void Controller::checkSameSectionName() {
    if (sections.empty()) return;
    for (unsigned int i = 0; i < sections.size() - 1; i++) {
        if (sections[i].getName() == sections[sections.size() - 1].getName()) {
            deleteLast();
            throw "Same section name\n";
        }
    }
}

void Controller::addSection(Section &s) { sections.push_back(s); }

void Controller::addTextToSectionDecision(char **arg) {
    char *ptr = NULL;
    int sectionId = strtol(arg[2], &ptr, 10);
    if (strlen(ptr) == 0) {
        checkExistSectionName(sectionId);
        addTextToSection(sectionId, arg[3]);
    } else {
        sectionId = checkExistSectionName(arg[2]);
        addTextToSection(sectionId, arg[3]);
    }
}

void Controller::checkExistSectionName(int whichSection) {
    for (unsigned int i = 0; i < sections.size(); i++) {
        if (sections[i].getId() == whichSection) return;
    }
    throw "Section doesnt exists\n";
}

int Controller::checkExistSectionName(char *whichSection) {
    std::string name(whichSection);
    for (unsigned int i = 0; i < sections.size(); i++) {
        if (sections[i].getName() == name) return sections[i].getId();
    }
    throw "Section doesnt exists\n";
}

void Controller::addTextToSection(int whichSection, char *text) {
    sections[whichSection].insertData(text);
}

void Controller::printDecision(int arc, char **arg) {
    char *ptr = nullptr;
    int sectionId = strtol(arg[2], &ptr, 10);
    if (arc == 3) {
        if (strcmp(arg[2], "--sections") == 0) {
            printAllSections();
        } else {
            if (strlen(ptr) == 0) {
                checkExistSectionName(sectionId);
                printSection(sectionId);
            } else {
                sectionId = checkExistSectionName(arg[2]);
                printSection(sectionId);
            }
        }
    } else if (arc == 4) {
        int line = strtol(arg[3], nullptr, 10);
        // dodelat kontrolu jestli je line cislo
        if (strlen(ptr) == 0) {
            checkExistSectionName(sectionId);
            printLineOfSection(sectionId, line);
        } else {
            sectionId = checkExistSectionName(arg[2]);
            printLineOfSection(sectionId, line);
        }
    }
}

void Controller::printAllSections() {
    for (unsigned int i = 0; i < sections.size(); i++) {
        printSectionIdAndName(i);
    }
}

void Controller::printSection(int sectionId) {
    printSectionIdAndName(sectionId);
    for (int j = 0; j < sections[sectionId].getNumberOfDataLines(); j++) {
        std::cout << "  " << sections[sectionId].getData()[j]->getId() << " "
                  << sections[sectionId].getData()[j]->getText() << "\n";
    }
}

void Controller::printSectionIdAndName(int position) {
    std::cout << sections[position].getId() << " "
              << sections[position].getName() << "\n";
}

void Controller::printLineOfSection(int section, int line) {
    std::cout << sections[section].getData()[line]->getId() << " "
              << sections[section].getData()[line]->getText() << "\n";
}

void Controller::deleteDecision(int arc, char **arg) {
    char *ptr = nullptr;
    int sectionId = strtol(arg[2], &ptr, 10);
    if (arc == 3) {
        if (strlen(ptr) == 0) {
            checkExistSectionName(sectionId);
            deleteMemoryLeaksSection(sectionId);
            deleteSpecificSection(sectionId);
        } else {
            sectionId = checkExistSectionName(arg[2]);
            deleteMemoryLeaksSection(sectionId);
            deleteSpecificSection(sectionId);
        }
        changeSectionsIdAfterDelete();
    } else if (arc == 4) {
        int line = strtol(arg[3], nullptr, 10);
        // dodelat kontrolu jestli to je int
        if (strlen(ptr) == 0) {
            checkExistSectionName(sectionId);
            checkIfSectionTextExists(sectionId, line);         
            deleteLineOfSection(sectionId, line);
        } else {
            sectionId = checkExistSectionName(arg[2]);
            checkIfSectionTextExists(sectionId, line);
            deleteLineOfSection(sectionId, line);
        }
        changeSectionTextsIdAfterDelete(sectionId);
    }
}

void Controller::changeSectionsIdAfterDelete() {
    for (unsigned int i = 0; i < sections.size(); i++) sections[i].setId(i);
}

void Controller::deleteSpecificSection(int whichSection) {
    sections.erase(sections.begin() + whichSection);
}

void Controller::deleteLineOfSection(int section, int line) {
    Data *d = sections[section].getData()[line];
    delete d;
    d = nullptr;
    sections[section].deleteData(line);
}

void Controller::deleteMemoryLeaksSection(int section) {
    for (unsigned int i = 0; i < sections[section].getData().size(); i++)
        delete sections[section].getData()[i];
}

void Controller::changeSectionTextsIdAfterDelete(int section) {
    for (unsigned int i = 0; i < sections[section].getData().size(); i++)
        sections[section].getData()[i]->setId(i);
}

void Controller::checkIfSectionTextExists(int sectionId, int line) {
    if ((int)sections[sectionId].getData().size() <= line)
        throw "Section text doesnt exist\n";
}

std::vector<Section> Controller::getSections() { return sections; }

void Controller::deleteLast() { sections.erase(sections.end()); }
