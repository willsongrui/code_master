#ifndef WORD_TABLE_H
#define WORD_TABLE_H
#include <stdio.h>
#include <vector>
#include <string>
#include "word_item.h"
namespace ps_word_table
{
class Word_table
{
public:
    Word_table(const std::vector<Word_item_base*>&);
    ~Word_table();
    int load_file(const char*);
    int parse_line();
private:
    Word_table(const Word_table&);
    Word_table* operator= (const Word_table&);
    int read_line();
    void split_delimeter(std::vector<std::string>& mv, const std::string& delimeter);
    std::vector<Word_item_base*> _value;
    std::vector<Word_item_base*> _rule;
    FILE* _file;
    bool _ready;
    std::string _cur_line;
    int _word_per_line;


};
}
#endif
