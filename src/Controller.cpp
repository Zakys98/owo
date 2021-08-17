#include <Controller.hpp>
#include <Exception.hpp>
#include <File.hpp>
#include <algorithm>

namespace zowo = Zakys98::owo;

void zowo::Controller::addSection(zowo::Section &s) { sections.push_back(s); }

void zowo::Controller::checkSameSectionName(const std::string &name) {
    if (sections.empty()) return;
    for (auto &section : sections) {
        if (section.getName() == name) {
            throw zowo::exceptionSameSectionName();
        }
    }
}

zowo::Section &zowo::Controller::checkExistsSectionName(int id) {
    for (auto &section : sections) {
        if (section.getId() == id) return section;
    }
    throw zowo::exceptionSectionDoesntExist();
}

zowo::Section &zowo::Controller::checkExistsSectionName(const std::string &name) {
    for (auto &section : sections) {
        if (section.getName() == name) {
            return section;
        }
    }
    throw zowo::exceptionSectionDoesntExist();
}

const zowo::Data &zowo::Controller::checkExistsSectionText(zowo::Section &sec, int id) {
    auto &data = sec.getData();
    for (auto &d : data) {
        if (d.getId() == id)
            return d;
    }
    throw zowo::exceptionSectionTextDoesntExist();
}

void Zakys98::owo::Controller::deleteSection(zowo::Section &sec) {
    sections.erase(sections.begin() + sec.getId());
    int number = 0;
    for (auto &s : sections)
        s.setId(number++);
}

const std::vector<zowo::Section> &zowo::Controller::getSections() const { return sections; }

unsigned int zowo::Controller::getSectionsSize() { return sections.size(); }

void zowo::Controller::openAndWriteToFile() {
    zowo::File f;
    f.openFileForWriting();
    f.writeToFile(*this);
    f.closeFile();
}

void zowo::Controller::readAndParseFile() {
    zowo::File f;
    f.openFileForReading();
    f.parseFileForController(*this);
    f.closeFile();
}