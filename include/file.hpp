#pragma once

#include <controller.hpp>
#include <data.hpp>

#include <fstream>
#include <iostream>

class File {
   private:
    std::fstream file;
    std::string name = "document.txt";
    void parseSectionText(Section &, int);

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