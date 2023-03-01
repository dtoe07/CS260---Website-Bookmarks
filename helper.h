//Header file for helper functions

#ifndef HELPER_H
#define  HELPER_H
#include"data.h"
#include <iostream>
using namespace std;

        const int keyCap = 2;

void promptTopic(char*topic);
void promptKey(char*key);
void promptData(data*newData);
void toUpper(char*word);

//Function Prototypes
char* killSymbols(char*webSite);
void arrayWords(char**array, char*words);

void getKey(char*website, char*key);
void convertKey(char**array, char*key);

void loadKey(char**keyarray, char**array);
void keyInArray(char*website, char**keyArray);
void arrayToChar(char**keyArray, char*key);


void menu();

#endif
