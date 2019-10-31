#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;


string get_normalize_word(string& word) {
    string normalized_word(word);

    for (int i = 0; i < word.size(); ++i) {
        normalized_word[i] = tolower(normalized_word[i]);
    }

    sort(normalized_word.begin(), normalized_word.end());

    return normalized_word;
}


int main() {
    vector<pair<string, string>> words_with_norms;

    string in_word;

    cin >> in_word;
    while (in_word != "#") {
        words_with_norms.emplace_back(in_word, get_normalize_word(in_word));
        cin >> in_word;
    }


    unordered_set<string> not_unique_norms;
    unordered_map<string, string> unique_words_with_norms_map;
    for (auto& word_with_norm : words_with_norms) {
        string& word = word_with_norm.first;
        string& norm = word_with_norm.second;

        if (not_unique_norms.find(norm) != not_unique_norms.end()) continue;

        if (unique_words_with_norms_map.find(norm) == unique_words_with_norms_map.end()) {
            unique_words_with_norms_map[norm] = word;
        } else {
            unique_words_with_norms_map.erase(norm);
            not_unique_norms.insert(norm);
        }
    }


    vector<string> anagrams;
    anagrams.reserve(unique_words_with_norms_map.size());

    for (auto& word_with_norm : unique_words_with_norms_map) {
        anagrams.push_back(word_with_norm.second);
    }


    sort(anagrams.begin(), anagrams.end());


    for (auto& anagram : anagrams) {
        cout << anagram << '\n';
    }
}
