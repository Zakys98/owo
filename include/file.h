#ifndef __file_h__
#define __file_h__

#include <fstream>
#include <iostream>
#include <cstring>
#include "controller.h"
#include "data.h"

class File {

   private:
    std::fstream file;
    std::string name = "document.txt";
    void parseSectionText(Section &,int);

   public: 
    bool checkExists();
    void createFile();
    void closeFile();
    void openFileForReading();
    void openFileForWriting();
    void removeFile();
    void writeToFile(Controller &);
    void parseFileForController(Controller &);
    
};

#endif