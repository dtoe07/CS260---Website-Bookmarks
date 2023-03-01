//implementation for tree header

#include "tree.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int MAXCHAR = 1024;


//Constructor
tree::tree()
{
	root = NULL;
	size = 0;
}

//destructor
tree::~tree()
{
	destroyTree(root);
}

//destroy Tree
void tree::destroyTree(data*& root)
{
	if(root)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = NULL;
	}
}

//Adding new website --------------------------------------------------------------
void tree::add()
{
    data*newData = new data;
    promptData(newData);
    insert(newData);
}

//Display a website base on key word
void tree::display(char*key)
{
    data aData;
    bool test;
    test = retrieve(key, aData);
    if(test)
    cout<<aData<<endl;
}

//Insert new data -----------------------------------------------------------------
void tree::insert(data*newData)
{
    insert(root, newData);
}

void tree::insert(data*& root, data* newData)
{
	if(!root)
	{
		root = newData;
		size++;
	}
	else if(*newData < *root)
	{
		insert(root->left, newData);
	}
	else
	{
		insert(root->right, newData);
	}
}

//remove by key word --------------------------------------------------------------
void tree::removeByKey(char*key)
{
    removeByKey(root, key);
}
bool tree::removeByKey(data*& root, char * key)
{
	if(!root)
		return false;
	char name[100];
	root->getKey(name);
	int temp = strcmp(name, key);
	if(temp == 0)
	{
		deleteData(root);
		return true;
	}
	else if (temp < 0)
		return removeByKey(root->right, key);
	else
		return removeByKey(root->left, key);

}

//remove by topic ----------------------------------------------------------------
void tree::removeByTopic(char*topic)
{
    removeByTopic(root, topic);
}

void tree::removeByTopic(data*& root, char * topic)
{
    if(root)
    {
        removeByTopic(root->left, topic);
        
        removeByTopic(root->right, topic);
        char name[100];
        root->getTopic(name);
        int temp = strcmp(name, topic);
        if(temp == 0)
            deleteData(root);
    }
}

//retrieve -----------------------------------------------------------------------
bool tree::retrieve (char * key, data& aData)const
{
    return retrieve(root, key, aData);
}

bool tree::retrieve (data * root, char * key, data& aData) const
{
    if(!root)
    {
        return false;
    }
    char name[100];
    root->getKey(name);
    int temp = strcmp(name, key);
            cout<<"key is:"<<name<<endl;
    if(temp == 0)
    {
        aData = *root;
        return true;
    }
    else if(temp < 0)
    {
        return retrieve(root->right, key, aData);
    }
    else
    {
        return retrieve(root->left, key, aData);
    }

}
//Delete a Data -----------------------------------------------------------------
void tree::deleteData (data *& target)
{
	data * temp;

	//a leaf
	if(!target->left && !target->right)
	{
		delete target;
		target = NULL;
	}
	//no left child
	else if(!target->left)
	{
		temp = target;
		target = target->right;
		temp->right = NULL;
		delete temp;
	}
	//no right child
	else if(!target->right)
	{
		temp = target;
		target = target->left;
		temp->left = NULL;
		delete temp;
	}
	//two children
	else
	{
		//find the inorder successor
		data * prev = NULL;
		data * curr = target->right;
		while(curr->left)
		{
			prev = curr;
			curr = curr->left;
		}
		
		//copy data at curr (the inorder successor) into target
		*target = *curr;		

		//disconnect curr (the inorder successor)
		if(!prev)
			target->right = curr->right;
		else
			prev->left = curr->right; //the inorder successor could have a right child

		

		//delete curr (the inorder successor)
		curr->right = NULL;
		delete curr;
	}
	size--;
}

//Display ALL -------------------------------------------------------------------
void tree::displayAll()
{
    displayAll(root);
}

void tree::displayAll (data * root)
{
	if(root)
	{
		displayAll(root->left);
		cout << '\t' << *root << endl;
		displayAll(root->right);
	}
}

//Loading from text file --------------------------------------------------------
void tree::load()
{
	ifstream in;
	char newTopic[MAXCHAR];
        char newWebsite[MAXCHAR];
        char newSummary[MAXCHAR];
        char newReview[MAXCHAR];
        char newKey[MAXCHAR];

        int newRating = 0;

//Openning file
	in.open("list.txt");
	if(!in)
	{
		cerr<<"fail to open"<<endl;
		exit(1);
	}

//start taking inputs
	in.clear();
	in.get(newTopic, MAXCHAR, '|');
	in.ignore(MAXCHAR, '|');
	while(!in.eof())
	{	
		in.clear();
		in.get(newWebsite, MAXCHAR, '|');
		in.ignore(MAXCHAR, '|');

		in.clear();
                in.get(newSummary, MAXCHAR, '|');
		in.ignore(MAXCHAR, '|');
		
		in.clear();
                in.get(newReview, MAXCHAR, '|');
		in.ignore(MAXCHAR, '|');

in.clear();
                in.get(newKey, MAXCHAR, '|');
		in.ignore(MAXCHAR, '|');

		in.clear();
                in >> newRating;
		in.ignore(MAXCHAR, '\n');
		
//Creating new data object to store new dat
		data*newData = new data;

		newData->setTopic(newTopic);
		newData->setWebsite(newWebsite);
		newData->setSummary(newSummary);
		newData->setReview(newReview);
		newData->setKey(newKey);
		newData->setRating(newRating);

//Inserting new object to table
		insert(newData);

//taking next input
	in.clear();
        in.get(newTopic, MAXCHAR, '|');
        in.ignore(MAXCHAR, '|');
	}
in.close();
}






