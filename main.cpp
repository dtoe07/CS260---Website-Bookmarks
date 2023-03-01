/******************************************************
Created by: Dinh Nguyen
Project 4 - CS260

This program is to save all favorite websites into
categories for easy look up later.
can search all websites by a particular topic or a key word
can display all websites
******************************************************/

#include"data.h"
#include"tree.h"
#include"helper.h"

using namespace std;

int main()
{
	char selection;
	tree aTree;
	
	aTree.load();

	menu();
	cin>>selection;
	cin.ignore(100, '\n');

/*------------------------ User Interaction --------------------*/
	while (selection != 'q')
	{
		switch (selection)
		{
            case 'a':
                    aTree.add();
                    break;
            /*-------------------------------------*/
            case 'b':
                    char topic[100];
                    promptTopic(topic);
                    aTree.removeByTopic(topic);
                    break;
            /*-------------------------------------*/
            case 'c':
                    char key[100];
                    promptKey(key);
                    aTree.removeByKey(key);
                    break;
            /*-------------------------------------*/
            case 'd':
                    aTree.displayAll();
                    break;
            /*-------------------------------------*/
            case 'e':
                    char aKey[100];
                    promptKey(aKey);
                    aTree.display(aKey);
                    break;
            /*-------------------------------------*/
            case 'm':
                    menu();
                    break;
		}

	cout << endl << endl;
	cout << "Enter 'm' to list out the commands list again" << endl;
	cout << "What else do you want to do?: ";
	cin >> selection;
	cin.ignore(100, '\n');
	}

return 0;
}
