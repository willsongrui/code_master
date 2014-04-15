#include "word_item.h"
#include <stdlib.h>
#include <vector>
#include <string>
using word_table::Word_item_base;
using word_table::Int_word_item;
using word_table::Float_word_item;
using word_table::CharArray_word_item;
using word_table::Array_word_item;
using std::vectoc;
using std::string;

int Int_word_item::parse(const string& str)
{
	if(Check_word_item::is_int(str) == false)
	{
		return -1;
	}
	long int ret = strtol(str.c_str());
	if((ret == LONG_MAX || ret == LONG_MIN))
	{
		return -1;
	}
	_value = ret;
	return 0;
}

Int_word_item* Int_word_item::getInstance()
{
	return new Int_word_item();
}

int Float_word_item::parse(const std::string& str)
{
	if(Check_word_item::is_float(str) == false)
	{
		return -1;
	}
	float ret = strtof(str.c_str());
	if(ret == HUGE_VALF || ret == HUGE_VALL)
	{
		returun -1;
	}
	_value = ret;
	return 0;

}

Float_word_item* Float_word_item::getInstance()
{
	return new Float_word_item();
}

CharArray_word_item::CharArray_word_item()
{
	memset(_value, 0, sizeof(_value));
}


CharArray_word_item* CharArray_word_item::getInstance()
{
	return new CharArray_word_item();
}

int CharArray_word_item::parse(const string& str)
{
	if(str.length() > CHARARRAY_SIZE)
	{
		return -1;
	}
	for(int i=0; i<str.length(); i++)
	{
		_value[i] = str[i];
	}
}

int Array_word_item::parse(const string& str)
{
	string maohao(":");
	int maohao_pos = str.find(maohao);
	
	if(maohao_pos == string::npos || maohao_pos == 0)
	{
		return -1;
	}
	string num_str = str.substr(0, maohao);
	if(Check_word_item::is_int(num_str) == false)
	{
		return -1;
	}
	Int_word_item num_item = Int_word_item();
	if(num_item.parse(num_str) < 0)
	{
		return -1;
	}
	_array_element_num = num_item.get_value();

	string douhao(",");
	int douhao_pos;
	int beg = maohao_pos + 1;
	vector<string> mv;
	while((douhao_pos = str.find(douhao, beg)) != string::npos)
	{
		mv.push_back(str.substr(beg, douhao_pos));
		beg = douhao_pos + 1;
	}
	mv.push_back(str.substr(beg));

	if(mv.size() != _array_element_num)
	{
		return -1;
	}
	bool is_int = true;
	bool is_float = false;
	for(int i=0; i<mv.size(); i++)
	{
		if(is_int(mv[i]) == false)
		{
			is_int = false;
		}
		if(is_float(mv[i]) == false)
		{
			is_float = false;
		}
	}

	if(is_int == true)
	{
		for(int i = 0; i < mv.size(); i++)
		{
			Int_word_item* item = new Int_word_item();
			item->parse(mv[i]);
			_value.push_back(item);
		}
		return 0;
	}
	
	if(is_float == true)
	{
		for(int i = 0; i < mv.size(); i++)
		{
			Float_word_item* item = new Float_word_item();
			item->parse(mv[i]);
			_value.push_back(item);
		}
		return 0;

	}
	
	for(int i=0; i < mv.size(); i++)
	{
		CharArray_word_item* item = new CharArray_word_item();
		item->parse(mv[i]);
		_value.push_back(item);
	}
	return 0;

}

Array_word_item::~Array_word_item()
{
	for(int i = 0; i < _value.size(); i++)
	{
		delete _value[i];
	}
}



