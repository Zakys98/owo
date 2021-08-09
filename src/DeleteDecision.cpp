#include <DeleteDecision.hpp>
#include <Section.hpp>

namespace zowo = Zakys98::owo;

void zowo::DeleteDecision::make(zowo::Controller &con, const std::vector<std::string> &args) {
    con.openAndWriteToFile();
}