#include <iostream>
#include <fstream>

struct Log
{
    int length = 0;
};

void CutLog(Log &log, int &n, int &cost)
{
    if (log.length == 1 || n < 0)
    {
        return;
    }
    cost += log.length;
    if (log.length % 2 == 0)
    {
        Log newLog;
        log.length = log.length / 2;
        newLog.length = log.length;
        CutLog(newLog, n, cost);
    }
    else
    {
        log.length = n;
    }
    --n;
    CutLog(log, n, cost);
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

    int length;
    inputFile >> length;
    int n;
    inputFile >> n;
    Log log;
    log.length = n;

    int cost = length;
    --n;
    CutLog(log, n, cost);

    std::cout << cost << std::endl;

    return 0;
}
