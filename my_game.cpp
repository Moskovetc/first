#include <iostream>
#include <vector>

using namespace std;

enum difficulty
{
    EASY,
    NORMAL,
    HARD
};

string convertDifficultyToString(unsigned short difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return "EASY";
    case NORMAL:
        return "NORMAL";
    case HARD:
        return "HARD";
    default:
        return "UNDEFINED";
    }
};


/*Init game configuration
 *
 */
class Config
{
private:
    string m_gameTitle = Config::DEFAULT_GAME_TITLE;
    uint m_maxScore = Config::DEFAULT_MAX_SCORE;
    difficulty m_gameDifficulty = Config::DEFAULT_GAME_DIFFICULTY;
    vector<difficulty> m_availableDifficulties = Config::AVAILABLE_GAME_DIFFICULTIES;
    bool m_printConfigEnabled = Config::DEFAULT_INIT_CONFIG_PRINT_ENABLED;

    void printUnsupportedConfigAndExit(unsigned short gameDifficulty)
    {
        cout << "Unsupported difficulty: " << convertDifficultyToString(gameDifficulty) << endl;
        cout << "Choose one of: ";
        vector<difficulty>::iterator difficultyIterator;
        vector<difficulty>::const_iterator iter;
        for (iter = AVAILABLE_GAME_DIFFICULTIES.begin(); iter != AVAILABLE_GAME_DIFFICULTIES.end(); ++iter)
        {
            cout << convertDifficultyToString(*iter) + " ";
        };
        cout << endl;

        exit(-1);
    };

public:
    static const string DEFAULT_GAME_TITLE;
    static const uint DEFAULT_MAX_SCORE;
    static const difficulty DEFAULT_GAME_DIFFICULTY;
    static const bool DEFAULT_INIT_CONFIG_PRINT_ENABLED;
    static const vector<difficulty> AVAILABLE_GAME_DIFFICULTIES;

    ~Config();

    const string& getGameTitle() const;
    void setGameTitle(const string& title);
    uint getMaxScore() const;
    void setMaxScore(uint maxScore);
    difficulty getGameDifficulty() const;
    vector<difficulty> getAvailableDifficulties();
    void setGameDifficulty(difficulty gameDifficulty);
    void setGameDifficulty(unsigned short gameDifficulty);
    bool isPrintConfigEnabled();
    void toString();
};

Config::~Config()
{
}

const string& Config::getGameTitle() const
{
    return m_gameTitle;
};

void Config::setGameTitle(const string& title)
{
    this->m_gameTitle = title;
};

uint Config::getMaxScore() const
{
    return m_maxScore;
}

void Config::setMaxScore(uint maxScore)
{
    m_maxScore = maxScore;
}

difficulty Config::getGameDifficulty() const
{
    return m_gameDifficulty;
}

vector<difficulty> Config::getAvailableDifficulties()
{
    return m_availableDifficulties;
}
;

void Config::setGameDifficulty(difficulty gameDifficulty)
{
    this->m_gameDifficulty = gameDifficulty;
};

void Config::setGameDifficulty(unsigned short gameDifficulty)
{
    switch (static_cast<difficulty>(gameDifficulty))
    {
    case EASY:
        this->m_gameDifficulty = static_cast<difficulty>(gameDifficulty);
        break;
    case NORMAL:
        this->m_gameDifficulty = static_cast<difficulty>(gameDifficulty);
        break;
    case HARD:
        this->m_gameDifficulty = static_cast<difficulty>(gameDifficulty);
        break;
    default:
        printUnsupportedConfigAndExit(gameDifficulty);
        break;
    }
};

bool Config::isPrintConfigEnabled()
{
    return m_printConfigEnabled;
}

void Config::toString()
{
    cout << "====================================" << endl;
    cout << "Init game configuration:" << endl;
    cout << "Game difficulty:" << convertDifficultyToString(this->m_gameDifficulty) << endl;
    cout << "====================================" << endl;
    cout << endl;
}

const string Config::DEFAULT_GAME_TITLE = "The Game";
const uint Config::DEFAULT_MAX_SCORE = 100;
const difficulty Config::DEFAULT_GAME_DIFFICULTY = NORMAL;
const bool Config::DEFAULT_INIT_CONFIG_PRINT_ENABLED = true;
const vector<difficulty> Config::AVAILABLE_GAME_DIFFICULTIES = { EASY, NORMAL, HARD };

void askQuitGame();
string convertDifficultyToString(difficulty difficulty);

int main()
{
    typedef unsigned int uint;

    Config config;

    /*main menu*/
    cout << "welcome to the '" + config.getGameTitle() + "'" << endl;
    cout << endl << endl;
    cout << "Difficulties: " << endl;
    // BUG: баг с цказателем на константу
    for (vector<difficulty>::iterator iter = config.getAvailableDifficulties().begin(); iter != config.getAvailableDifficulties().end(); ++iter)
    {
        cout << static_cast<unsigned short>(*iter) << ") " << convertDifficultyToString(static_cast<unsigned short>(*iter)) << endl;
    }

    cout << "Choose game difficulty: ";
    unsigned short userDifficulty = 0;
    cin >> userDifficulty;
    config.setGameDifficulty(userDifficulty);

    if (config.isPrintConfigEnabled())
    {
        config.toString();
    };

    /*Start game blok*/
    uint score = 0;
    do
    {
        cout << "time(0): " << time(0) << endl;
        typedef unsigned short ushort;
        ushort dice1 = 0;
        ushort dice2 = 0;
        srand(static_cast<unsigned int>(time(0)));
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        cout << "thrown dices: " << dice1 << " " << dice2 << endl;
        score += dice1 + dice2;
        cout << "score: " << score << endl;

        if (score >= config.getMaxScore())
        {
            cout << "Game ended, you riched score " << config.getMaxScore() << " or more " << endl;
            break;
        }

        askQuitGame();
    } while (true);
    return 0;
}

void askQuitGame()
{
    char quitGame;
    cout << "quit game? y/n: ";
    cin >> quitGame;

    while (quitGame != 'y' && quitGame != 'n')
    {
        cout << "\ninput value should be y or n" << endl;
        cout << "quit game? y/n: ";
        cin >> quitGame;
    }

    if (quitGame == 'y')
    {
        exit(-1);
    }
}