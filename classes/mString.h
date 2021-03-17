#ifndef MSTRING_H
#define MSTRING_H

#include <iostream>
#include <vector>

using namespace std;

class String : string {
    private:
        string str;

    public:
        //String(string _str) { str = _str; }
        void operator=(const string &_str) {
            str = _str;
        }

        vector<string> split(string regex) {
            vector<string> vct;
            unsigned int relstart = 0;
            for (unsigned int i = 0; i < str.size(); i++) {
                // Substring nd add to the vector
                if (str[i] == regex[0]) {
                    if (getSubstring(i, regex.size()+i) == regex) {
                        vct.push_back(getSubstring(relstart, i));
                        relstart = i + regex.size();
                    }
                }
            }
            vct.push_back(getSubstring(relstart, str.size()));
            return vct;
        }
        
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
        
        string getSubstring(unsigned int idxStart, unsigned int end) {
            string result = "";
            for (unsigned int i = idxStart; i < end; i++) {
                result += str[i];
            }
            return result;
        }

        string replaceAll(string regex, string replacement) {
            string result = str;
            for (unsigned int i = 0; i < result.size(); i++) {
                // We check if the first char of regex matches with curr char
                int relstart = 0;
                if (str[i] == regex[0]) {
                    if (regex == getSubstring(i, regex.size()+i)) {
                        result = getSubstring(relstart, i) + replacement
                            + getSubstring(regex.size()+i, result.size());
                        relstart = i+replacement.size();
                    }
                }
            }
            return result;
        }

        string replaceAll(char regex, char replacement) {
            string result = str;
            int relstart = 0;
            for (unsigned int i = 0; i < result.size(); i++) {
                if (str[i] == regex) {
                    result = getSubstring(relstart, i) + replacement
                        + getSubstring(i+1, result.size());
                }
            }
            return result;
        }
        
};
#endif // MSTRING_H
