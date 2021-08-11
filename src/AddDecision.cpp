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

static void addTextToSection(zowo::Section &sec, const std::string &text) {
    sec.insertData(text);
}

static void addDataToSection(zowo::Controller &con, const std::vector<std::string> &args) {
    int checkIfArgIsInt = -1;
    try {
        checkIfArgIsInt = std::stoi(args[0]);
    } catch (std::invalid_argument &e) {
        addTextToSection(con.checkExistsSectionName(args[0]), args[1]);
    }
    if(checkIfArgIsInt != -1)
        addTextToSection(con.checkExistsSectionName(checkIfArgIsInt), args[1]);
}

void zowo::AddDecision::make(zowo::Controller &con, const std::vector<std::string> &args) {
    unsigned int size = args.size();
    if (size == 1) {
        addSection(con, args[0]);
    } else if (size == 2) {
        addDataToSection(con, args);
    }

    con.openAndWriteToFile();
}