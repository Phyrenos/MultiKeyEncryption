#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <random>


std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int generateRandomNumber(int min, int max) {
    std::srand(std::time(0));
    return std::rand() % (max - min + 1) + min;
}


std::string removeNewline(std::string str) {
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}


std::string encryptNumberComplex(int number, const std::string& key1, const std::string& key2, const std::string& key3, const int& key4)
{
    number = number * 2;
    std::string encrypt;
    for (size_t i = 0; i < number; ++i) {
        char c = number;
        char k1 = key1[i % key1.size()];
        char k2 = key2[i % key2.size()];
        char k3 = key1[i % key3.size()];
        int asciiValue = static_cast<int>(c);
        asciiValue = (asciiValue + static_cast<int>(k1) + static_cast<int>(k2) + static_cast<int>(k3)) % key4;
        encrypt += static_cast<char>(asciiValue);
    }
    return encrypt;
}

int DecryptNumberComplex(std::string number)
{
    return number.length() / 2 ;
}

int encryptNumber(int number, int key) {
    return number * key;
}


std::string Stringencrypt(const std::string& s, const std::string& key1, const std::string& key2, const std::string& key3, const int& key4) {
    std::string encrypted;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        char k1 = key1[i % key1.size()];
        char k2 = key2[i % key2.size()];
        char k3 = key1[i % key3.size()];
        int asciiValue = static_cast<int>(c);
        asciiValue = (asciiValue + static_cast<int>(k1) + static_cast<int>(k2) + static_cast<int>(k3)) % key4;
        encrypted += static_cast<char>(asciiValue);
    }
    return encrypted;
}

std::string Stringdecrypt(const std::string& s, const std::string& key1, const std::string& key2, const std::string& key3, const int& key4) {
    std::string decrypted;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        char k1 = key1[i % key1.size()];
        char k2 = key2[i % key2.size()];
        char k3 = key1[i % key3.size()];
        int asciiValue = static_cast<int>(c);
        asciiValue = (asciiValue - static_cast<int>(k1) - static_cast<int>(k2) - static_cast<int>(k3) - key4) % key4;
        decrypted += static_cast<char>(asciiValue);
    }
    return decrypted;
}

int main() {
    std::string sentence;

    std::string Key1 = random_string(15);
    std::string Key2 = random_string(25);
    std::string Key3 = random_string(30);
    int Key4 = generateRandomNumber(500, 1023);
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::string encrypted = Stringencrypt(sentence, Key1, Key2, Key3, Key4);
    std::string decrypted = Stringdecrypt(encrypted, Key1, Key2, Key3, Key4);
    std::cout << "String Encryption" << std::endl;
    std::cout << "Key 1 : " << Key1 << std::endl;
    std::cout << "Key 2 : " << Key2 << std::endl;
    std::cout << "Key 3 : " << Key3 << std::endl;
    std::cout << "Key 4 : " << Key4 << std::endl;
    std::cout << "The encrypted sentence is: " << "" << removeNewline(encrypted) << "" << std::endl;
    std::cout << "The decrypted sentence is: " << removeNewline(decrypted) << std::endl;
    
    std::cout << "";
    std::cout << "Number Encryption" << std::endl;
    std::string encryptedNumber = encryptNumberComplex(25, Key1, Key2, Key3, Key4);
    std::cout << "Encrypted number: " << "" << removeNewline(encryptedNumber) << "" << std::endl;
    std::cout << "Decrypted number: " << DecryptNumberComplex(encryptedNumber) << std::endl;
    return 0;
}
