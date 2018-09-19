Daniel Zhu
#include "H:\C++\MyFunctions.h"

using namespace std;

class Swedish {
    private:
        string phrase;
        string swedPhrase;
    public:
        Swedish();
        string getPhrase();
        string getTranslate();
        void setPhrase(string);
        void setSwed(string);
        string translate(string);
        void print();

};

Swedish::Swedish() {
    phrase = swedPhrase = "";
}

string Swedish::getPhrase() {
    return (phrase);
}

string Swedish::getTranslate() {
    return (swedPhrase);
}

void Swedish::setPhrase(string p) {
    phrase = p;
}

void Swedish::setSwed(string s) {
    swedPhrase = s;
}

string Swedish::translate(string p) {
    int tempint;
    vector<string> words;
    vector<string> wordsorig;
    string temp, temp1, finish;

    p.append(" ");
    do {
        tempint = p.find_first_of(" ");
        temp = p.substr(0,tempint);
        words.push_back(temp);
        p.erase(0,tempint+1);
    } while (p.find(" ") != string::npos);

    for (int k=0; k<words.size(); k++) {
        wordsorig.push_back(words[k]);
    }

    ///All sentences end with "Bork Bork Bork!"
    for (int g=0; g<wordsorig.size(); g++) {
        if (wordsorig[g].find(".") != string::npos) {
            words.push_back("Bork Bork Bork!");
        }
    }

    ///Replace all occurrences of "THE" with "ZEE".
    for (int k=0; k<wordsorig.size(); k++) {
        while (wordsorig[k].find("THE") != string::npos) {
            words[k].replace(wordsorig[k].find("THE"), 3, "ZEE");
            wordsorig[k].replace(wordsorig[k].find("THE"), 3, "***");
        }
    }

    ///Replace all occurrences of "AN" with "UN".
    for (int y=0; y<wordsorig.size(); y++) {
        while (wordsorig[y].find("AN") != string::npos) {
            words[y].replace(wordsorig[y].find("AN"), 2, "UN");
            wordsorig[y].replace(wordsorig[y].find("AN"), 2, "**");
        }
    }

    ///Replace all occurrences of "AU" with "OO".
    for (int r=0; r<wordsorig.size(); r++) {
        while (wordsorig[r].find("AU") != string::npos) {
            words[r].replace(wordsorig[r].find("AU"), 2, "OO");
            wordsorig[r].replace(wordsorig[r].find("AU"), 2, "**");
        }
    }

    ///Replace all occurrences of "A" not at the end of a word with "E".
    for (int o=0; o<wordsorig.size(); o++) {
        temp = wordsorig[o];
        temp1 = temp[wordsorig[o].rfind("A")+1];

        while (wordsorig[o].find("A") != string::npos) {
            if (wordsorig[o].rfind("A") == wordsorig[o].size()-2 && temp1 == ".") {
                words[o].replace(wordsorig[o].rfind("A"), 1, "*");
            }
            if (wordsorig[o].rfind("A") == wordsorig[o].size()-1) {
                words[o].replace(wordsorig[o].rfind("A"), 1, "*");
            }
            if (words[o].find("A") != string::npos) {
                words[o].replace(wordsorig[o].find("A"), 1, "E");
            }
            wordsorig[o].replace(wordsorig[o].rfind("A"), 1, "*");
        }
        while (words[o].find("*") != string::npos) {
            words[o].replace(words[o].find("*"), 1, "A");
        }
    }

    ///Replace all occurrences of "OW" with "OO".
    for (int r=0; r<wordsorig.size(); r++) {
        while (wordsorig[r].find("OW") != string::npos) {
            words[r].replace(wordsorig[r].find("OW"), 2, "OO");
            wordsorig[r].replace(wordsorig[r].find("OW"), 2, "**");
        }
    }

    ///Replace all occurrences of "O" with "U".
    for (int r=0; r<wordsorig.size(); r++) {
        while (wordsorig[r].find("O") != string::npos) {
            words[r].replace(wordsorig[r].find("O"), 1, "U");
            wordsorig[r].replace(wordsorig[r].find("O"), 1, "*");
        }
    }

    ///Replace the first occurrence of "I" other than at the start of a word with "EE".
    bool counter = 0;
    do {
        for (int a=0; a<wordsorig.size(); a++) {
            if (wordsorig[a].find("I")!= string::npos && counter == 0) {
                if (wordsorig[a].find_first_of("I") == 0) {
                    words[a].replace(0, 1, "*");
                    wordsorig[a].replace(wordsorig[a].find_first_of("I"), 1, "*");
                }
                if (words[a].find("I") != string::npos && wordsorig[a].find("I") != string::npos) {
                    words[a].replace(wordsorig[a].find("I"), 1, "EE");
                    wordsorig[a].replace(wordsorig[a].find_first_of("I"), 1, "**");
                    counter = 1;
                }
            }
        }
        counter = 1;
    } while (counter == 0);

    for (int a=0; a<wordsorig.size(); a++) {
        while (words[a].find("*") != string::npos && wordsorig[a].find("*") != string::npos) {
            words[a].replace(wordsorig[a].find("*"), 1, "I");
        }
    }

    ///Replace all occurrences of "EN" at the end of a word with "EE"
    for (int v=0; v<wordsorig.size(); v++) {
        temp = wordsorig[v];
        temp1 = temp[wordsorig[v].rfind("EN")+2];
        if (wordsorig[v].find("EN") != string::npos) {
            if (wordsorig[v].rfind("EN") == wordsorig[v].size()-3 && temp1 == ".") {
                words[v].replace(wordsorig[v].rfind("EN"), 2, "EE");
                wordsorig[v].replace(wordsorig[v].rfind("EN"), 2, "**");
            }
            if (wordsorig[v].rfind("EN") == wordsorig[v].size()-2) {
                words[v].replace(wordsorig[v].rfind("EN"), 2, "EE");
                wordsorig[v].replace(wordsorig[v].rfind("EN"), 2, "**");
            }
        }
    }

    ///Replace all occurrences of "E" at the end of a word with "E-A"
    for (int y=0; y<wordsorig.size(); y++) {
        temp = wordsorig[y];
        temp1 = temp[wordsorig[y].rfind("E")+1];
        if (wordsorig[y].find("E") != string::npos) {
            if ((wordsorig[y].rfind("E") == wordsorig[y].size()-2) && temp1 == ".") {
                words[y].replace(wordsorig[y].rfind("E"), 1, "E-A");
                wordsorig[y].replace(wordsorig[y].rfind("E"), 1, "*");
                wordsorig[y].append("**");
            }
            if (wordsorig[y].rfind("E") == wordsorig[y].size()-1) {
                words[y].replace(wordsorig[y].rfind("E"), 1, "E-A");
                wordsorig[y].replace(wordsorig[y].rfind("E"), 1, "*");
                wordsorig[y].append("**");
            }
        }
    }

    ///Replace all occurrences of "E" at the start of a word with "I"
    for (int a=0; a<wordsorig.size(); a++) {
        if (wordsorig[a].find_first_of("E") == 0) {
            words[a].replace(0, 1, "I");
            wordsorig[a].replace(0, 1, "*");
        }
    }

    ///Replace all occurrences of "U" with "OO"
    for (int r=0; r<wordsorig.size(); r++) {
        while (wordsorig[r].find("U") != string::npos) {
            words[r].replace(wordsorig[r].find("U"), 1, "OO");
            wordsorig[r].replace(wordsorig[r].find("U"), 1, "**");
        }
    }

    for (int j=0; j<words.size(); j++) {
        temp = words[j].substr(0, words[j].size());
        finish.append(temp + " ");
    }

    return (finish);
}

void Swedish::print() {
    cout << "Original Phrase: " << phrase << endl;
    cout << "Swedish Chef Translation: " << swedPhrase << endl << endl;
}

int main() {
    Swedish p;
    string orig, swed;

    ifstream readfile;
    readfile.open("S://Public/Potter/Swed5.txt");
    getline (readfile, orig);
    readfile.close();
    p.setPhrase(orig);

    swed = p.translate(orig);
    p.setSwed(swed);
    p.print();

    return 0;
}
