#pragma once

#include <Controller.hpp>
#include <Data.hpp>
#include <fstream>
#include <iostream>
#include <filesystem>

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
    const std::filesystem::path name = "./document.txt";
    void parseSectionText(Section &, int);
};

}  // namespace Zakys98::owo