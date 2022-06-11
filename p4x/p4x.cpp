/**
 * TODO: Implement P4 extra-credit.
 * I was really tired, so I never came back for this
 */

// Using p4 as Extra Credit towards my final grade
//
// Author: Uchenna Nwoke
//
#include "WordCounterx.h"
#include "CommonWordListx.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

string cleanWord(string);

void removeCommonWords(WordCounterx &);
/**
 * Function to print the uniqueWordCount, totalWordCount, and
 * loadFactor of a word counter
 * @param wc an instance of WordCounterx
 */
void printStats(WordCounterx &wc);

/**
 * Function to print the analysis of a single word in a
 * word counter and then remove it
 * @param wc   an instance of WordCounterx
 * @param word the word to analyze and remove
 */
void analyzeWord(WordCounterx &wc, const string &word);

/**
 * Function that process the text from a file into a word counter instance.
 * @param wc       an instance of WordCounterx
 * @param filepath the path to the file the client wants to process
 */
void processFile(WordCounterx &wc, const std::string &filepath);

/**
 * Function to prompt user for filename and capacity, process the file,
 * and prompt for word to analyze
 */
void wordCounterDriver();


const char APOSTROPHE_CHAR = '\''; 	// apostrophe character used in cleanWord
const char HYPHEN_CHAR = '-'; 		// hyphen/dash character used in cleanWord
int testCount = 1;
int main() {
    // populate common words
    CommonWordListx::populateWords();

    int choice = 1;

    cout << "Welcome to word counter!" << endl << endl;

    while (choice != 0) {
        wordCounterDriver();
        cout << "Enter 0 to quit" << endl;
        cin >> choice;
    }

    return 0;
}

string cleanWord(string s) {
   string result = "";                  // Keep track of the cleaned result.
   unsigned i = 0, length = s.length(); // Input for the for loop.
   for (; i < length; i++) {
      if (isalnum(s[i])) 
         result += tolower(s[i]);
      else if (s[i] == APOSTROPHE_CHAR) {
         if (i > 0 && isalnum(s[i-1]))
            result += s[i];
      } else if (s[i] == HYPHEN_CHAR) {
         if (i > 0 && i < (length-1) && isalnum(s[i-1]) && isalnum(s[i+1]))
            result += s[i];
			// If a word ends in a hyphen, we assume it is residue that needs to
			// be paired with the next word. Return the word with the hyphen as a
			// signal to the caller to retain it as residue.
         else if (i > 0 && i == (length-1) && isalnum(s[i-1]))
            result += s[i];
      }
   }
   return result;
}

void removeCommonWords(WordCounterx &wc) {
   for (string &s : CommonWordListx::getWords())
      wc.removeWord(s);
}

void printStats(WordCounterx &wc) {
    cout << setw(10) << wc.getUniqueWordCount() ;
    cout << setw(10) << wc.getTotalWordCount();
    cout << setw(10) <<std::setprecision(3) << fixed << wc.getLoadFactor();
    cout << endl;
}

void analyzeWord(WordCounterx &wc, const string &word) {
    cout << setw(13 ) << word;
    cout <<setw(9) << wc.getWordCount(word) << endl;
    wc.removeWord(word);
}

void processFile(WordCounterx &wc, const std::string &filepath) {
    string word, splitWord;
    ifstream inFile;
    vector<string> stopWords = CommonWordListx::getWords();
    inFile.open(filepath);

    if(inFile.is_open()) {
        while (inFile >> word) {
            if (word[word.length() - 1] == '-'){
                inFile >> splitWord;
                word = word.substr(0, word.length() -1);
                word.append(splitWord);
            }

            word = cleanWord(word);
            wc.addWord(word);
        }
        for (string common: stopWords)
            wc.removeWord(common);
        cout << "  #Unique   #Total   Load Factor \n"
                "+---------+--------+-------------+" << endl;
        printStats(wc);
    } else {
        cout << "ERROR: cannot open file";
        return;
    }
}


void wordCounterDriver() {
    string filepath;
    int capacity;

    cout << "*********************\n"
            "*   Test file #" << testCount++ << ":   *\n"
            "*********************\n\n";

    cout << "What is the filename: ";
    cin >> filepath;
    cout << "What is the capacity: ";
    cin >> capacity;

    WordCounterx wc(capacity);
    processFile(wc, filepath);
    cout << endl;

    cin.ignore();
    cout << "Enter Words (seperated by space): " << endl;
    string word, in;
    vector<string> wordList;
    getline(cin,in);
    istringstream iss(in);
    while(iss >> word) {
        wordList.push_back(word);
    }

    cout << "Analysis of words : " << endl;
    cout << "Given Word   Count" << endl;
    cout << "+------------+-------+" << endl;
    for (string s: wordList) {
        analyzeWord(wc, s);
    }

    cout << endl;
    cout << "  #Unique   #Total   Load Factor \n"
            "+---------+--------+---------+" << endl;
    printStats(wc);
    cout << endl;
}
