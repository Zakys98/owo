#include <Controller.hpp>
#include <PrintDecision.hpp>

static void printSectionIdAndName(const Zakys98::owo::Section &sec) {
    std::cout << sec.getId() << " "
              << sec.getName() << "\n";
}

static void printLineOfSection(const Zakys98::owo::Data &data) {
    std::cout << data.getId() << " "
              << data.getText() << "\n";
}

static void printAllSections(const std::vector<Zakys98::owo::Section> &sections, unsigned int size) {
    for (auto &section : sections) {
        printSectionIdAndName(section);
    }
}

static void printSection(const Zakys98::owo::Section &sec) {
    printSectionIdAndName(sec);
    auto &data = sec.getData();
    for (auto &d : data) {
        std::cout << "  ";
        printLineOfSection(d);
    }
}

// PREDELAT
//mozna predelat na template
void Zakys98::owo::PrintDecision::make(Controller &con, const std::vector<std::string> &args) {
    unsigned int size = args.size();
    int q = -1;
    Zakys98::owo::Section sec;
    try {
        q = std::stoi(args[0]);
    } catch (std::invalid_argument &e) {
        sec = con.checkExistSectionName(args[0]);
    }
    if (q != -1)
        sec = con.checkExistSectionName(q);

    if (size == 1) {
        if (args[0] == std::string("--sections")) {
            printAllSections(con.getSections(), size);
        } else {
            printSection(sec);  //dodelat jak pro int tak string
        }

    } else if (size == 2) {
        // catch invalid argument u line
        int line = std::stoi(args[1]);
        const Zakys98::owo::Data &data = con.checkIfSectionTextExists(sec, line);
        printLineOfSection(data);
    }
}
