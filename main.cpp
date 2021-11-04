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

void goFishing(const int* pond)
{
    std::cout << "Please enter the field row: ";
    std::string input;
    std::cin >> input;
    int row = std::stoi(input);

    std::cout << "Please enter the field column: ";
    input.clear();
    std::cin >> input;
    int col = std::stoi(input);

    if (*(pond + (row * 3) + col) == FISH) throw FishException();
    else if (*(pond + (row * 3) + col) == BOOT) throw BootException();
    else if (*(pond + (row * 3) + col) == NOTHING) throw NothingException();
}

void printPond(int* pond)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << *(pond + (i * 3) + j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "---------\n";
}


int main() {
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

    printPond((int*)pond);

    int turns {0};
    while (true)
    {
        try
        {
            goFishing((int*)pond);
        }
        catch (FishException)
        {

        }
        catch (BootException)
        {

        }
        catch (const NothingException& e)
        {

        }
        catch (...)
        {
            std::cout << "Something wrong!!!\n";
        }

    }

    return 0;
}