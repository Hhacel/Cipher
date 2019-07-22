#include <iostream>
#include <string>
#include "encryptor.h"

int main()
{
    std::string file_path = "wiadomosc.txt";
    std::string key = "abc";
    Encryptor crypt = Encryptor();
    std::cout << crypt.encrypt_to_text(file_path, key) << std::endl;
    crypt.encrypt_to_file(file_path, key, "wiadomosc_2.txt");
    return 0;
}
