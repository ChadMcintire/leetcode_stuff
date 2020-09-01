#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()){
        return "";
    }

    int minSize = strs.front().size();

    for(string i : strs) {
        if (i.size() < minSize){
            minSize = i.size();
        }
    }

    if (minSize == 0){
        return "";
    }

    if (minSize == 1 && strs.size() == 1){
        return strs[0];
    }


    char firstChar = strs.front()[0];
    if (minSize == 1 && strs.size() > 1){
        for(string i : strs) {
            if (i[0] != firstChar){
                return "";
            }
        }

        string convChar(1, firstChar);
        return convChar;
    }

    bool stop = true;
    string final = "";
    for (int it=0; it<minSize; it++)
    {
        char current_string = strs.front()[it]; 
        for(string i : strs) {
            if (i[it] != current_string)
            {
                stop = false;
                break;
            }
            if (minSize == 1)
            {
                break;
            }
        }
        if (stop != false){
            final += current_string;
        }
        else{
            break;
        }

    }

    return final;
    }
};

int main(){
    //std::vector<std::string> testString = {"flower","flow","flight"};
    //std::vector<std::string> testString = {"aa", "aa"};
    
    std::vector<std::string> testString = {"aa", "a"};
    //std::vector<std::string> testString = {"a", "a"};
    //std::vector<std::string> testString = {"a"};
    Solution sol;
    sol.longestCommonPrefix(testString);
} 
