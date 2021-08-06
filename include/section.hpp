#pragma once

#include <data.hpp>
#include <string>
#include <vector>

namespace Zakys98::owo {

class Section {
   public:
    Section();
    int getId();
    void setId(int);
    std::string getName();
    void setName(std::string);
    int getNumberOfDataLines();
    void setNumberOfDataLines(int);
    std::vector<Data> &getData();
    void insertData(std::string &);
    void insertData(Data &);
    void deleteData(int);
    unsigned int getDataSize();

   private:
    int id;
    std::string name;
    std::vector<Data> data;
    int numberOfDataLines;
    void incNumberOfDataLines();
    void decNumberOfDatalines();
};

}  // namespace Zakys98::owo