#include "check_word_item.h"
#include <string>
using std::string;
using word_table::Check_word_item;
bool Check_word_item::is_digit(char ch)
{
    if (ch < '0' || ch > '9')
    {
        return false;
    }

    return true;
}
bool Check_word_item::is_int(const string& str)
{
    if (str.length() == 0)
    {
        return false;
    }

    if (str[i] != '-' && is_digit(str[i]) == false)
    {
        return false;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (is_digit(str[i]) == false)
        {
            return false;
        }
    }

    return 0;
}

bool Check_word_item::is_float(const string& str)
{
    if (str.length() == 0)
    {
        return false;
    }

    int dot_num = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (is_digit(str[i]) == false)
        {
            if (dot_num != 0)
            {
                return -1;
            }
            else
            {
                if ((str[i] == '.') && (i != 0))
                {
                    ++dot_num;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return true;
}