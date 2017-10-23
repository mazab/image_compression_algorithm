#include "def.h"
//======================================================================================================================
void read_code(char *& code, int & length, char* name)
{
	ifstream in(name, ios::binary);
	in.read((char*)&length, 2);
	code = new char[length];
	int i=0;
	while(i<length)
	{
		unsigned char input = 0;
		char ref = 1;
		in.read((char*)&input, 1);
		for(int j=7; j>=0; j--)
		{
			char tmp = input >> j;
			tmp &= ref;
			if(tmp == 0)
				code[i] = '0';
			else
				code[i] = '1';
			i++;
			if(i == length)
				break;
		}
	}
	in.close();
}
//======================================================================================================================
void write_picture(char **& picture, char* name)
{
	ofstream out(name);
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			out<<picture[i][j];
		}
	}
	out.close();
}
//======================================================================================================================
