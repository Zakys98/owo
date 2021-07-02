#include <cstring>
#include <iostream>

#include "../include/controller.h"
#include "../include/exception.h"
#include "../include/file.h"

enum commands { init,
                add,
                delet,
                help,
                clean,
                print,
                none };

const std::string tryText = "Try : owo help\n";
const std::string helpText =
    "owo init               - initialize repository\n"
    "owo add    <section> <text>\n"
    "owo delete <section> <line>\n"
    "owo print  --sections  - prints all sections\n"
    "owo clean\n";

int argumentsParser(std::string &);
bool checkIfFileIsInitialized();
void readAndParseFile(Controller &);
void openAndWriteToFile(Controller &);
void initFile();
void removeFile();

int main(int argc, char **argv) {
    std::vector<std::string> all_args(argv + 1, argv + argc);
    if (all_args.size() < 1 || all_args.size() > 4) {
        std::cout << tryText;
        return 0;
    }

    int swi = argumentsParser(all_args[0]);
    Controller c;
    switch (swi) {
        case init:
            initFile();
            break;

        case add:
            if (!checkIfFileIsInitialized()) break;
            readAndParseFile(c);

            if (argc == 3) {
                try {
                    c.addSection(argv);
                } catch (MyException::exceptionSameSectionName &e) {
                    std::cout << e.what();
                }
            } else if (argc == 4)
                try {
                    c.addTextToSectionDecision(argv);
                } catch (MyException::exceptionSectionDoesntExist &e) {
                    std::cout << e.what();
                }

            openAndWriteToFile(c);
            break;

        case delet:
            if (!checkIfFileIsInitialized()) break;
            readAndParseFile(c);

            try {
                c.deleteDecision(argc, argv);
            } catch (MyException::exceptionSectionDoesntExist &e) {
                std::cout << e.what();
            } catch (MyException::exceptionSectionTextDoesntExist &e) {
                std::cout << e.what();
            } catch (MyException::exceptionMissingArgument &e) {
                std::cout << e.what();
            }

            openAndWriteToFile(c);
            break;

        case print:
            if (!checkIfFileIsInitialized()) break;
            readAndParseFile(c);

            try {
                c.printDecision(argc, argv);
            } catch (MyException::exceptionMissingArgument &e) {
                std::cout << e.what();
            } catch (MyException::exceptionSectionTextDoesntExist &e) {
                std::cout << e.what();
            }
            break;

        case help:
            std::cout << helpText;
            break;

        case clean:
            removeFile();
            break;

        default:
            std::cout << tryText;
            break;
    }

    return 0;
}

int argumentsParser(std::string &first_argument) {
    if (first_argument == "init")
        return init;
    else if (first_argument == "add" || first_argument == "a")
        return add;
    else if (first_argument == "delete" || first_argument == "d")
        return delet;
    else if (first_argument == "help")
        return help;
    else if (first_argument == "print" || first_argument == "p")
        return print;
    else if (first_argument == "clean")
        return clean;

    return none;
}

bool checkIfFileIsInitialized() {
    File f;
    return f.checkExists();
}

void initFile() {
    File f;
    if (f.checkExists())
        std::cout << "Your owo is already initialized !\n";
    else
        f.createFile();
    f.closeFile();
}

void readAndParseFile(Controller &c) {
    File f;
    f.openFileForReading();
    f.parseFileForController(c);
    f.closeFile();
}

void openAndWriteToFile(Controller &c) {
    File f;
    f.openFileForWriting();
    f.writeToFile(c);
    f.closeFile();
}

void removeFile() {
    File f;
    f.removeFile();
}

// delsi jmeno u sekce dela problem