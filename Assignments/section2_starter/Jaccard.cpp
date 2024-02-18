/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified for Qt and Ed by Neel
 * Kishnani for Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include "testing/SimpleTest.h"
#include "set.h"
#include "queue.h"
#include "tokenscanner.h"
#include "simpio.h"
#include "filelib.h"
using namespace std;

/*
 * See Stanford library's promptUserForFile function to get
 * a file into a stream format:
 * https://web.stanford.edu/dept/cs_edu/resources/cslib_docs/filelib.html#Function:promptUserForFile
 */

string queueToString(Queue<string> kGram) {
    string result;
    while (!kGram.isEmpty()) {
        if (result != "") result += " ";
        result += kGram.dequeue();
    }

    return result;
}

Set<string> kGramsIn(istream& input, int k) {
    if (k <= 0) error("k must be positive.");

    TokenScanner scanner(input);
    scanner.addWordCharacters("'");

    Queue<string> kGram;
    Set<string> result;

    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (scanner.getTokenType(token) == scanner.WORD) {
            kGram.enqueue(token);
        }

        if (kGram.size() == k) {
            result.add(queueToString(kGram));
            kGram.dequeue();
        }
    }

    return result;

}

Set<string> wordsIn(istream& input) {
    return kGramsIn(input, 1);
}

int chooseKGramSize() {
    while (true) {
        int result = getInteger("Enter k: ");
        if (result > 0) return result;

        cout << "Please enter a positive integer," << endl;
    }
}

Set<string> contentOfUserFileChoice(int k) {
    ifstream input;
    promptUserForFile(input, "Enter filename: ");
    return kGramsIn(input, k);
}

int main() {
    int k = chooseKGramSize();
    Set<string> s1 = contentOfUserFileChoice(k);
    Set<string> s2 = contentOfUserFileChoice(k);

    double intersectSize = (s1 * s2).size();
    double unionSize = (s1 + s2).size();

    cout << "Jaccard Similarity: " << intersectSize / unionSize << endl;
    return 0;
}

