#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct SearchElement
{
    int money = 0;
    std::vector<int> coins;
};

std::vector<int> MoneyExchange(const std::vector<int> &coinValues, const int money)
{
    SearchElement firstElem;
    firstElem.money = money;
    std::vector<SearchElement> newVector{firstElem};

    while (!newVector.empty())
    {
        std::sort(newVector.begin(), newVector.end(), [](const SearchElement &a, const SearchElement &b) -> bool
        {
            return a.money > b.money;
        });
        size_t currLength = newVector.size();

        for (size_t i = 0; i < currLength; --currLength)
        {
            for (const int value: coinValues)
            {
                if (newVector[i].money < value)
                {
                    continue;
                }

                SearchElement newElem;
                newElem.money = newVector[i].money - value;
                newElem.coins = newVector[i].coins;
                newElem.coins.push_back(value);
                if (newElem.money == 0)
                {
                    return newElem.coins;
                }

                newVector.push_back(newElem);
            }

            newVector.erase(newVector.begin());
        }
    }

    return {};
}

void print(const std::vector<int> &coins)
{
    std::unordered_map<int, int> coinsMap;
    int valueCount = 0;
    for (const int value: coins)
    {
        if (coinsMap.find(value) != coinsMap.end())
        {
            coinsMap.at(value)++;

            continue;
        }

        valueCount++;
        coinsMap.insert(std::make_pair(value, 1));
    }

    std::cout << valueCount << ' ' << coins.size() << std::endl;

    for (const auto&[value, count]: coinsMap)
    {
        std::cout << value << ' ' << count << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    inputFile.open(argv[1]);

    if (!inputFile.is_open())
    {
        std::cout << "File does not open." << std::endl;
        return 1;
    }
    int money;
    inputFile >> money;
    int countVal;
    inputFile >> countVal;

    std::vector<int> coinValues;
    while (!inputFile.eof())
    {
        int number;
        inputFile >> number;
        coinValues.push_back(number);
    }

    std::vector<int> result;
    result = MoneyExchange(coinValues, money);

    print(result);

    return 0;
}
