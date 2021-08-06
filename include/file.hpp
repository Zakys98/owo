#pragma once

#include <controller.hpp>
#include <data.hpp>
#include <fstream>
#include <iostream>

namespace Zakys98::owo {

class File {
   public:
    bool checkExists();
    void createFile();
    void closeFile();
    void openFileForReading();
    void openFileForWriting();
    void removeFile();
    void writeToFile(Controller &);
    void parseFileForController(Controller &);

   private:
    std::fstream file;
    std::string name = "document.txt";
    void parseSectionText(Section &, int);
};

}  // namespace Zakys98::owo