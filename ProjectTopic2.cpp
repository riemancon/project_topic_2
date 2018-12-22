#include "ProjectTopic2.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int /* argc */, char** /* argv */)
{
    ScrabbleWords scrabbleWords("scrabble_words.txt");

    Player player1;
    Player player2;
}

ScrabbleWords::ScrabbleWords(const std::string& filename) :
    //      a, b, c, d,  e, f, g, h, i, j, k, l, m, n, o, p,  q, r, s, t, u, v, w, x, y,  z, blank
    values{ 1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0},
    distro{ 9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2,  1, 6, 4, 6, 4, 2, 2, 1, 2,  1, 2}
{
    std::ifstream infile(filename);

    std::string line;
    //int lineno = 0;
    while (std::getline(infile, line))
    {
        //++lineno;

        if (line[0] == '#' || line.length() == 0)
        {
            //std::cout << "Skipping line " << lineno << " -> " << line << std::endl;
            continue;
        }

        //std::cout << "Adding line " << lineno << " -> " << line << std::endl;
        words.insert(line);
    }
}

int ScrabbleWords::letterValue(char letter)
{
    return values[tolower(static_cast<int>(letter)) - 'a'];
}

int ScrabbleWords::wordValue(const std::string& candidate)
{
    int value = 0;

    if (isValidWord(candidate))
    {
        for (unsigned int idx = 0; idx < candidate.length(); ++idx)
        {
            value += letterValue(candidate[idx]);
        }
    }

    return value;
}

bool ScrabbleWords::isValidWord(const std::string& candidate)
{
    return words.find(candidate) != words.end();
}

Player::Player() :
    score(0)
{
}

void Player::addLetters(int numToAdd)
{
}
