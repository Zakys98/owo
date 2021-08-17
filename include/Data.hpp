#pragma once

#include <string>

namespace Zakys98::owo {

class Data {
   public:
    int getId() const;
    void setId(int);
    const std::string getText() const;
    void setText(const std::string &);

   private:
    int id;
    std::string text;
};

}