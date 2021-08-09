#pragma once

#include <Data.hpp>
#include <string>
#include <vector>

namespace Zakys98::owo {

class Section {
   public:
    Section();
    int getId() const;
    void setId(int);
    const std::string getName() const;
    void setName(const std::string);
    int getNumberOfDataLines();
    void setNumberOfDataLines(int);
    const std::vector<Data> &getData() const;
    void insertData(const std::string &);
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