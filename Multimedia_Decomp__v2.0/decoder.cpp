#include "def.h"
//======================================================================================================================
void decode(char *& code, char **& t_picture)
{
	int k=0;
	int l=(SIZE-1)*(SIZE-1);
	t_picture = new char*[SIZE-1];
	for(int i=0; i<SIZE-1; i++)
	{
		t_picture[i] = new char[SIZE-1];
		for(int j=0; j<SIZE-1; j++)
		{
			if(code[k] == '1')
			{
				t_picture[i][j] = '0';
			}
			else
			{
				if(code[l] == '1')
					t_picture[i][j] = '1';
				else
					t_picture[i][j] = '2';
				l++;
			}
			k++;
		}
	}
	for(int i=0; i<SIZE-1; i++)
	{
		for(int j=0; j<SIZE-1; j++)
		{
			if(t_picture[i][j] == '2')
			{
				if(code[l] == '0')
					t_picture[i][j] = '3';
				l++;
			}
		}
	}
}
//======================================================================================================================
void de_transform(char **& picture, char **& t_picture, map<string, char*>& m)
{
	picture = new char*[SIZE];
	picture[0] = new char[SIZE];
	for(int i=0; i<SIZE; i++)
	{
		picture[0][i] = '0';
	}
	for(int i=1; i<SIZE; i++)
	{
		picture[i] = new char[SIZE];
		picture[i][0] = '0';
	}
	for(int i=1; i<SIZE; i++)
	{
		for(int j=1; j<SIZE; j++)
		{
			char x = picture[i-1][j];
			char y = picture[i][j-1];
			string xy = "";
			xy += x;
			xy += y;
			if(t_picture[i-1][j-1] == '0')
			{
				picture[i][j] = m[xy][0];
			}
			else if(t_picture[i-1][j-1] == '1')
			{
				picture[i][j] = m[xy][1];
			}
			else if(t_picture[i-1][j-1] == '2')
			{
				picture[i][j] = m[xy][2];
			}
			else
			{
				picture[i][j] = m[xy][3];
			}
		}
	}
}
//======================================================================================================================