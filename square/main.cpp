/*
    7.3. Прямоугольники 1(8)
    На координатной плоскости задано N прямоугольников со сторонами, параллельными
    координатным осям. Найти площадь фигуры, получающейся в результате объединения
    прямоугольников.

    Ввод из файла INPUT.TXT. В первой строке содержится значение N (1 ≤ N ≤ 500). В каждой из
    следующих N строк – четыре целых числа A i , B i , C i , D i через пробел, определяющие координаты
    левого верхнего и правого нижнего углов очередного прямоугольника (-10 6 ≤ A i , B i , C i , D i ≤ 10 6 ; A i
    ≤ C i ; B i ≥ D i ).

    Вывод в файл OUTPUT.TXT единственного целого числа – площади фигуры.

    Атайкин Павел, ПС-21.
    Среда: Clion, компилятор: CMake
*/
#include <iostream>
#include <fstream>
#include <ostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

bool Inner(int minValue, int value, int maxValue)
{
    return minValue <= value && value <= maxValue;
}

struct Rect
{
    int x1, y1;
    int x2, y2;

    Rect()
    {}

    Rect(int X1, int Y1, int X2, int Y2) : x1(X1), y1(Y1), x2(X2), y2(Y2)
    {}

    void FillRec(std::ifstream &inputFile)
    {
        inputFile >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) std::swap(x1, x2);
        if (y1 > y2) std::swap(y1, y2);
    }

    int Square()
    {
        return (x2 - x1) * (y2 - y1);
    }

    bool IsExist(Rect r)
    {
        return
                Inner(x1, r.x1, x2) && Inner(x1, r.x2, x2) &&
                Inner(y1, r.y1, y2) && Inner(y1, r.y2, y2);

    }
};

int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    inputFile.open(argv[1]);

    std::ofstream outputFile;
    outputFile.open(argv[2]);

    std::vector<Rect> mas;
    std::vector<int> X, Y;

    int n;
    inputFile >> n;
    mas.resize(n);
    for (int i = 0; i < n; ++i)
    {
        mas[i].FillRec(inputFile);
        X.push_back(mas[i].x1);
        X.push_back(mas[i].x2);

        Y.push_back(mas[i].y1);
        Y.push_back(mas[i].y2);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    X.resize(unique(X.begin(), X.end()) - X.begin());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());

    size_t square = 0;
    for (size_t i = 0; i < X.size() - 1; ++i)
    {
        for (size_t j = 0; j < Y.size() - 1; ++j)
        {
            Rect cur = Rect(X[i], Y[j], X[i + 1], Y[j + 1]);

            for (auto &item : mas)
            {
                if (item.IsExist(cur))
                {
                    square += cur.Square();
                    break;
                }
            }
        }
    }

    outputFile << square << std::endl;

    return 0;
}
