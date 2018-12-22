#include <string>
#include <set>
#include <map>

const int LETTERS_IN_ALPHABET = 27;
const int MAX_PLAYER_LETTERS = 5;

class ScrabbleWords
{
public:
    ScrabbleWords(const std::string& filename);

    bool isValidWord(const std::string& candidate);

    int wordValue(const std::string& candidate);

private:

    std::set<std::string> words;

    int values[LETTERS_IN_ALPHABET];
    int distro[LETTERS_IN_ALPHABET];

    int letterValue(char letter);
};

class Player
{
public:
    Player();

    void addLetters(int numToAdd);

private:
    char letters[MAX_PLAYER_LETTERS];
    int score;
};
