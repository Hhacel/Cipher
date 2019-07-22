#include "encryptor.h"

Encryptor::Encryptor()
{
    _upper = '~';
    _lower = ' ';
    _length = _upper - _lower + 1;
}

Encryptor::~Encryptor()
{
    //dtor
}

char Encryptor::_move(char c, int key)
{
    key %= _length;
    if(key < 0) {
        key += _length;
    }

    if(c < _lower or c > _upper or c == '\n' or c == '\r')
        return c;

    int c_int = int(c);

    c_int-=_lower;
    c_int+=key;
    c_int%=_length;
    c_int+=_lower;
    return char(c_int);
}


std::string Encryptor::_encrypt(std::string msg, std::string key)
{
    for(int i=0; i<msg.size(); i++){
        msg[i]=_move(msg[i], key[i%key.size()]);
    }
    return msg;
}

void Encryptor::encrypt_to_file(std::string file_name, std::string key, std::string file_out)
{
    std::string text = read_file(file_name);
    std::string cipher = _encrypt(text, key);
    write_file(cipher, file_out);
}

std::string Encryptor::encrypt_to_text(std::string file_name, std::string key)
{
    std::string text = read_file(file_name);
    return _encrypt(text , key);
}
