// File1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    setlocale(0, "");

    ifstream inputFile("File1.txt");
    ofstream outputFile("File2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) 
    {
        cout << "Ошибка открытия файлов!" << "/n";
        return 1;
    }

    string line, lastLine;

    while (getline(inputFile, line)) 
    {
        if (!inputFile.eof())
        {
            outputFile << lastLine << "\n";
        }
        lastLine = line;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
