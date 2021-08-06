#pragma once

#include <string>

class Data{
    
    private:
        int id;
        std::string text;
    public:
        int getId();
        void setId(int);
        std::string getText();
        void setText(std::string &);
};