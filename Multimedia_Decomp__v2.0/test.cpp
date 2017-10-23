#include "def.h"
//======================================================================================================================
void test_map(map<string, char*> & m)
{
	cout<<"Testing the Prob. Map ..."<<endl;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout<<i<<j<<"->";
			for(int k=0; k<4; k++)
			{
				string s = "";
				s += 0x30 + i;
				s += 0x30 + j;
				cout<<(m[s])[k];
			}
			cout<<'\t';
		}
		cout<<endl;
	}
}
//======================================================================================================================
void test_picture(char **& picture, int size)
{
	cout<<"\nTesting the Input Picture ..."<<endl;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			cout<<picture[i][j];
		}
		cout<<endl;
	}
}
//======================================================================================================================
void test_code(char *& code, int length)
{
	cout<<"\nTesting code ...("<<length<<")..."<<endl;
	for(int i=0; i<length; i++)
	{
		cout<<code[i];
	}
	cout<<endl;
}
//======================================================================================================================
bool isEqual(char* input, char* output)
{
	ifstream in0(input);
	ifstream in1(output);
	char _0(0),_1(0);
	string code0 = "";
	string code1 = "";
	int count_0(0), count_1(0);
	while(in0>>_0)
	{
		code0 += _0;
		count_0++;
	}
	in0.close();
	while(in1>>_1)
	{
		code1 += _1;
		count_1++;
	}
	in1.close();
	if(count_0 != count_1)
		return false;
	if(code0 != code1)
		return false;

	return true;
}
//======================================================================================================================