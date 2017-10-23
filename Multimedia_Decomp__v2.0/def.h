#ifndef _DEF_
#define _DEF_

//includes:
//----------
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
using namespace std;

//types:
//-------
#define SIZE 50
typedef unsigned char Byte;
struct BitField{ Byte _0:1, _1:1, _2:1, _3:1, _4:1, _5:1, _6:1, _7:1; };
union byte{ Byte b; BitField bits; };

//functions:
//-----------
void fill_map(map<string, char*> & m);
void read_picture(char **& picture, const char* name);
void transform(char **& picture, char **& t_picture, map<string, char*>& m);
void encode(char **& t_picture, char*& code, int& length);
void decode(char *& code, char **& t_picture);
void de_transform(char **& picture, char **& t_picture, map<string, char*>& m);
void write_code(char *& code, int length, char* name);
void read_code(char *& code, int & length, char* name);
void write_picture(char **& picture, char* name);

bool isEqual(char* input, char* output);
void test_map(map<string, char*> & m);
void test_picture(char **& picture, int size=SIZE);
void test_code(char *& code, int length);

#endif