#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include "serializer.h"

class Encryptor : public Serializer
{
    public:
        Encryptor();
        virtual ~Encryptor();
        std::string encrypt_to_text(std::string file_name, std::string key);
        void encrypt_to_file(std::string file_name, std::string key, std::string file_out);

    protected:

    private:
        char _move(char c, int key);
        std::string _encrypt(std::string msg, std::string key);
        char _lower;
        char _upper;
        int _length;
};

#endif //ENCRYPTOR_H
