#include <file.hpp>
#include <filesystem>

bool Zakys98::owo::File::checkExists() { return std::filesystem::exists(name); }

void Zakys98::owo::File::createFile() { file.open(name, std::fstream::out); }

void Zakys98::owo::File::closeFile() { file.close(); }

void Zakys98::owo::File::openFileForReading() {
    file.open(name, std::fstream::in | std::fstream::app);
}

void Zakys98::owo::File::openFileForWriting() {
    file.open(name, std::fstream::out | std::fstream::trunc);
}

void Zakys98::owo::File::removeFile() {
    std::filesystem::remove(name);
}

void Zakys98::owo::File::writeToFile(Controller &c) {
    unsigned int sectionSize = c.getSectionsSize();
    for (unsigned int i = 0; i < sectionSize; i++) {
        Section s = c.getSections()[i];
        file << s.getId() << " "
             << s.getName() << " "
             << s.getNumberOfDataLines() << std::endl;
        unsigned int sectionDataSize = s.getDataSize();
        for (unsigned int j = 0; j < sectionDataSize; j++) {
            file << s.getData()[j].getId() << " "
                 << s.getData()[j].getText() << std::endl;
        }
    }
}

void Zakys98::owo::File::parseFileForController(Controller &c) {
    while (!file.eof()) {
        Section s;
        std::string section_name;
        int section_id;
        int section_number_of_lines;
        file >> section_id >> section_name >> section_number_of_lines;
        if (section_name == "") break;
        s.setId(section_id);
        s.setName(section_name);
        s.setNumberOfDataLines(section_number_of_lines);
        parseSectionText(s, section_number_of_lines);
        c.addSection(s);
    }
}

void Zakys98::owo::File::parseSectionText(Section &s, int numberOfLines) {
    file.ignore();
    for (int i = 0; i < numberOfLines; i++) {
        std::string pom;
        getline(file, pom);
        std::string id = pom.substr(0, pom.find(" "));
        std::string text = pom.substr(pom.find(" ") + 1, pom.length());
        Data d;
        d.setId(stoi(id));
        d.setText(text);
        s.insertData(d);
    }
}