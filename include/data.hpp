#pragma once

#include <string>

namespace Zakys98::owo {

class Data {
   public:
    int getId();
    void setId(int);
    std::string getText();
    void setText(std::string &);

   private:
    int id;
    std::string text;
};

}