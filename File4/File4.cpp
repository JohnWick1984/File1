// File4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    setlocale(0, "");
    string filename = "File4.txt";
    string word_to_replace, new_word;

    
    ifstream file(filename);

    if (!file)
    {
        cout << "Ошибка открытия файла " << filename << "\n";
        return 1;
    }

    // Чтение содержимого файла в строку
    string file_content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    // Закрытие файла
    file.close();

    
    cout << "Введите слово для замены: ";
    cin >> word_to_replace;

    cout << "Введите новое слово: ";
    cin >> new_word;

    // Замена слова в строке
    size_t pos = file_content.find(word_to_replace);
    while (pos != string::npos)
    {
        file_content.replace(pos, word_to_replace.length(), new_word);
        pos = file_content.find(word_to_replace, pos + new_word.length());
    }

    // Открытие файла на запись
    ofstream outfile(filename);

    if (!outfile) {
        cout << "Ошибка открытия файла " << filename << "\n";
        return 1;
    }

    // Запись нового содержимого файла
    outfile << file_content;

    
    outfile.close();

    return 0;
}
