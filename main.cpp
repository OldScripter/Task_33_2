#include <iostream>
#include <random>
#include "include/FishException.h"
#include "include/BootException.h"
#include "include/NothingException.h"

const int MAX_BOOTS = 3;

enum Containment
{
    NOTHING = 0,
    FISH = 1,
    BOOT = 2
};

/**
 * @function Main game logic (1 turn).
 * @throws FishException, BootException, NothingException, InvalidException
 * @param [in] pond int[3][3]
 */
void goFishing(const int* pond)
{
    std::cout << "Please enter the field row:\n";
    std::string input;
    std::cin >> input;
    int row = std::stoi(input);
    if (row < 1 || row > 3) throw std::invalid_argument("invalid argument: row");

    std::cout << "Please enter the field column:\n";
    input.clear();
    std::cin >> input;
    int col = std::stoi(input);
    if (col < 1 || col > 3) throw std::invalid_argument("invalid argument: col");

    if (*(pond + ((row - 1) * 3) + col - 1) == FISH) throw FishException();
    else if (*(pond + ((row - 1) * 3) + col - 1) == BOOT) throw BootException();
    else if (*(pond + ((row - 1) * 3) + col - 1) == NOTHING) throw NothingException();
}

/**
 * @function Print the pond filed in the console.
 * @param [in] pond int[3][3]
 */
void printPond(const int* pond)
{
    std::cout << "  | 1 2 3\n";
    std::cout << "---------\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < 3; ++j)
        {
            std:: cout << *(pond + (i * 3) + j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "---------\n";
    std::cout << "0 - empty\n";
    std::cout << "1 - fish\n";
    std::cout << "2 - boot\n";
}

int main() {

    //Preparing the pond:
    srand(time(nullptr));
    int pond[3][3] {NOTHING};

    int fishRow = rand() % 3;
    int fishCol = rand() % 3;

    pond[fishRow][fishCol] = FISH;

    int bootRow {0};
    int bootCol {0};
    for (int i = 0; i < MAX_BOOTS; ++i)
    {
        while (true)
        {
            bootRow = rand() % 3;
            bootCol = rand() % 3;
            if (bootCol == fishCol && bootRow == fishRow) continue;
            else break;
        }
        pond[bootRow][bootCol] = BOOT;
    }

    //Start game:
    printPond((int*)pond);
    int turns {0};
    while (true)
    {
        ++turns;
        try
        {
            goFishing((int*)pond);
            break;
        }
        catch (const FishException& e)
        {
            std::cout << e.what() << "\n";
            std::cout << "It takes " << turns << " turns.\n";
            break;
        }
        catch (const BootException& e)
        {
            std::cout << e.what() << "\n";
            std::cout << "Game over.\n";
            break;
        }
        catch (const NothingException& e)
        {
            std::cout << e.what() << "\n";
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << "\n";
        }
        catch (...)
        {
            std::cout << "Unexpected error.\n";
            break;
        }
    }
    return 0;
}