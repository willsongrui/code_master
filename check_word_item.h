#ifndef _CHECK_WORD_ITEM_H
#define _CHECK_WORD_ITEM_H
#include <string>
namespace word_table
{
class Check_word_item
{
public:
    static bool is_int(const std::string&);
    static bool is_float(const std::string&);
private:
    static bool is_digit(char);
};
}
#endif
