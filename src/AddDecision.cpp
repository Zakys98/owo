#include <AddDecision.hpp>
#include <Section.hpp>

namespace zowo = Zakys98::owo;

static void addSection(zowo::Controller &con, const std::string &name) {
    zowo::Section s;
    con.checkSameSectionName(name);
    s.setName(name);
    s.setId(con.getSectionsSize());
    con.addSection(s);
}

void zowo::AddDecision::make(zowo::Controller &con, const std::vector<std::string> &args) {
    addSection(con, args[0]);
    con.openAndWriteToFile();
}