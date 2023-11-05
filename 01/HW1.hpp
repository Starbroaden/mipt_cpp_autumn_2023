#include <iostream>
#include <cstdint> // для intX_t
#include <cstddef> // для size_t
#include <map>
#include <cassert>


std::string convertTextToSound(std::string text)
{
    std::string str = text;
    
    //запоминаем первую букву слова
    char first = str[0];
    //сделаем из первой буквы строку
    std::string first_string;
    first_string.push_back(std::toupper(first));
    
    //для дальнейшей работы удаляем из строки первую букву
    str.erase(0, 1);
    
    //удаляем все вхождения h и w
    for(size_t i = 0; i < str.size(); i++)
    {
        if ((str[i] == 'w')||(str[i] == 'h'))
        {
            str.erase(i, 1);
        }
    }
    
    //заменяем согласные на цифры
    
    std::map<char, char> change = {{'b', '1'}, {'f', '1'}, 
    {'p', '1'}, {'v', '1'},{'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'},
    {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'}, {'d', '3'}, {'t', '3'}, 
    {'l', '4'}, {'m', '5'}, {'n', '5'}, {'r', '6'}};
    
    

    for(size_t i = 0; i < str.size(); i++)
    {
        for(auto n{change.begin()}; n != change.end(); n++)
        {
            if (str[i] == n->first)
            {
                str[i] = n->second;
                /*хотел вместо предыдущей строки написать так:
                str.replace(i, 1, n->second);
                но компилятор ругается. Видимо, из-за того,
                что я не до конца разобрался с std::map и методом replace
                */ 
            }
        }
    }

    //заменяем последовательность одинаковых цифр на одну

    for(size_t i = 0; i < str.size(); i++)
    {
        std::string numbers = "0123456789";
        for (auto n: numbers)
        {
            if ((str[i] == n))
            {
                while(str[i+1] == str[i])
                {
                    str.erase(i, 1);
                    i++;
                }
            }
        }
    }



    //удаляем a, e, i, o, u, y
    for (size_t i = 0; i < str.size(); i++)
    {
        if ((str[i] == 'a')||(str[i] == 'e')||(str[i] == 'i')||(str[i] == 'o')
        ||(str[i] == 'u')||(str[i] == 'y'))
        {
            str.erase(i, 1);
        }
    }

    //заменяем первый символ на запомненный заглавный
    str.insert(0, first_string);

    //если нужно, обрезаем строку до первых 4 символов или же достраиваем нулями
    if (str.size() > 4)
    {
        str = str.substr(0,4);
    }
    else if (str.size() < 4)
    {
        char zero_add = '0';
        //std::string zero_add = "0";
        while(str.size() != 4)
        {
            str.push_back(zero_add);
        }
    }

    return str;
}


bool isEqual(std::string text1, std::string text2)
{
    if (convertTextToSound(text1) == convertTextToSound(text2))
    {
        return true;
    }
    else
    {
        return false;
    }
}




