#include <iostream>
#include <string>
using namespace std;

long long Hash(string text) 
{
    long long h = 0;
    int p = 13;
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

            // 🔐 ENCRYPTION WITH CONCATENATION
            case 1: {
                cout << "\nINPUT: ";
                getline(cin, text);

                cout << "KEY: ";
                cin >> key;

                long long h = Hash(text);

                cout << "CALCULATED HASH (H(M)): " << h << endl;
                string combined = text + "|" + to_string(h);

                string encrypted = encrypt(combined, key);

                cout << "\nENCRYPTED TEXT: " << encrypted << endl;
                break;
            }

            case 2: {
                cout << "\nENTER ENCRYPTED TEXT: ";
                getline(cin, text);

                cout << "ENTER NUMERIC KEY: ";
                cin >> key;

                string decrypted = decrypt(text, key);

                // split using '|'
                int pos = decrypted.find('|');

                if (pos == string::npos) {
                    cout << "\nINVALID FORMAT\n";
                    break;
                }

                string original = decrypted.substr(0, pos);
                long long receivedHash = stoll(decrypted.substr(pos + 1));

                long long newHash = Hash(original);

                if (receivedHash == newHash) {
                    cout << "\nHASH VERIFIED\n";
                    cout << "DECRYPTED TEXT: " << original << endl;
                } else {
                    cout << "\nHASH MISMATCH! DATA TAMPERED\n";
                }

                break;
            }

            case 3:
                break;

            default:
                cout << "\nINVALID CHOICE\n";
        }

    } while (choice != 3);

    return 0;
}