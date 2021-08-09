#pragma once

#include <Controller.hpp>

namespace Zakys98::owo {

class Decision {
   public:
    virtual void make(Controller &, const std::vector<std::string> &) = 0;
};

}  // namespace Zakys98::owo