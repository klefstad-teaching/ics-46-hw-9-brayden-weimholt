#include "ladder.h"


void error(string word1, string word2, string msg){
    cout << "Error connecting " << word1 << " and " << word2 << "; " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int len1 = str1.length(), len2 = str2.length();
    if(abs(len1 - len2) > d) return false; //if differ by more than d chars, not within d


    if (len1 == len2) {
        int diff = 0;
        for (int i = 0; i < len1; ++i) {
            if (str1[i] != str2[i]) {
                ++diff;
                if (diff > d) return false; 
            }
        } return true; 
    }

    const string& shorter = (len1 < len2) ? str1 : str2;
    const string& longer = (len1 < len2) ? str2 : str1;

    int i = 0, j = 0, diff = 0;
    while (i < shorter.length() && j < longer.length()) {
        if (shorter[i] == longer[j]) {
            ++i;
            ++j;
        } else {
            ++diff;
            if (diff > d) {
                return false;
            }
            ++j; 
        }
    }

    return true;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    unordered_set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> current_ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = current_ladder.back();

        for (const string& word : word_list) {
            if (!visited.count(word) && is_adjacent(last_word, word)) {
                visited.insert(word);
                vector<string> new_ladder = current_ladder;
                new_ladder.push_back(word);

                if (word == end_word) {
                    return new_ladder;
                }

                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    if(!in.is_open()) error("", "", "Input file incorrectly named.");
    string word;
    while(in >> word){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder){
    if(ladder.empty()) cout << "No word ladder found."<< endl;
    else{
        cout << "Word ladder found:";
        for (size_t i = 0; i < ladder.size(); ++i) {
            cout << " " << ladder[i];
        }
        cout << endl;
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
    cout << endl;

}


