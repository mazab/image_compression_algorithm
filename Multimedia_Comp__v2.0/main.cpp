#include "def.h"
//======================================================================================================================
int main(int argc, char* argv[])
{
	//create the prob. map:
	map<string, char*> prob;
	fill_map(prob);

	//read the picture from the file:

	char* file_name = new char[10];
	if(argc == 3)
	{
		file_name = argv[1] ;
	}
	else 
	{
		cin>>file_name ;
		cout<<endl ;
	}
	char ** picture;
	read_picture(picture, file_name);
	
	//transform picture:
	char ** t_picture;
	transform(picture, t_picture, prob);
	
	//encode the transformed picture:
	int code_length =0;
	char* code;
	encode(t_picture, code, code_length);
	//write the code:
	char* code_name = new char[10]; 
	if(argc == 3 )
	{
		code_name = argv[2] ;
	}
	else 
	{
		cin>>code_name ;
		cout<<endl ;
	}
	write_code(code, code_length, code_name);

	return 0 ; 
}
//======================================================================================================================