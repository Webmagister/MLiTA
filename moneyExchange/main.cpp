/*
    4.6. Размен денег (6)
    Требуется разменять заданную сумму денег минимальным количеством монет.

    Ввод. Первая строка файла INPUT.TXT содержит сумму денег L (1 ≤ L ≤ 1500) и количество
    типов монет N (1 ≤ N ≤ 20). Вторая строка содержит N значений C i через пробел: стоимости типов
    монет (1 ≤ C i ≤ 1000).

    Вывод. В первой строке выводится количество типов монет K, необходимое для размена, и
    общее минимальное количество монет M. В следующих K строках выводятся через пробел по 2
    числа: стоимость монеты и количество экземпляров данной монеты. Эти K строк должны
    выводится в порядке убывания стоимости монет. Если имеется несколько вариантов решения,
    достаточно вывести любой из них. Если указанную сумму разменять невозможно, то выходной
    файл должен содержать No.

    Атайкин Павел, ПС-21.
    Среда: Clion, компилятор: CMake
*/
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <map>

void GetResult(int i, const std::vector<int> &p, std::map<int, int> &result)
{
    if (i == 0)
    {
        return;
    }
    GetResult(i - p[i], p, result);

    if (result.find(p[i]) != result.end())
    {
        result.at(p[i]) += 1;
    }
    else
    {
        result.insert(std::pair<int, int>(p[i], 1));
    }
}

int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    inputFile.open(argv[1]);

    std::ofstream outputFile;
    outputFile.open(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cout << "File does not open." << std::endl;
        return 1;
    }
    int money = 0;
    inputFile >> money;
    int countVal = 0;
    inputFile >> countVal;

    std::vector<int> coinValues;
    while (!inputFile.eof())
    {
        int number = 0;
        inputFile >> number;
        coinValues.push_back(number);
    }

    std::vector<int> d(money + 1);
    std::vector<int> p(money + 1);

    d[0] = 0;
    for (int i = 1; i <= money; i++)
    {
        d[i] = 10000;
        for (int j = 0; j < countVal; j++)
        {
            if (i - coinValues[j] >= 0 && d[i - coinValues[j]] + 1 < d[i])
            {
                d[i] = d[i - coinValues[j]] + 1;
                p[i] = coinValues[j];
            }
        }
    }

    std::map<int, int> result;
    if (d[money] == 10000)
    {
        outputFile << "No." << std::endl;

        return 0;
    }
    GetResult(money, p, result);

    outputFile << result.size() << " " << d[money] << std::endl;

    for (auto iter = result.rbegin(); iter != result.rend(); ++iter)
    {
        outputFile << iter->first << " " << iter->second << std::endl;
    }

    return 0;
}
