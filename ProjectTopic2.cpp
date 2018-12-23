#include "ProjectTopic2.h"

#include <iostream>
#include <fstream>
#include <sstream>

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
    std::for_each(files.begin(),
                  files.end(),
                  [=](std::string &f)
                  {
                      f.insert(0, path);
                      f.insert(path.size(), 1, '/');
                  });

    ScrabbleWords scrabbleWords(files);

    std::string word("junk1");
    std::cout << "word value of " << word << " " << scrabbleWords.wordValue(word) << std::endl;

    Player player1;
    Player player2;
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
        words.insert(line);

        ++count;
    }

    return count;
}

Player::Player() :
    score(0)
{
}

void Player::addLetters(int numToAdd)
{
}
