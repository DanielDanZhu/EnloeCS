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
    string temp, finish;

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
    for (int g=0; g<words.size(); g++) {
        if (words[g].find(".") != string::npos) {
            words.push_back("Bork Bork Bork!");
        }
    }

    ///Replace all occurrences of "THE" with "ZEE".
    for (int k=0; k<words.size(); k++) {
        while (wordsorig[k].find("THE") != string::npos) {
            tempint = wordsorig[k].find("THE") != string::npos;
            wordsorig[k].replace(wordsorig[k].find("THE"), 3, "***");
            words[k].replace(wordsorig[k].find("THE"), 3, "ZEE");
        }
    }

    for (int k=0; k<wordsorig.size(); k++) {
        cout << wordsorig[k] << endl;
    }
    for (int k=0; k<words.size(); k++) {
        cout << words[k] << endl;
    }

    /*///Replace all occurrences of "AN" with "UN".
    for (int y=0; y<words.size(); y++) {
        while (wordsorig[y].find("AN") != string::npos) {
            words[y].replace(words[y].find("AN"), 2, "UN");
        }
    }

    ///Replace all occurrences of "AU" with "OO".
    for (int r=0; r<words.size(); r++) {
        while (wordsorig[r].find("AU") != string::npos) {
            words[r].replace(words[r].find("AU"), 2, "OO");
        }
    }

    ///Replace all occurrences of "A" not at the end of a word with "E".
    for (int o=0; o<words.size(); o++) {
        while (wordsorig[o].find("A") != string::npos) {
            if (wordsorig[o].find("A") == wordsorig[o].size()-1) {
                words[o].replace(words[o].size()-1, 1, "*");
            }
            words[o].replace(words[o].find("A"), 1, "E");
        }
        while (words[o].find("*") != string::npos) {
            words[o].replace(words[o].find("*"), 1, "A");
        }
    }

    ///Replace all occurrences of "OW" with "OO".
    for (int t=0; t<words.size(); t++) {
        while (wordsorig[t].find("OW") != string::npos) {
            words[t].replace(words[t].find("OW"), 2, "OO");
        }
    }

    ///Replace all occurrences of "O" with "U".
    for (int e=0; e<words.size(); e++) {
        while (wordsorig[e].find("O") != string::npos) {
            words[e].replace(words[e].find("O"), 1, "U");
        }
    }

    ///Replace the first occurrence of "I" other than at the start of a word with "EE".

    ///Replace all occurrences of "EN" at the end of a word with "EE"
    for (int v=0; v<words.size(); v++) {
        if (wordsorig[v].find_last_of("EN") == wordsorig[v].size()-1) {
            words[v].replace(words[v].find_last_of("EN"), 2, "EE");
        }
    }

    ///Replace all occurrences of "E" at the end of a word with "E-A"
    for (int y=0; y<words.size(); y++) {
        if (wordsorig[y].find_last_of("E") == wordsorig[y].size()-1) {
            words[y].replace(words[y].find_last_of("E"), 1, "E-A");
        }
    }

    ///Replace all occurrences of "E" at the start of a word with "I"
    for (int a=0; a<words.size(); a++) {
        if (wordsorig[a].find_first_of("E") == 0) {
            words[a].replace(words[a].find_first_of("E"), 1, "I");
        }
    }

    ///Replace all occurrences of "U" with "OO"
    for (int h=0; h<words.size(); h++) {
        while (wordsorig[h].find("U") != string::npos) {
            words[h].replace(words[h].find("U"), 1, "OO");
        }
    }*/

    for (int j=0; j<words.size(); j++) {
        temp = words[j].substr(0, words[j].size());
        finish.append(temp + " ");
    }

    return (finish);
}

void Swedish::print() {
    cout << "Original Phrase: " << phrase << endl;
    cout << "Swedish Chef Translation: " << swedPhrase << endl;
}

int main() {
    Swedish p;
    string orig, swed;

    ifstream readfile;
    readfile.open("H://C++/swedChef1.txt");
    getline (readfile, orig);
    readfile.close();
    p.setPhrase(orig);

    swed = p.translate(orig);
    //p.setSwed(swed);
    //p.print();

    /*readfile.open("H://C++/swedChef2.txt");
    getline (readfile, orig);
    readfile.close();
    p.setPhrase(orig);

    p.print();

    readfile.open("H://C++/swedChef3.txt");
    getline (readfile, orig);

    readfile.close();
    p.setPhrase(orig);

    p.print();

    readfile.open("H://C++/swedChef4.txt");
    getline (readfile, orig);
    readfile.close();
    p.setPhrase(orig);

    p.print();

    readfile.open("H://C++/swedChef5.txt");
    getline (readfile, orig);
    readfile.close();
    p.setPhrase(orig);

    p.print();*/

    return 0;
}
