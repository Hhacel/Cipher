#include "serializer.h"

Serializer::Serializer()
{
    //ctor
}

Serializer::~Serializer()
{
    //dtor
}

std::string Serializer::read_file(std::string file_name)
{
    std::ifstream input_file(file_name);
    std::stringstream string_stream;

    string_stream << input_file.rdbuf();
    std::string text = string_stream.str();
    return text;
}

void Serializer::write_file(std::string text, std::string file_name)
{
    std::ofstream output_file(file_name);
    if (output_file.is_open()){
        output_file << text;
        output_file.close();
    }
    else std::cout << "Unable to open/n";
}
