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

//dodelat na int
static void addDataToSection(zowo::Controller &con, const std::vector<std::string> &args) {
    try {
        //thirdArgumentStrtol(section);
    } catch (std::invalid_argument &e) {
        zowo::Section &sec = con.checkExistSectionName(args[0]);
        addTextToSection(sec, args[1]);
    }
    zowo::Section &sec = con.checkExistSectionName(args[0]);
    addTextToSection(sec, args[1]);
    //checkExistSectionName();
    //addTextToSection(text);
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