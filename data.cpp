//This is the implemebtation file for data.h

#include "data.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

//Constructor
data::data()
{
	topic = NULL;
	website = NULL;
	summary = NULL;
	review = NULL;
	key = NULL;
	rating = 0;

    left = NULL;
	right = NULL;
}

//Destructor
data::~data()
{
	if(topic)
		delete[]topic;
	if(website)
		delete[]website;
	if(summary)
		delete[]summary;
	if(review)
		delete[]review;
	if(key)
        delete[]key;
}

//display overloading
ostream& operator<< (ostream& out, const data& aData)
{
    out<< aData.topic << endl<< "website : " <<aData.website << endl
    << "summary : " << aData.summary<< endl
    << "review  : " << aData.review << endl
    << "key word: " << aData.key <<"|"<< endl << "rating  : " <<aData.rating <<endl;
	return out;
}

//overloading comparison
bool operator< (const data& d1, const data& d2)
{
	char key1[100];
	char key2[100];

	d1.getKey (key1);
	d2.getKey (key2);

	if(strcmp( key1, key2) < 0)
		return true;
	else
		return false;
}

//overloading Assignment
const data& data::operator=(const data& aData)
{
		setTopic(aData.topic);
		setWebsite(aData.website);
		setSummary(aData.summary);
		setReview(aData.review);
		setKey(aData.key);
		setRating(aData.rating);
		return *this;
}

/*-------------------------- Accessors ---------------------------------*/

void data::getTopic(char*topic)const
{
	strcpy(topic, this->topic);
}

void data::getWebsite(char*website)const
{
	strcpy(website, this->website);
}

void data::getSummary(char*summary)const
{
	strcpy(summary, this->summary);
}

void data::getReview(char*review)const
{
	strcpy(review, this->review);
}

void data::getKey(char*key)const
{
	strcpy(key, this->key);
}

void data::getRating(int &rating)const
{
	rating = this->rating;
}

/*----------------------- Setting functions -------------------------*/

void data::setTopic(char*topic)
{
	if(this->topic)
		delete[]this->topic;
	this->topic = new char[strlen(topic)+1];
	strcpy(this->topic,topic);

int i = 0;
  while (this->topic[i])
  {
    this->topic[i] = toupper(this->topic[i]); 
    i++;
  }
}

void data::setWebsite(char*website)
{
        if(this->website)
                delete[]this->website;
        this->website = new char[strlen(website)+1];
        strcpy(this->website, website);
}

void data::setSummary(char*summary)
{
	if(this->summary)
                delete[]this->summary;
        this->summary = new char[strlen(summary)+1];
        strcpy(this->summary, summary);
}

void data::setReview(char*review)
{
	if(this->review)
                delete[]this->review;
        this->review = new char[strlen(review)+1];
        strcpy(this->review, review);
}

void data::setKey(char*key)
{
	if(this->key)
		delete[]this->key;
	this->key = new char[strlen(key)+1];
	strcpy(this->key, key);
}

void data::setRating(int rating)
{
	this->rating = rating;
}
