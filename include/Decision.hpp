#pragma once

#include <Controller.hpp>

namespace Zakys98::owo {

class Decision {
   public:
    virtual void make(Controller &, const std::vector<std::string> &) = 0;

   protected:
    enum TYPE {
        STRING,
        INT
    };

    inline TYPE chooseType(const std::string &str) {
        try {
            std::stoi(str);
        } catch (std::invalid_argument &e) {
            return STRING;
        }
        return INT;
    }

    inline int returnInt(const std::string &str) {
        return std::stoi(str);
    }
};

}  // namespace Zakys98::owo