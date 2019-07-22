#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        std::string read_file(std::string file_name);
        void write_file(std::string text, std::string file_name);
    protected:

    private:
};

#endif  //SERIALIZER_H
