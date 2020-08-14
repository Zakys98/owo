#ifndef __section_h__
#define __section_h__

#include <string>
#include <vector>
#include "data.h"

class Section{

    private:
        int id;
        std::string name;
        std::vector<Data*> data;
        //std::vector<std::unique_ptr<Data>> data;
        int numberOfDataLines;
        void incNumberOfDataLines();
        void decNumberOfDatalines();
   
    public:
        Section();
        int getId();
        void setId(int);
        std::string getName();
        void setName(std::string);
        int getNumberOfDataLines();
        void setNumberOfDataLines(int);
        std::vector<Data*> getData();
        void insertData(char*);
        void insertData(Data *);
        void deleteData(int);
};

#endif