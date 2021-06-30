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
                print };

const std::string tryText = "Try : owo help\n";
const std::string helpText =
    "owo init               - initialize repository\n"
    "owo add    <section> <text>\n"
    "owo delete <section> <line>\n"
    "owo print  --sections  - prints all sections\n"
    "owo clean\n";

int argumentsParser(char **);
bool checkIfFileIsInitialized();
void readAndParseFile(Controller &);
void openAndWriteToFile(Controller &);
void initFile();

int main(int argc, char **argv) {
    if (argc >= 2 && argc < 5) {
        int swi = argumentsParser(argv);
        Controller c;
        File f;
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
                } catch (MyException::exceptionSectionTextDoesntExist &e){
                    std::cout << e.what();
                }
                break;

            case help:
                std::cout << helpText;
                break;

            case clean:
                f.removeFile();
                break;

            default:
                std::cout << tryText;
                break;
        }
    } else
        std::cout << tryText;

    return 0;
}

int argumentsParser(char **arg) {
    if (strcmp(arg[1], "init") == 0) {
        return init;
    } else if (strcmp(arg[1], "add") == 0 || (strcmp(arg[1], "a") == 0)) {
        return add;
    } else if (strcmp(arg[1], "delete") == 0 || (strcmp(arg[1], "d") == 0)) {
        return delet;
    } else if (strcmp(arg[1], "help") == 0) {
        return help;
    } else if ((strcmp(arg[1], "print") == 0) || (strcmp(arg[1], "p") == 0)) {
        return print;
    } else if (strcmp(arg[1], "clean") == 0) {
        return clean;
    }
    return -1;
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

// delsi jmeno u sekce dela problem