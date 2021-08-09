#include <Controller.hpp>
#include <Decision.hpp>
#include <File.hpp>
#include <PrintDecision.hpp>
#include <cxxopts.hpp>
#include <iostream>

enum commands {
    add
};

namespace zowo = Zakys98::owo;

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

static void chooseDecision(zowo::Decision &decision, const std::vector<std::string> &args) {
    zowo::Controller con;
    if (!checkIfFileIsInitialized()) return;
    readAndParseFile(con);
    decision.make(con, args);
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
        zowo::PrintDecision print;
        chooseDecision(print, result["print"].as<std::vector<std::string>>());
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
        std::cout << e.what() << std::endl;
    }

    return 0;

    zowo::Controller c;

    std::vector<std::string> all_args(argv + 1, argv + argc);
    if (all_args.size() < 1 || all_args.size() > 4) {
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
                } catch (std::exception &e) {
                    std::cout << e.what();
                }
            } else if (argc == 4)
                try {
                    c.addTextToSectionDecision(all_args[1], all_args[2]);
                } catch (std::exception &e) {
                    std::cout << e.what();
                }

            openAndWriteToFile(c);
            break;
    }

    return 0;
}
// do classy controller pridat atribut zakys98::owo::file a pridat parsovani do controleru
// delsi jmeno u sekce dela problem