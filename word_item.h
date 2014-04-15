#ifndef _WORD_ITEM_H
#define _WORD_ITEM_H
const int CHARARRAY_SIZE = 100;
namespace word_table
{
class Word_item_base
{
public:
    Word_item_base() {}
    virtual ~Word_item_base() {}
    virtual int parse(const std::string&) = 0;
    Word_item_base(const Word_item_base&) {}
    static bool is_int(const std::string& str);
    static bool is_float(const std::string& str);

private:
    Word_item_base& operator= (const Word_item_base&);

};

class Int_word_item : public Word_item_base
{
public:
    Int_word_item() : _value(0) {};
    ~Int_word_item() {}
    int parse(const std::string&);
    int get_value() const
    {
        return _value;
    }
    static Int_word_item* getInstance();

private:
    Int_word_item(const Int_item_base&);
    int _value;
    Int_word_item& operator= (const Int_word_item&);

};

class Float_word_item : public Word_item_base
{
public:
    Float_word_item() : _value(0.0) {}
    ~Float_word_item() {}
    int parse(const std::string&);
    static Float_word_item* getInstance();

private:
    float _value;
    Float_word_item(const Float_word_item&);
    Float_word_item& operator= (const Float_word_item&);
};

class CharArray_word_item : public Word_item_base
{
public:
    CharArray_word_item() {}
    ~CharArray_word_item() {}
    int parse(const std::string&);
    static CharArray_word_item* getInstance();

private:
    Float_word_item& operator= (const Float_word_item&);
    Float_word_item(const Float_word_item&);
    char _value[CHARARRAY_SIZE];
};

class Array_word_item : public Word_item_base
{
public:
    Array_word_item() : _array_element_num(0) {}
    ~Array_word_item();
    int parse(const std::string&);

private:
    Array_word_item& operator= (const Array_word_item&);
    Array_word_item(const Array_word_item&);
    int _array_element_num;
    vector<Word_item_base*> _value;
};

#endif
