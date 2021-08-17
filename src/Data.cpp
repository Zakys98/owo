#include <Data.hpp>

int Zakys98::owo::Data::getId() const { return id; }

void Zakys98::owo::Data::setId(int id) { this->id = id; }

const std::string Zakys98::owo::Data::getText() const { return text; }

void Zakys98::owo::Data::setText(const std::string &s) {
    this->text = s;
}