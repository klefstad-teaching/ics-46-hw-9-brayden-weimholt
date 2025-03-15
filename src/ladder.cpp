#include "ladder.h"


void error(string word1, string word2, string msg){
    cout << "Error connecting " << word1 << " and " << word2 << "; " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d);

bool is_adjacent(const string& word1, const string& word2);

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> current_ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = current_ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word) && !visited.count(word)) {
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

void load_words(set<string> & word_list, const string& file_name);

void print_word_ladder(const vector<string>& ladder);

void verify_word_ladder();


