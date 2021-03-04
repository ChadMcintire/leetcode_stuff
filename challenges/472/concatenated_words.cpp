#include <vector>
#include <map>
#include <set>
#include <iostream>

class Solution {
public:
    //void check_current_words( std::string current word,  std::string findconcat){
        
    //}

    void print_map_keys(const std::map<int, std::set<std::string>>& maps){
        for (auto it = maps.begin(); 
             it != maps.end(); ++it){
                std::cout << "key = "<< it->first << "\n"; //<< " = "
        }
    }
    
    void sort_words_by_length(const std::vector<std::string>& vec){
        std::map<int, std::set<std::string>> length_map;
        for (auto word : vec){
            // not found
            if ( length_map.find(word.length()) == length_map.end() ) {
                std::set<std::string> unique_ordered_string;
                unique_ordered_string.insert(word);
                length_map.insert ( std::pair<int, std::set<std::string>>(word.length(), unique_ordered_string) );
            } 
             // not found
            else {
                length_map.find(word.length())->second.insert(word);
            }
        }


    print_map_keys(length_map);
    std::cout << "mymap.size() is " << length_map.size() << '\n';

}

    
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        sort_words_by_length(words);

        std::set<std::string> unique_ordered_string;
        for (auto word : words){
            unique_ordered_string.insert(word);
            for (auto findconcat : words){
                if (findconcat.length() >= word.length()){
                    //for(for i = 0; i < findconcat.length() - word.length(); i++){
                        
                    //}
                }   
                else{
                    
                }
            }
        }
        for (auto word : unique_ordered_string){
            std::cout << word << "\n";
        }
        
        return words;
    }
    

private:
    std::set<std::string> base;
    std::set<std::string> concatenated;
    std::string test_word;
};

int main(){
    std::vector<std::string> words {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"} ;  

Solution sol;
sol.findAllConcatenatedWordsInADict(words);
}
