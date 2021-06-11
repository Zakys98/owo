#include "../include/section.h"

Section::Section() : numberOfDataLines(0) {}

int Section::getId() {
    return this->id;
}

void Section::setId(int id) {
    this->id = id;
}

std::string Section::getName() {
    return this->name;
}
void Section::setName(std::string name) {
    this->name = name;
}

std::vector<Data>& Section::getData() {
    return data;
}

int Section::getNumberOfDataLines() {
    return numberOfDataLines;
}

void Section::setNumberOfDataLines(int number) {
    numberOfDataLines = number;
}

void Section::insertData(char *text) {
    Data d;
    d.setText(text);
    d.setId(numberOfDataLines);
    incNumberOfDataLines();
    insertData(d);
}

void Section::incNumberOfDataLines() {
    numberOfDataLines++;
}

void Section::insertData(Data d) {
    data.push_back(d);
}

void Section::deleteData(int position) {
    data.erase(data.begin() + position);
    decNumberOfDatalines();
}

void Section::decNumberOfDatalines() {
    numberOfDataLines--;
}

unsigned int Section::getDataSize() {
    return data.size();
}