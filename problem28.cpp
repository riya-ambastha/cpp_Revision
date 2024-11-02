 #include <iostream>
#include <sstream>
#include <vector>

bool isCircularSentence(std::string sentence) {
    // Split the sentence into words
    std::istringstream stream(sentence);
    std::vector<std::string> words;
    std::string word;
    
    while (stream >> word) {
        words.push_back(word);
    }

    
    for (size_t i = 0; i < words.size(); ++i) {
 
        char lastChar = words[i].back();
     
        char firstCharNext = words[(i + 1) % words.size()].front();
        
        if (lastChar != firstCharNext) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::string sentence1 = "leetcode exercises sound delightful";
    std::string sentence2 = "eetcode";
    std::string sentence3 = "Leetcode is cool";

    std::cout << (isCircularSentence(sentence1) ? "true" : "false") << std::endl; // Output: true
    std::cout << (isCircularSentence(sentence2) ? "true" : "false") << std::endl; // Output: true
    std::cout << (isCircularSentence(sentence3) ? "true" : "false") << std::endl; // Output: false

    return 0;
}
