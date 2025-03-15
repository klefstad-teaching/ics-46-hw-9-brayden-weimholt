#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");


    //cout << "Running test cases..." << endl;
    //verify_word_ladder();
    //cout << "Test cases completed." << endl;

    string begin_word, end_word;
    cout << "\nEnter the start word: ";
    cin >> begin_word;
    transform(begin_word.begin(), begin_word.end(), begin_word.begin(), ::tolower);

    cout << "Enter the end word: ";
    cin >> end_word;
    transform(end_word.begin(), end_word.end(), end_word.begin(), ::tolower);

    if (begin_word == end_word) {
        error(begin_word, end_word, "Start and end words must be different.");
        return 0;
    }

    if (word_list.find(end_word) == word_list.end()) {
        error(begin_word, end_word, "End word is not in the dictionary.");
        return 0;
    }

    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);
    print_word_ladder(ladder);

    return 0;
}