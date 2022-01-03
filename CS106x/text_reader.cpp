#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cctype>
#include <chrono> //Platform Independent Library. For more accurate timing use platform specific Libs

#define TEXT_FILE "LOTR.txt"

using namespace std;

//Interesting Util Function - Timer
struct Timer
{
    chrono::time_point<chrono::steady_clock> start, end;
    chrono::duration<float> duration;

    Timer() {
        start = chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end =  chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count()*1000.0f;
        cout << ms << " milliseconds" << endl << endl; //Using 'endl' is slower than '\n' but platform independent
    }
};

void UNIQUE_WORDS_VECTOR()
{
    Timer timer; //this one line will give the benchmark for this function coz of the constructor-destructor lifecycle :D

    vector<string> words;

    ifstream file (TEXT_FILE); string word; while(file >> word) { //Iterate through the whole file
        bool exists = false;
        for(string w : words){
            if(w == word){
                exists = true;
                break;
            }
        }

        if(!exists) {
            words.push_back(word);
        }
    }

    cout << "UNIQUE_WORDS_VECTOR::Total Unique words = " << words.size() << endl;
}

void UNIQUE_WORDS_SET()
{
    Timer time;

    set<string> words;

    ifstream file (TEXT_FILE); string word; while(file >> word) {
        words.insert(word);
    }

    cout << "UNIQUE_WORDS_SET::Total Unique words = " << words.size() << endl;
}

void UNIQUE_WORDS_HASHSET()
{
    Timer time;

    unordered_set<string> words; //hashset

    ifstream file (TEXT_FILE); string word; while(file >> word) {
        words.insert(word);
    }

    cout << "UNIQUE_WORDS_HASHSET::Total Unique words = " << words.size() << endl;
}

void ANAGRAMS_SET(string w)
{
    Timer time;

    string input = w;
    //convert to lower case
    transform(w.begin(), w.end(), w.begin(),
              [](unsigned char c){ return tolower(c); });
    //sort it so it can be the key for the map
    sort(w.begin(), w.end());

    map<string, set<string>> anagrams;

    ifstream file (TEXT_FILE); string word; while(file >> word) {
        string key = word;
        //convert to lowercase
        transform(key.begin(), key.end(), key.begin(),
                  [](unsigned char c){ return tolower(c); });
        sort(key.begin(), key.end());
        anagrams[key].insert(word); //anagrams[key] returns a "set<string>" so we insert the word there
    }

    //print the set out
    cout << "ANAGRAMS_SET::Anagrams of the word '" << input << "' are: " << endl;
    for(string const& anagram : anagrams[w]) {
        cout << anagram << endl;
    }

   cout << "ANAGRAMS_SET::Size of SET is: " << anagrams.size() << endl;
}

void ANAGRAMS_HASHSET(string w)
{
    Timer time;

    string input = w;
    //convert to lower case
    transform(w.begin(), w.end(), w.begin(),
              [](unsigned char c){ return tolower(c); });
    //sort it so it can be the key for the map
    sort(w.begin(), w.end());

    unordered_map<string, set<string>> anagrams;

    ifstream file (TEXT_FILE); string word; while(file >> word) {
        string key = word;
        //convert to lowercase
        transform(key.begin(), key.end(), key.begin(),
                  [](unsigned char c){ return tolower(c); });
        sort(key.begin(), key.end());
        anagrams[key].insert(word); //anagrams[key] returns a "set<string>" so we insert the word there
    }

    //print the set out
    cout << "ANAGRAMS_HASHSET::Anagrams of the word '" << input << "' are: " << endl;
    for(string const& anagram : anagrams[w]) {
        cout << anagram << endl;
    }

   cout << "ANAGRAMS_HASHSET::Size of HASHSET is: " << anagrams.size() << endl;
}

int main()
{
    string word;

    //Total Unique Words - Vector
    UNIQUE_WORDS_VECTOR();

    //Total Unique Words - Set
    UNIQUE_WORDS_SET();

    //Total Unique words - HashSet [ Ideal ]
    UNIQUE_WORDS_HASHSET();

    cout << "Enter a word to check its anagrams in the text file: " << endl;
    cin >> word;
    cout << endl;

    //Anagrams of a given word in the book - Set
    ANAGRAMS_SET(word);

    //Anagrams of a given word in the book - HashSet [ Ideal ]
    ANAGRAMS_HASHSET(word);

    return 0;
}
