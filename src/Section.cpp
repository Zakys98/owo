#include <Section.hpp>

Zakys98::owo::Section::Section() : numberOfDataLines(0) {}

int Zakys98::owo::Section::getId() const {
    return this->id;
}

void Zakys98::owo::Section::setId(int id) {
    this->id = id;
}

const std::string Zakys98::owo::Section::getName() const {
    return this->name;
}
void Zakys98::owo::Section::setName(const std::string name) {
    this->name = name;
}

const std::vector<Zakys98::owo::Data>& Zakys98::owo::Section::getData() const {
    return data;
}

int Zakys98::owo::Section::getNumberOfDataLines() {
    return numberOfDataLines;
}

void Zakys98::owo::Section::setNumberOfDataLines(int number) {
    numberOfDataLines = number;
}

void Zakys98::owo::Section::insertData(const std::string &text) {
    Data d;
    d.setText(text);
    d.setId(numberOfDataLines);
    incNumberOfDataLines();
    insertData(d);
}

void Zakys98::owo::Section::incNumberOfDataLines() {
    numberOfDataLines++;
}

void Zakys98::owo::Section::insertData(Data &d) {
    data.push_back(d);
}

void Zakys98::owo::Section::deleteData(int position) {
    data.erase(data.begin() + position);
    decNumberOfDatalines();
}

void Zakys98::owo::Section::decNumberOfDatalines() {
    numberOfDataLines--;
}

unsigned int Zakys98::owo::Section::getDataSize() {
    return data.size();
}