#include "../include/controller.h"

void Controller::addSection(char **argv) {
    Section s;
    std::string name(argv[2]);
    checkSameSectionName(name);
    s.setName(name);
    s.setId(sections.size());
    sections.push_back(s);
}

void Controller::checkSameSectionName(std::string name) {
    if (sections.empty()) return;
    for(auto &section : sections){
        if(section.getName() == name){       
            throw "Same section name\n";
        }
    }
}

void Controller::addSection(Section &s) { sections.push_back(s); }

void Controller::addTextToSectionDecision(char **argv) {
    thirdArgumentStrtol(argv[2]);
    if (isThirdArgumentInt()) {
        checkExistSectionName();
        addTextToSection(argv[3]);
    } else {
        sectionId = checkExistSectionName(argv[2]);
        addTextToSection(argv[3]);
    }
}

void Controller::thirdArgumentStrtol(char *argv) {
    ptr = nullptr;
    sectionId = strtol(argv, &ptr, 10);
}

bool Controller::isThirdArgumentInt() {
    return strlen(ptr) == 0 ? true : false;
}

void Controller::checkExistSectionName() {
    for (unsigned int i = 0; i < getSectionsSize(); i++) {
        if (sections[i].getId() == sectionId) return;
    }
    throw "Section doesnt exists\n";
}

int Controller::checkExistSectionName(char *whichSection) {
    std::string name(whichSection);
    for (unsigned int i = 0; i < getSectionsSize(); i++) {
        if (sections[i].getName() == name) return sections[i].getId();
    }
    throw "Section doesnt exists\n";
}

void Controller::addTextToSection(char *text) {
    sections[sectionId].insertData(text);
}

void Controller::printDecision(int argc, char **argv) {
    if (argc == 2)
        throw "Missing argument!\n";
    thirdArgumentStrtol(argv[2]);
    if (argc == 3) {
        if (strcmp(argv[2], "--sections") == 0) {
            printAllSections();
        } else {
            if (isThirdArgumentInt()) {
                checkExistSectionName();
                printSection();
            } else {
                sectionId = checkExistSectionName(argv[2]);
                printSection();
            }
        }
    } else if (argc == 4) {
        int line = strtol(argv[3], nullptr, 10);
        // dodelat kontrolu jestli je line cislo
        if (isThirdArgumentInt()) {
            checkExistSectionName();
            checkIfSectionTextExists(line);
            printLineOfSection(line);
        } else {
            sectionId = checkExistSectionName(argv[2]);
            printLineOfSection(line);
        }
    }
}

void Controller::printAllSections() {
    for (unsigned int i = 0; i < getSectionsSize(); i++) {
        sectionId = i;
        printSectionIdAndName();
    }
}

void Controller::printSection() {
    printSectionIdAndName();
    for (int j = 0; j < sections[sectionId].getNumberOfDataLines(); j++) {
        std::cout << "  " << sections[sectionId].getData()[j].getId() << " "
                  << sections[sectionId].getData()[j].getText() << "\n";
    }
}

void Controller::printSectionIdAndName() {
    std::cout << sections[sectionId].getId() << " "
              << sections[sectionId].getName() << "\n";
}

void Controller::printLineOfSection(int line) {
    std::cout << sections[sectionId].getData()[line].getId() << " "
              << sections[sectionId].getData()[line].getText() << "\n";
}

void Controller::deleteDecision(int argc, char **argv) {
    if (argc == 2)
        throw "Missing argument!\n";
    thirdArgumentStrtol(argv[2]);
    if (argc == 3) {
        if (isThirdArgumentInt()) {
            checkExistSectionName();
            deleteSection();
        } else {
            sectionId = checkExistSectionName(argv[2]);
            deleteSection();
        }
        changeSectionsIdAfterDelete();
    } else if (argc == 4) {
        int line = strtol(argv[3], nullptr, 10);
        // dodelat kontrolu jestli to je int
        if (isThirdArgumentInt()) {
            checkExistSectionName();
            checkIfSectionTextExists(line);
            deleteLineOfSection(line);
        } else {
            sectionId = checkExistSectionName(argv[2]);
            checkIfSectionTextExists(line);
            deleteLineOfSection(line);
        }
        changeSectionTextsIdAfterDelete();
    }
}

void Controller::changeSectionsIdAfterDelete() {
    for (unsigned int i = 0; i < getSectionsSize(); i++) sections[i].setId(i);
}

void Controller::deleteSection() {
    sections.erase(sections.begin() + sectionId);
}

void Controller::deleteLineOfSection(int line) {
    sections[sectionId].deleteData(line);
}

void Controller::changeSectionTextsIdAfterDelete() {
    for (unsigned int i = 0; i < sections[sectionId].getDataSize(); i++)
        sections[sectionId].getData()[i].setId(i);
}

void Controller::checkIfSectionTextExists(int line) {
    if ((int)sections[sectionId].getDataSize() <= line || line < 0)
        throw "Section text doesnt exist\n";
}

std::vector<Section> Controller::getSections() { return sections; }

unsigned int Controller::getSectionsSize() { return sections.size(); }
