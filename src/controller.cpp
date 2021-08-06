#include <controller.hpp>
#include <exception.hpp>

void Zakys98::owo::Controller::addDecision(const std::vector<std::string> &argv) {
}

void Zakys98::owo::Controller::addSection(std::string &name) {
    Section s;
    checkSameSectionName(name);
    s.setName(name);
    s.setId(sections.size());
    sections.push_back(s);
}

void Zakys98::owo::Controller::checkSameSectionName(std::string &name) {
    if (sections.empty()) return;
    for (auto &section : sections) {
        if (section.getName() == name) {
            throw Zakys98::owo::exceptionSameSectionName();
        }
    }
}

void Zakys98::owo::Controller::addSection(Section &s) { sections.push_back(s); }

void Zakys98::owo::Controller::addTextToSectionDecision(std::string &section, std::string &text) {
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

void Zakys98::owo::Controller::thirdArgumentStrtol(const std::string &number) {
    sectionId = std::stoi(number);
}

void Zakys98::owo::Controller::checkExistSectionName() {
    for (auto &section : sections) {
        if (section.getId() == sectionId) return;
    }
    throw Zakys98::owo::exceptionSectionDoesntExist();
}

void Zakys98::owo::Controller::checkExistSectionName(const std::string &name) {
    sectionId = -1;
    for (auto &section : sections) {
        if (section.getName() == name) {
            sectionId = section.getId();
            return;
        }
    }
    throw Zakys98::owo::exceptionSectionDoesntExist();
}

void Zakys98::owo::Controller::addTextToSection(std::string &text) {
    sections[sectionId].insertData(text);
}

void Zakys98::owo::Controller::printDecision(const std::vector<std::string> &argv) {
    unsigned int size = argv.size();
    if (size == 0)
        throw Zakys98::owo::exceptionMissingArgument();  //navic
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

void Zakys98::owo::Controller::printAllSections() {
    unsigned int size = getSectionsSize();
    for (unsigned int i = 0; i < size; i++) {
        sectionId = i;
        printSectionIdAndName();
    }
}

void Zakys98::owo::Controller::printSection() {
    printSectionIdAndName();
    for (int j = 0; j < sections[sectionId].getNumberOfDataLines(); j++) {
        std::cout << "  ";
        printLineOfSection(j);
    }
}

void Zakys98::owo::Controller::printSectionIdAndName() {
    std::cout << sections[sectionId].getId() << " "
              << sections[sectionId].getName() << "\n";
}

void Zakys98::owo::Controller::printLineOfSection(int line) {
    std::cout << sections[sectionId].getData()[line].getId() << " "
              << sections[sectionId].getData()[line].getText() << "\n";
}

void Zakys98::owo::Controller::deleteDecision(const std::vector<std::string> &argv) {
    unsigned int size = argv.size();
    if (size == 0)
        throw Zakys98::owo::exceptionMissingArgument();  //navic
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

void Zakys98::owo::Controller::changeSectionsIdAfterDelete() {
    int number = 0;
    for (auto &s : sections) s.setId(number++);
}

void Zakys98::owo::Controller::deleteSection() {
    sections.erase(sections.begin() + sectionId);
}

void Zakys98::owo::Controller::deleteLineOfSection(int line) {
    sections[sectionId].deleteData(line);
}

void Zakys98::owo::Controller::changeSectionTextsIdAfterDelete() {
    unsigned int size = sections[sectionId].getDataSize();
    for (unsigned int i = 0; i < size; i++)
        sections[sectionId].getData()[i].setId(i);
}

void Zakys98::owo::Controller::checkIfSectionTextExists(int line) {
    if ((int)sections[sectionId].getDataSize() <= line || line < 0)
        throw Zakys98::owo::exceptionSectionTextDoesntExist();
}

std::vector<Zakys98::owo::Section> Zakys98::owo::Controller::getSections() { return sections; }

unsigned int Zakys98::owo::Controller::getSectionsSize() { return sections.size(); }
