#include <string>
#include <set>
#include <map>
#include <vector>

const int LETTERS_IN_ALPHABET = 27;
const int MAX_PLAYER_LETTERS = 5;

class ScrabbleWords
{
public:
    ScrabbleWords(std::string filename = "");
    ScrabbleWords(const std::vector<std::string>& filenames);

    bool isValidWord(const std::string& candidate);

    int wordValue(const std::string& candidate);

private:

    std::set<std::string> words;

    static std::vector<int> values;
    static std::vector<int> distro;

    int letterValue(char letter);

    int loadWords(const std::string& filename);
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
