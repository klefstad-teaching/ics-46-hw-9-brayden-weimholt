#include "ladder.h"


void error(string word1, string word2, string msg){
    cout << "Error connecting " << word1 << " and " << word2 << "; " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int len1 = str1.size(), len2 = str2.size();
    if(abs(len1 - len2) > d) return false; //if differ by more than d chars, not within d

    vector<vector<int>> ch_dist_table(len1 + 1, vector<int>(len2+1, 0));

    for (int i = 0; i <= len1; ++i) 
        ch_dist_table[i][0] = i;  //deletions

    for (int j = 0; j <= len2; ++j) 
        ch_dist_table[0][j] = j;  //insertions

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                // Characters match: no cost
                ch_dist_table[i][j] = ch_dist_table[i - 1][j - 1];
            } else {
                ch_dist_table[i][j] = min({ch_dist_table[i - 1][j] + 1,   // Deletion
                                ch_dist_table[i][j - 1] + 1,   // Insertion
                                ch_dist_table[i - 1][j - 1] + 1}); // Substitution
            }
        } 
    }
    return ch_dist_table[len1][len2] == d;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

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


