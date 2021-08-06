#include <controller.hpp>
#include <cstring>
#include <cxxopts.hpp>
#include <exception.hpp>
#include <file.hpp>
#include <iostream>

enum commands {
    add
};

namespace zowo = Zakys98::owo;

const std::string tryText = "Try : owo\n";

static bool checkIfFileIsInitialized() {
    zowo::File f;
    return f.checkExists();
}

static void initFile() {
    zowo::File f;
    if (f.checkExists()) {
        std::cout << "Your owo is already initialized !\n";  // throw exception
    } else {
        f.createFile();
        f.closeFile();
    }
}

static void readAndParseFile(zowo::Controller &c) {
    zowo::File f;
    f.openFileForReading();
    f.parseFileForController(c);
    f.closeFile();
}

static void openAndWriteToFile(zowo::Controller &c) {
    zowo::File f;
    f.openFileForWriting();
    f.writeToFile(c);
    f.closeFile();
}

static void removeFile() {
    zowo::File f;
    std::cout << "Are you sure ? ";
    std::string input{""};
    while (std::cin >> input) {
        std::transform(input.begin(), input.end(), input.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (input == "y" || input == "yes") {
            f.removeFile();
            break;
        } else if (input == "n" || input == "no") {
            break;
        }
    }
}

static cxxopts::Options createArgOpts() {
    cxxopts::Options options("Owo", "Program for memorization commands");
    options.add_options()("init", "init owo")("a, add", "add section or line in section", cxxopts::value<std::vector<std::string>>())("d, delete", "delete section or line in section", cxxopts::value<std::vector<std::string>>())("p, print", "print section or line in section", cxxopts::value<std::vector<std::string>>())("clean", "clean owo")("h, help", "help message");

    return options;
}

static void parseArgOpts(int argc, char **argv) {
    cxxopts::Options options = createArgOpts();
    auto result = options.parse(argc, argv);

    zowo::Controller c;

    if (result.count("help")) {
        std::cout << options.help();
    }
    if (result.count("add")) {
        auto &ff = result["add"].as<std::vector<std::string>>();
        for (const auto &f : ff) {
            std::cout << f << std::endl;
        }
    }
    if (result.count("delete")) {
        if (!checkIfFileIsInitialized()) return;
        readAndParseFile(c);
        auto &vector_of_args = result["delete"].as<std::vector<std::string>>();
        c.deleteDecision(vector_of_args);
        openAndWriteToFile(c);
    }
    if (result.count("print")) {
        if (!checkIfFileIsInitialized()) return;
        readAndParseFile(c);
        auto &vector_of_args = result["delete"].as<std::vector<std::string>>();
        c.printDecision(vector_of_args);
    }
    if (result.count("init")) {
        initFile();
    }
    if (result.count("clean")) {
        removeFile();
    }
}

int main(int argc, char **argv) {
    try {
        parseArgOpts(argc, argv);
    } catch (std::exception &e) {
        std::cout << e.what();
    }

    return 0;

    zowo::Controller c;

    std::vector<std::string> all_args(argv + 1, argv + argc);
    if (all_args.size() < 1 || all_args.size() > 4) {
        std::cout << tryText;
        return 0;
    }

    int swi = 0;

    switch (swi) {
        case add:
            if (!checkIfFileIsInitialized()) break;
            readAndParseFile(c);

            if (argc == 3) {
                try {
                    c.addSection(all_args[1]);
                } catch (zowo::exceptionSameSectionName &e) {
                    std::cout << e.what();
                }
            } else if (argc == 4)
                try {
                    c.addTextToSectionDecision(all_args[1], all_args[2]);
                } catch (zowo::exceptionSectionDoesntExist &e) {
                    std::cout << e.what();
                }

            openAndWriteToFile(c);
            break;
    }

    return 0;
}

// delsi jmeno u sekce dela problem