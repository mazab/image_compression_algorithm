#include "def.h"
//======================================================================================================================
void read_picture(char **& picture, const char* name)
{
	ifstream in(name);
	picture = new char*[SIZE];
	for(int i=0; i<SIZE; i++)
	{
		picture[i] = new char[SIZE];
		for(int j=0; j<SIZE; j++)
		{
			in>>picture[i][j];
		}
	}
}
//======================================================================================================================
void write_code(char *& code, int length, char* name)
{
	ofstream out(name, ios::binary);
	//output the length of the code
	out.write((char*)&length, 2);
	//calculate the no. of bytes to be out
	int bytes_count = length/8;
	bytes_count += (length%8 != 0)? 1 : 0;
	
	//create and initialize the bytes to be out
	byte* bytes = new byte[bytes_count];
	int bits_count =0; // this should not exceed the "length"
	for(int i=0; i<bytes_count; i++)
	{
		//set bit #0 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._7 = 0;
		else
			bytes[i].bits._7 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #1 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._6 = 0;
		else
			bytes[i].bits._6 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #2 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._5 = 0;
		else
			bytes[i].bits._5 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #3 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._4 = 0;
		else
			bytes[i].bits._4 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #4 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._3 = 0;
		else
			bytes[i].bits._3 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #5 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._2 = 0;
		else
			bytes[i].bits._2 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #6 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._1 = 0;
		else
			bytes[i].bits._1 = 1;
		bits_count++;
		if(bits_count == length)
			break;
		//set bit #7 in bytes[i]
		if(code[bits_count] == '0')
			bytes[i].bits._0 = 0;
		else
			bytes[i].bits._0 = 1;
		bits_count++;
		if(bits_count == length)
			break;
	}

	//output the bytes
	for(int i=0; i<bytes_count; i++)
	{
		out.write((char*)&bytes[i], 1);
	}
	out.close();
}
//======================================================================================================================
