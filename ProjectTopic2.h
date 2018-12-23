#include <string>
#include <set>
#include <map>
#include <vector>

const int LETTERS_IN_ALPHABET = 27;
const int MAX_PLAYER_LETTERS = 5;

void promptForWord(const std::string& name, std::string& tempword);

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
    Player(const std::string& name);

    void addLetters(int numToAdd);

    void addScore(int value);

    void print();

    std::string getName() { return name; }

private:
    char letters[MAX_PLAYER_LETTERS];
    int score;
    std::string name;
};
