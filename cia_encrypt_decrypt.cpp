#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, string key) 
{
    string result = "";

    for (int i = 0; i < text.length(); i++) 
    {
        int shift = key[i % key.length()] - '0';

        if (isalpha(text[i])) 
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            char enc = (text[i] - base + shift) % 26 + base;
            result += enc;
        }
        else if (isdigit(text[i])) 
        {
            char enc = (text[i] - '0' + shift) % 10 + '0';
            result += enc;
        }
        else 
        {
            result += text[i];
        }
    }

    return result;
}

string decrypt(string text, string key) 
{
    string result = "";

    for (int i = 0; i < text.length(); i++) 
    {
        int shift = key[i % key.length()] - '0';

        if (isalpha(text[i])) 
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            char dec = (text[i] - base - shift + 26) % 26 + base;
            result += dec;
        }
        else if (isdigit(text[i])) 
        {
            char dec = (text[i] - '0' - shift + 10) % 10 + '0';
            result += dec;
        }
        else 
        {
            result += text[i];
        }
    }

    return result;
}

int main() 
{
    string text, key;

    cout << "INPUT: ";
    getline(cin, text);

    cout << "KEY: ";
    cin >> key;

    string encrypted = encrypt(text, key);
    cout << "\nENCRYPTED TEXT: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "DECRYPTED TEXT: " << decrypted << endl;

    return 0;
}