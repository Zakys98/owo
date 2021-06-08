#include "../include/data.h"

int Data::getId() { return id; }

void Data::setId(int id) { this->id = id; }

std::string Data::getText() { return text; }

void Data::setText(char *s) {
    std::string str(s);
    this->text = str;
}

void Data::setText(std::string s) {
    this->text = s;
}