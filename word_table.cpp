#include "word_table"
#include <stdio.h>
#include <stdexcept>
using word_table::Word_table;
Word_table::Word_table(const vector<Word_item*> mv) : _file(NULL), _ready(false)
{
    for (int i = 0; i < mv.size(); i++)
    {
        Word_item* item = mv[i]->getInstance();
        _rule.push_back(item);
    }

    _word_per_line = _rule.size();
}

int Word_table::load_file(const char* filename)
{
    if (filename == NULL)
    {
        return -1;
    }

    _file = fopen(filename, "r");

    if (_file == NULL)
    {
        return -2;
    }

    _ready = true;
}

int Word_table::read_line()
{
    if (false == _ready)
    {
        return -3;
    }

    char buff[1000];
    char* ret = fgets(buff, sizeof(buff), _file);

    if (false == ret)
    {
        return -4;
    }

    _cur_line.clear();

    if ((buff[sizeof(buff) - 1] != '\0') || (buff[sizeof(buff) - 2] == '\n'))
    {
        _cur_line = string(buff);
        return 0;
    }
    else
    {
        while ((buff[sizeof(buff) - 1] == '\0') && (buff[sizeof(buff) - 2] != '\n'))
        {
            _cur_line = _cur_line + string(buff);
            ret = fgets(buff, sizeof(buff), _file);

            if (ret == NULL)
            {
                break;
            }

            _cur_line += string(buff);
        }
    }

    return 0;
}
void Word_table::split_delimeter(vector<string>& mv, const string& delimeter)
{
    int beg = 0;
    int pos;

    while ((pos = _cur_line.find(delimeter, beg) != string::npos)
{
    mv.push_back(_cur_line.substr(beg, pos - beg));
        beg = pos + delimeter.length();
    }
    mv.push_back(_cur_line.substr(beg));
}

int Word_table::parse_line()
{
    int read_line_ret = read_line();

    if (read_line_ret < 0)
    {
        return read_line_ret;
    }

    vector<string> split_vec;
    string delimeter("\t");
    split_delimeter(split_vec, delimeter);
    int vec_size = split_vec.size();

    if (vec_size != _word_per_line)
    {
        return -5;
    }

    for (int i = 0; i < vec_size; i++)
    {
        int ret = _rule[i].parse(split_vec[i]);

        if (ret < 0)
        {
            return ret;
        }
    }

    return 0;
}

