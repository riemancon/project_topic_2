#include "ProjectTopic2.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>

#define xstr(s) str(s)
#define str(s) #s

//                                      a, b, c, d,  e, f, g, h, i, j, k, l, m, n, o, p,  q, r, s, t, u, v, w, x, y,  z, blank
std::vector<int> ScrabbleWords::values{ 1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
std::vector<int> ScrabbleWords::distro{ 9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2,  1, 6, 4, 6, 4, 2, 2, 1, 2,  1, 2};

int main(int /* argc */, char** /* argv */)
{
    std::string path(xstr(SOURCE_PATH));

    std::vector<std::string> files{"scrabble_words_two_three_letters.txt",
                                   "scrabble_words_four_letters.txt",
                                   "scrabble_words_five_letters.txt"};

    // prepend the path
    std::for_each(files.begin(),
                  files.end(),
                  [=](std::string &f)
                  {
                      f.insert(0, path);
                      f.insert(path.size(), 1, '/');
                  });

    ScrabbleWords scrabbleWords(files);

    std::vector<Player> players{Player("player1"), Player("player2")};
    int selector = 0;
    while (1)
    {
        bool validOption = true;

        std::string tempword;

        promptForWord(players[selector].getName(), tempword);

        if (tempword.size() >= 2 && tempword.size() <= 5)
        {
            int value = scrabbleWords.wordValue(tempword);
            if (value)
            {
                std::cout << "word value of " << tempword << " " << value << std::endl;
            }
            else
            {
                std::cout << "'" << tempword << "' is not a word" << std::endl;
            }

            players[selector].addScore(value);

            // switch player
            selector ^= 1;
        }
        else
        {
            if (tempword.size() == 1)
            {
                switch (tolower(tempword.at(0)))
                {
                case 'h':
                    std::cout << "help" << std::endl;
                    break;
                case 'p':
                    std::cout << "pass" << std::endl;
                    selector ^= 1;
                    break;
                case 'x':
                    std::cout << std::endl << "Game over" << std::endl;
                    for (auto& p : players)
                    {
                        p.print();
                    }
                    exit(0);    
                    break;
                case 's':
                    for (auto& p : players)
                    {
                        p.print();
                    }
                    break;
                default:
                    std::cout << "unknown option" << std::endl;
                    validOption = false;
                break;
                }
            }

            if (!validOption)
            {
                std::cout << "word size must be between 2 and 5 letters, try again" << std::endl;
            }
        }
    }
}

ScrabbleWords::ScrabbleWords(std::string filename)
{
    if (!filename.empty())
    {
        int count = loadWords(filename);

        std::cout << "loaded " << count << " words from " << filename << std::endl;
    }
}

ScrabbleWords::ScrabbleWords(const std::vector<std::string>& filenames)
{
    int num_tiles = 0;
    for (auto& n : distro)
    {
        num_tiles += n;
    }
    std::cout << "number of tiles is " << num_tiles << std::endl;
 
    for (const std::string& filename : filenames)
    {
        int count = loadWords(filename);

        std::cout << "loaded " << count << " words from " << filename << std::endl;
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

int ScrabbleWords::loadWords(const std::string& filename)
{
    std::ifstream infile(filename);

    std::string line;
    //int lineno = 0;
    int count = 0;

    while (std::getline(infile, line))
    {
        //++lineno;

        if (line[0] == '#' || line.length() == 0)
        {
            //std::cout << "Skipping line " << lineno << " -> " << line << std::endl;
            continue;
        }

        //std::cout << "Adding line " << lineno << " -> " << line << std::endl;
        std::transform(line.begin(), line.end(), line.begin(), tolower);
        words.insert(line);

        ++count;
    }

    return count;
}

Player::Player(const std::string& _name) :
    score(0),
    name(_name)
{
}

void Player::addLetters(int numToAdd)
{
}

void Player::addScore(int value)
{
    score += value;
}

void Player::print()
{
    std::cout << "Player " << name << " score " << score << std::endl;
}

void promptForWord(const std::string& name, std::string& tempword)
{
    std::cout << "Player " << name << ", enter a word, 2-5 letters.  'H' for help, 'P' to pass turn, 'X' to exit: ";

    getline(std::cin, tempword);

    std::transform(tempword.begin(), tempword.end(), tempword.begin(), tolower);
}
