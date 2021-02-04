#ifndef MSTRING_H
#define MSTRING_H

#include <iostream>
#include <vector>

using namespace std;

class String : string {
    private:
        string str;

    public:
        String(string _str) { str = _str; }
        vector<string> split(string regex);
        /*
        vector<string> split(char regex) {
            vector<string> vct;
            unsigned int relstart = 0;
            for (unsigned int i = 0; i < str.size(); i++) {
                if (str[i] == regex) {
                    // Substring nd add to the vector
                    vct.push_back(getSubstring(relstart, i));
                    relstart = i;
                }
            }
            vct.push_back(getSubstring(relstart, str.size()));
            return vct;
        }
        */
        string getSubstring(unsigned int idxStart, unsigned int end) {
            string result = "";
            for (unsigned int i = start; i < end; i++) {
                result += str[i];
            }
            return result;
        }
        
};
