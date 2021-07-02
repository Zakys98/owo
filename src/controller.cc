#include "../include/controller.h"

#include "../include/exception.h"

void Controller::addSection(std::string &name) {
    Section s;
    checkSameSectionName(name);
    s.setName(name);
    s.setId(sections.size());
    sections.push_back(s);
}

void Controller::checkSameSectionName(std::string &name) {
    if (sections.empty()) return;
    for (auto &section : sections) {
        if (section.getName() == name) {
            throw MyException::exceptionSameSectionName();
        }
    }
}

void Controller::addSection(Section &s) { sections.push_back(s); }

void Controller::addTextToSectionDecision(std::string &section, std::string &text) {
    try {
        thirdArgumentStrtol(section);
    } catch (std::invalid_argument &e) {
        checkExistSectionName(section);
        addTextToSection(text);
        return;
    }
    checkExistSectionName();
    addTextToSection(text);
}

void Controller::thirdArgumentStrtol(std::string &number) {
    sectionId = std::stoi(number);
}

void Controller::checkExistSectionName() {
    for (auto &section : sections) {
        if (section.getId() == sectionId) return;
    }
    throw MyException::exceptionSectionDoesntExist();
}

void Controller::checkExistSectionName(std::string &name) {
    sectionId = -1;
    for (auto &section : sections) {
        if (section.getName() == name) {
            sectionId = section.getId();
            return;
        }
    }
    throw MyException::exceptionSectionDoesntExist();
}

void Controller::addTextToSection(std::string &text) {
    sections[sectionId].insertData(text);
}

void Controller::printDecision(std::vector<std::string> &argv) {
    unsigned int size = argv.size();
    if (size == 0)
        throw MyException::exceptionMissingArgument();
    try {
        thirdArgumentStrtol(argv[0]);
    } catch (std::invalid_argument &e) {
        checkExistSectionName(argv[0]);
    }

    if (size == 1) {
        if (argv[1] == "--sections")
            printAllSections();
        else
            printSection();

    } else if (size == 2) {
        // catch invalid argument u line
        int line = std::stoi(argv[1]);
        checkIfSectionTextExists(line);
        printLineOfSection(line);
    }
}

void Controller::printAllSections() {
    unsigned int size = getSectionsSize();
    for (unsigned int i = 0; i < size; i++) {
        sectionId = i;
        printSectionIdAndName();
    }
}

void Controller::printSection() {
    printSectionIdAndName();
    for (int j = 0; j < sections[sectionId].getNumberOfDataLines(); j++) {
        std::cout << "  ";
        printLineOfSection(j);
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

void Controller::deleteDecision(std::vector<std::string> &argv) {
    unsigned int size = argv.size();
    if (size == 0)
        throw MyException::exceptionMissingArgument();
    try {
        thirdArgumentStrtol(argv[0]);
        checkExistSectionName();
    } catch (std::invalid_argument &e) {
        checkExistSectionName(argv[0]);
    }

    if (size == 1) {
        deleteSection();
        changeSectionsIdAfterDelete();
    } else if (size == 2) {
        // catch invalid argument u line
        int line = std::stoi(argv[1]);
        checkIfSectionTextExists(line);
        deleteLineOfSection(line);
        changeSectionTextsIdAfterDelete();
    }
}

void Controller::changeSectionsIdAfterDelete() {
    int number = 0;
    for (auto &s : sections) s.setId(number++);
}

void Controller::deleteSection() {
    sections.erase(sections.begin() + sectionId);
}

void Controller::deleteLineOfSection(int line) {
    sections[sectionId].deleteData(line);
}

void Controller::changeSectionTextsIdAfterDelete() {
    unsigned int size = sections[sectionId].getDataSize();
    for (unsigned int i = 0; i < size; i++)
        sections[sectionId].getData()[i].setId(i);
}

void Controller::checkIfSectionTextExists(int line) {
    if ((int)sections[sectionId].getDataSize() <= line || line < 0)
        throw MyException::exceptionSectionTextDoesntExist();
}

std::vector<Section> Controller::getSections() { return sections; }

unsigned int Controller::getSectionsSize() { return sections.size(); }
