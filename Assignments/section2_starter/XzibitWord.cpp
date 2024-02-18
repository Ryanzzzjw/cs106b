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
#include "lexicon.h"
#include <string>
using namespace std;

string mostXzibitWord(const Lexicon& words) {
    string result;
    int numSubwords = 0;

    for (string word: words) {
        Lexicon ourSubwords;

        for (int start = 0; start < word.length(); start++) {

            for (int stop = start; stop <= word.length(); stop++) {
                string candidate = word.substr(start, stop - start);

                if (!words.containsPrefix(candidate)) break;

                if (words.contains(candidate)) {
                    ourSubwords.add(candidate);
                }
            }
        }
        if (numSubwords < ourSubwords.size()) {
            result = word;
            numSubwords = ourSubwords.size();
        }
    }

    return result;

}

/* * * * * Provided Tests Below This Point * * * * */

static Lexicon& sharedLexicon() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

PROVIDED_TEST("Example from handout") {
    Lexicon& lex = sharedLexicon();
    EXPECT_EQUAL(mostXzibitWord(lex), "foreshadowers");
}
