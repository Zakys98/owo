#include <cstring>
#include <iostream>

#include "../include/controller.h"
#include "../include/file.h"

enum commands { init, add, delet, help, clean, print };

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
void cleanMemory(Controller &);
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
                    } catch (const char *s) {
                        std::cout << s;
                    }
                } else if (argc == 4)
                    try {
                        c.addTextToSectionDecision(argv);
                    } catch (const char *s) {
                        std::cout << s;
                    }

                openAndWriteToFile(c);
                break;

            case delet:
                if (!checkIfFileIsInitialized()) break;
                readAndParseFile(c);

                try {
                    c.deleteDecision(argc, argv);
                } catch (const char *s) {
                    std::cout << s;
                }

                openAndWriteToFile(c);
                break;

            case print:
                if (!checkIfFileIsInitialized()) break;
                readAndParseFile(c);

                try {
                    c.printDecision(argc, argv);
                } catch (const char *s) {
                    std::cout << s;
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
        cleanMemory(c);
    } else
        std::cout << tryText;

    return 0;
}

int argumentsParser(char **arg) {
    if (strcmp(arg[1], "init") == 0) {
        return init;
    } else if (strcmp(arg[1], "add") == 0) {
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
    if (f.checkExists()) return 1;
    return 0;
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

void cleanMemory(Controller &c) {
    /*for (unsigned int i = 0; i < c.getSections().size(); i++) {
        for (unsigned int j = 0; j < c.getSections()[i].getData().size(); j++)
            delete c.getSections()[i].getData()[j];
    }*/
}

// delsi jmeno u sekce dela problem