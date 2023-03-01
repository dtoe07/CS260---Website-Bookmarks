//Header file for BST

#ifndef TREE_H
#define TREE_H
#include "data.h"
#include "helper.h"

//declaring a tree class to manage BST
class tree
{
private:
	data*root;
	int size;
    
    void insert(data*& root, data*newData);
    bool retrieve(data*root, char*key, data& aData)const;
    void removeByTopic(data*& root, char*topic);
    bool removeByKey(data*& root, char*key);
    
    void deleteData(data*& target);
    bool display(data*root, char*key, data& aData);
    void displayAll(data*root);

public:
	tree();
	~tree();
	void load();

    void destroyTree(data*& root);
	
    void add();
	void insert(data*newData);
	bool retrieve(char*key, data& aData)const;
	void removeByTopic(char*topic);
	void removeByKey(char*key);

    void display(char*key);
	void displayAll();
};

#endif
