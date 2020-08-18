#include "../headers/controller.h"

void Controller::addSection(char **argv) {
    Section s;
    std::string str(argv[2]);
    s.setName(str);
    s.setId(sections.size());
    sections.push_back(s);
    checkSameSectionName();
}

void Controller::checkSameSectionName() {
    if (sections.empty()) return;
    for (unsigned int i = 0; i < sectionsSize() - 1; i++) {
        if (sections[i].getName() == sections[sectionsSize() - 1].getName()) {
            deleteLast();
            throw "Same section name\n";
        }
    }
}

void Controller::addSection(Section &s) { sections.push_back(s); }

void Controller::addTextToSectionDecision(char **argv) {
    if (isThirdArgumentInt(argv)) {
        checkExistSectionName();
        addTextToSection(argv[3]);
    } else {
        sectionId = checkExistSectionName(argv[2]);
        addTextToSection(argv[3]);
    }
}

bool Controller::isThirdArgumentInt(char **argv) {
    ptr = nullptr;
    sectionId = strtol(argv[2], &ptr, 10);
    if (strlen(ptr) == 0) return true;
    return false;
}

void Controller::checkExistSectionName() {
    for (unsigned int i = 0; i < sectionsSize(); i++) {
        if (sections[i].getId() == sectionId) return;
    }
    throw "Section doesnt exists\n";
}

int Controller::checkExistSectionName(char *whichSection) {
    std::string name(whichSection);
    for (unsigned int i = 0; i < sectionsSize(); i++) {
        if (sections[i].getName() == name) return sections[i].getId();
    }
    throw "Section doesnt exists\n";
}

void Controller::addTextToSection(char *text) {
    sections[sectionId].insertData(text);
}

void Controller::printDecision(int argc, char **argv) {
    ptr = nullptr;
    sectionId = strtol(argv[2], &ptr, 10);
    if (argc == 3) {
        if (strcmp(argv[2], "--sections") == 0) {
            printAllSections();
        } else {
            if (strlen(ptr) == 0) {
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
        if (strlen(ptr) == 0) {
            checkExistSectionName();
            printLineOfSection(line);
        } else {
            sectionId = checkExistSectionName(argv[2]);
            printLineOfSection(line);
        }
    }
}

void Controller::printAllSections() {
    for (unsigned int i = 0; i < sections.size(); i++) {
        printSectionIdAndName(i);
    }
}

void Controller::printSection() {
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

void Controller::printLineOfSection(int line) {
    std::cout << sections[sectionId].getData()[line]->getId() << " "
              << sections[sectionId].getData()[line]->getText() << "\n";
}

void Controller::deleteDecision(int argc, char **argv) {
    ptr = nullptr;
    sectionId = strtol(argv[2], &ptr, 10);
    if (argc == 3) {
        if (strlen(ptr) == 0) {
            checkExistSectionName();
            deleteMemoryLeaksSection();
            deleteSpecificSection(sectionId);
        } else {
            sectionId = checkExistSectionName(argv[2]);
            deleteMemoryLeaksSection();
            deleteSpecificSection(sectionId);
        }
        changeSectionsIdAfterDelete();
    } else if (argc == 4) {
        int line = strtol(argv[3], nullptr, 10);
        // dodelat kontrolu jestli to je int
        if (strlen(ptr) == 0) {
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
    for (unsigned int i = 0; i < sections.size(); i++) sections[i].setId(i);
}

void Controller::deleteSpecificSection(int whichSection) {
    sections.erase(sections.begin() + whichSection);
}

void Controller::deleteLineOfSection(int line) {
    Data *d = sections[sectionId].getData()[line];
    delete d;
    d = nullptr;
    sections[sectionId].deleteData(line);
}

void Controller::deleteMemoryLeaksSection() {
    for (unsigned int i = 0; i < sections[sectionId].getData().size(); i++)
        delete sections[sectionId].getData()[i];
}

void Controller::changeSectionTextsIdAfterDelete() {
    for (unsigned int i = 0; i < sections[sectionId].getData().size(); i++)
        sections[sectionId].getData()[i]->setId(i);
}

void Controller::checkIfSectionTextExists(int line) {
    if ((int)sections[sectionId].getData().size() <= line)
        throw "Section text doesnt exist\n";
}

std::vector<Section> Controller::getSections() { return sections; }

unsigned int Controller::sectionsSize(){
    return sections.size();
}

void Controller::deleteLast() { sections.erase(sections.end()); }
