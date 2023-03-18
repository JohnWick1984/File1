// File3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    setlocale(0, "");
    string filename, word;
    int count = 0;

    cout << "Введите имя файла: "; // вводить в формате file.txt
    cin >> filename;
    cout << "Введите слово: ";
    cin >> word;

    ifstream file(filename);
    if (!file.is_open()) 
    {
        cout << "Не удалось открыть файл" << "\n";
        return 1;
    }

    string line;
    while (getline(file, line)) 
    {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos)
        {
            count++;
            pos += word.length();
        }
    }

    cout << "Слово \"" << word << "\" встретилось " << count << " раз(а)" << "\n";

    return 0;
}
