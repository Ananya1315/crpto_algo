#include <iostream>
#include <string>
using namespace std;

long long Hash(string text) 
{
    long long h = 0;
    int p = 31;
    int mod = 1e9 + 7;

    for (char c : text) 
    {
        h = (h * p + c) % mod;
    }
    return h;
}

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

int main() {
    int choice;
    string text, key;

    do {
        cout << "\nGRONSFELD MENU \n";
        cout << "1. ENCRYPT TEXT \n";
        cout << "2. DECRYPT TEXT\n";
        cout << "3. EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                cout << "\nINPUT: ";
                getline(cin, text);

                cout << "KEY: ";
                cin >> key;

                string encrypted = encrypt(text, key);
                long long hashValue = Hash(encrypted);

                cout << "\nENCRYPTED TEST: " << encrypted << endl;
                cout << "GENERATED HASH: " << hashValue << endl;
                break;
            }

            case 2: 
            {
                cout << "\nENTER ENCRYPTED TEXT: ";
                getline(cin, text);

                cout << "ENTER NUMERIC KEY: ";
                cin >> key;

                long long oldHash;
                cout << "ENTER RECIEVED HASH: ";
                cin >> oldHash;

                long long newHash = Hash(text);

                if (oldHash == newHash) 
                {
                    cout << "\nHASH VERIFIED\n";
                    string decrypted = decrypt(text, key);
                    cout << "DECRYPTED TEXT: " << decrypted << endl;
                } 
                else 
                {
                    cout << "\nHash Mismatch! Data may be tampered.\n";
                }
                break;
            }

            case 3:
                break;

            default:
                cout << "\nINVALID CHOICE\n";
        }

    } 
    while (choice != 3);

    return 0;
}