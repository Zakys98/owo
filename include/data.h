#ifndef __data_h__
#define __data_h__

#include <string>

class Data{
    
    private:
        int id;
        std::string text;
    public:
        int getId();
        void setId(int);
        std::string getText();
        void setText(char *);
        void setText(std::string);
};

#endif