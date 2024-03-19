#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_spli(const char c) {
    char sum[10] = {' ', '(', ')', ','}; //символи, що розділяють слова(можна додати ще)
    for (char a : sum) {
        if (c == a) {
            return true;
        }
    }
    return false;
}

void longest_word(string file_name) {
    string longestWord, str, word;
    ifstream file;

    file.open(file_name);
    if (!file.is_open()) {                        // повідомляє чи відкрився файл
        cout << "error, no file" << endl;
    }

    ///////////////////////////////////////////////

    string wid[100];                                //найдовші слова(поточні)
    int longest = 0, i = 0;

    while (getline(file, str)) {       
        str += " ";
        for (char c : str) {
            if (is_spli(c)) {
                if (word.length() > longest) {        //нове найдовше слово
                    longest = word.length();
                    i = 0;
                    fill(&wid[0], &wid[100], 0);
                    wid[i] = word;
                }
                else if (word.length() == longest) {   // запис без повторів
                    int is = 0;
                    for (int j = 0; j < i + 1; j++) {
                        if (word == wid[j])
                            is = 1;
                    }                                  
                    if (is == 0) {
                        i++;
                        wid[i] = word;
                    }
                }
                word = "";
            }
            else
            {
                word += c;
            }
        }
    }

    for (string c : wid) {
        cout << c << " ";
    }
}



int main()
{
    longest_word("test1.txt");
    return 0;
}

