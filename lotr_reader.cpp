#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <chrono> //Platform Independent Library. For more accurate timing use platform specific Libs

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

    ifstream file ("lotr.txt"); string word; while(file >> word) { //Iterate through the whole file
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

    ifstream file ("lotr.txt"); string word; while(file >> word) {
        words.insert(word);
    }

    cout << "UNIQUE_WORDS_SET::Total Unique words = " << words.size() << endl;
}

void UNIQUE_WORDS_HASHSET()
{
    Timer time;

    unordered_set<string> words; //hashset

    ifstream file ("lotr.txt"); string word; while(file >> word) {
        words.insert(word);
    }

    cout<< "UNIQUE_WORDS_HASHSET::Total Unique words = " << words.size() << endl;
}

int main()
{
    //Total Unique Words - Vector
    UNIQUE_WORDS_VECTOR();

    //Total Unique Words - Set
    UNIQUE_WORDS_SET();

    //Total Unique words - HashSet [ Ideal ]
    UNIQUE_WORDS_HASHSET();

    //Total occurences of a given word - Vector

    //Total occurences of a given word - Set

    //Total occurences of a given work - HashSet

    //Anagrams of a given word in the book - Vector

    //Anagrams of a given word in the book - Set

    //Anagrams of a given word in the book - HashSet [ Ideal ]
    return 0;
}
