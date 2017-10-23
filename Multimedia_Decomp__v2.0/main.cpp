#include "def.h"
//======================================================================================================================
void main(int argc, char* argv[])
{
	//create the prob. map:
	map<string, char*> prob;
	fill_map(prob);
	
	//input the encoded file:
	char* code;
	int code_length=0;
	char* code_name = new char[10]; 
	if(argc == 3 )
	{
		code_name = argv[1] ;
	}
	else 
	{
		cin>>code_name ;
		cout<<endl ;
	}
	read_code(code, code_length, code_name); 
	
	//decode the entered file:
	char** tt_picture;
	decode(code, tt_picture);
	
	//de-transform the decoded code:
	char** final_picture;
	de_transform(final_picture, tt_picture, prob);

	char* file_name = new char[10];
	if(argc == 3 )
	{
		file_name = argv[2] ;
	}
	else 
	{
		cin>>file_name ;
		cout<<endl ;
	}
	write_picture(final_picture, file_name);
}
//======================================================================================================================