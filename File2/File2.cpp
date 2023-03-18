// File2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() 
{
    setlocale(0, "");
    ifstream file("File1.txt");
    if (!file)
    {
        cout << "Не могу открыть файл"<<"\n";
        return 1;
    }
    string line;
    size_t max_length = 0;
    while (getline(file, line))
    {
        size_t length = line.length();
        if (length > max_length) 
        {
            max_length = length;
        }
    }
  cout << "Длина самой длинной строки = " << max_length << "\n";
    return 0;
}
