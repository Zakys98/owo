#include <DeleteDecision.hpp>
#include <Section.hpp>

namespace zowo = Zakys98::owo;

static void changeSectionsIdAfterDelete(const std::vector<zowo::Section> &sections) {
    
}

static void deleteLineOfSection(int line) {
    //sections[sectionId].deleteData(line);
}

static void changeSectionTextsIdAfterDelete() {
    //unsigned int size = sections[sectionId].getDataSize();
    //for (unsigned int i = 0; i < size; i++)
    //sections[sectionId].getData()[i].setId(i);
}

void zowo::DeleteDecision::make(zowo::Controller &con, const std::vector<std::string> &args) {
    unsigned int size = args.size();
    zowo::Section sec;
    if(Decision::chooseType(args[0]) == Decision::TYPE::STRING){
        sec = con.checkExistsSectionName(args[0]);
    } else {
        int intArg = Decision::returnInt(args[0]);
        sec = con.checkExistsSectionName(intArg);
    }
        
    if (size == 1) {
        con.deleteSection(sec);
        changeSectionsIdAfterDelete(con.getSections());
    } else if (size == 2) {
        // catch invalid argument u line
        int line = std::stoi(args[1]);
        //checkIfSectionTextExists(line);
        deleteLineOfSection(line);
        changeSectionTextsIdAfterDelete();
    }

    con.openAndWriteToFile();
}