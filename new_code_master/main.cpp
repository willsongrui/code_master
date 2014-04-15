#include <iostream>
#include <vector>
#include "word_item.h"
#include "word_table.h"
using std::vector;
using std::cout;
using std::endl;
//using namespace ps_word_table;
using ps_word_table::Word_table;
using ps_word_table::Word_item_base;
using ps_word_table::Int_word_item;
using ps_word_table::Float_word_item;
using ps_word_table::CharArray_word_item;
using ps_word_table::Array_word_item;
int main()
{
	vector<Word_item_base*> mv;
	Int_word_item* my_int = new Int_word_item();
	CharArray_word_item* my_char = new CharArray_word_item();
	mv.push_back(my_int);
	mv.push_back(my_char);
	Word_table my_word_table(mv);
	cout<<"hello";
    int ret = my_word_table.load_file("test.log");
	cout<<ret<<endl;
    /*
    int line_num = 0;
    
    while(my_word_table.parse_line())
	{
		cout<<"line: "<<line_num++;
			
	}*/
	delete my_int;
	delete my_char;
   // cout<<"1"<<endl;
	return 0;
}

