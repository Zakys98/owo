#include <Controller.hpp>
#include <PrintDecision.hpp>

namespace zowo = Zakys98::owo;

static void printSectionIdAndName(const zowo::Section &sec) {
    std::cout << sec.getId() << " "
              << sec.getName() << "\n";
}

static void printLineOfSection(const zowo::Data &data) {
    std::cout << data.getId() << " "
              << data.getText() << "\n";
}

static void printAllSections(const std::vector<zowo::Section> &sections) {
    for (auto &section : sections) {
        printSectionIdAndName(section);
    }
}

static void printSection(const zowo::Section &sec) {
    printSectionIdAndName(sec);
    auto &data = sec.getData();
    for (auto &d : data) {
        std::cout << "  ";
        printLineOfSection(d);
    }
}

// PREDELAT
void zowo::PrintDecision::make(zowo::Controller &con, const std::vector<std::string> &args) {
    unsigned int size = args.size();
    zowo::Section sec;
    if(Decision::chooseType(args[0]) == Decision::TYPE::STRING){
        sec = con.checkExistsSectionName(args[0]); 
    } else {
        int intArg = Decision::returnInt(args[0]);
        sec = con.checkExistsSectionName(intArg);
    }   

    if (size == 1) {
        if (args[0] == std::string("--sections")) {
            printAllSections(con.getSections());
        } else {
            printSection(sec);  //dodelat jak pro int tak string
        }

    } else if (size == 2) {
        // catch invalid argument u line
        int line = std::stoi(args[1]);
        const zowo::Data &data = con.checkExistsSectionText(sec, line);
        printLineOfSection(data);
    }
}
