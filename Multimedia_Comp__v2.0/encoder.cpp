#include "def.h"
//======================================================================================================================
void transform(char **& picture, char **& t_picture, map<string, char*>& m)
{
	t_picture = new char*[SIZE-1];
	for(int i=1; i<SIZE; i++)
	{
		t_picture[i-1] = new char[SIZE-1];
		for(int j=1; j<SIZE; j++)
		{
			string s = "";
			s += picture[i-1][j];
			s += picture[i][j-1];
			if(picture[i][j] == m[s][0])
				t_picture[i-1][j-1] = '0';
			else if(picture[i][j] == m[s][1])
				t_picture[i-1][j-1] = '1';
			else if(picture[i][j] == m[s][2])
				t_picture[i-1][j-1] = '2';
			else
				t_picture[i-1][j-1] = '3';
		}
	}
}
//======================================================================================================================
void encode(char **& t_picture, char*& code, int& length)
{
	queue<char> q0;		int length0 = (SIZE-1)*(SIZE-1);
	queue<char> q1;		int length1 = 0;
	queue<char> q2;		int length2 = 0;
	for(int i=0; i<SIZE-1; i++)
	{
		for(int j=0; j<SIZE-1; j++)
		{
			if(t_picture[i][j] == '0')
				q0.push('1');
			else
			{
				q0.push('0');
				length1++;
				if(t_picture[i][j] == '1')
					q1.push('1');
				else
				{
					q1.push('0');
					length2++;
					if(t_picture[i][j] == '2')
						q2.push('1');
					else
						q2.push('0');
				}
			}
		}
	}
	length = length0 + length1 + length2;
	code = new char[length];
	int i=0;
	for(int j=0; j<length0; j++)
	{
		code[i++] = q0.front();
		q0.pop();
	}
	for(int j=0; j<length1; j++)
	{
		code[i++] = q1.front();
		q1.pop(); 
	}
	for(int j=0; j<length2; j++)
	{
		code[i++] = q2.front();
		q2.pop(); 
	}
}
//======================================================================================================================