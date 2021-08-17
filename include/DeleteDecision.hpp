#pragma once

#include <Decision.hpp>

namespace Zakys98::owo {

class DeleteDecision : public Zakys98::owo::Decision {
   public:
    void make(Controller &, const std::vector<std::string> &);
};

}  // namespace Zakys98::owo
