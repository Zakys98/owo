#include <Controller.hpp>
#include <Exception.hpp>
#include <File.hpp>

namespace zowo = Zakys98::owo;

void zowo::Controller::checkSameSectionName(const std::string &name) {
    if (sections.empty()) return;
    for (auto &section : sections) {
        if (section.getName() == name) {
            throw zowo::exceptionSameSectionName();
        }
    }
}

void zowo::Controller::addSection(zowo::Section &s) { sections.push_back(s); }

void zowo::Controller::addTextToSectionDecision(std::string &section, std::string &text) {
    try {
        thirdArgumentStrtol(section);
    } catch (std::invalid_argument &e) {
        checkExistSectionName(section);
        addTextToSection(text);
        return;
    }
    //checkExistSectionName();
    addTextToSection(text);
}

void zowo::Controller::thirdArgumentStrtol(const std::string &number) {
    sectionId = std::stoi(number);
}

zowo::Section &zowo::Controller::checkExistSectionName(int id) {
    for (auto &section : sections) {
        if (section.getId() == id) return section;
    }
    throw zowo::exceptionSectionDoesntExist();
}

zowo::Section &zowo::Controller::checkExistSectionName(const std::string &name) {
    sectionId = -1;
    for (auto &section : sections) {
        if (section.getName() == name) {
            return section;
        }
    }
    throw zowo::exceptionSectionDoesntExist();
}

void zowo::Controller::addTextToSection(std::string &text) {
    sections[sectionId].insertData(text);
}

void zowo::Controller::deleteDecision(const std::vector<std::string> &argv) {
    unsigned int size = argv.size();
    try {
        thirdArgumentStrtol(argv[0]);
        //checkExistSectionName();
    } catch (std::invalid_argument &e) {
        checkExistSectionName(argv[0]);
    }

    if (size == 1) {
        deleteSection();
        changeSectionsIdAfterDelete();
    } else if (size == 2) {
        // catch invalid argument u line
        int line = std::stoi(argv[1]);
        //checkIfSectionTextExists(line);
        deleteLineOfSection(line);
        changeSectionTextsIdAfterDelete();
    }
}

void zowo::Controller::changeSectionsIdAfterDelete() {
    int number = 0;
    for (auto &s : sections) s.setId(number++);
}

void zowo::Controller::deleteSection() {
    sections.erase(sections.begin() + sectionId);
}

void zowo::Controller::deleteLineOfSection(int line) {
    sections[sectionId].deleteData(line);
}

void zowo::Controller::changeSectionTextsIdAfterDelete() {
    unsigned int size = sections[sectionId].getDataSize();
    //for (unsigned int i = 0; i < size; i++)
    //sections[sectionId].getData()[i].setId(i);
}

const zowo::Data &zowo::Controller::checkIfSectionTextExists(zowo::Section &sec, int id) {
    auto &data = sec.getData();
    for (auto &d : data) {
        if (d.getId() == id)
            return d;
    }

    throw zowo::exceptionSectionTextDoesntExist();
}

const std::vector<zowo::Section> &zowo::Controller::getSections() const { return sections; }

unsigned int zowo::Controller::getSectionsSize() { return sections.size(); }

void zowo::Controller::openAndWriteToFile() {
    zowo::File f;
    f.openFileForWriting();
    f.writeToFile(*this);
    f.closeFile();
}