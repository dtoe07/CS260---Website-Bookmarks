//This is a header file for to declare a data class
//to hold data

#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class data
{
private:
	char*topic;
	char*website;
	char*summary;
	char*review;
	char*key;
	int rating;
	
public:
	data();
	~data();
    data*left;
    data*right;

	void getTopic(char*topic)const;
	void getWebsite(char*website)const;
	void getSummary(char*summary)const;
	void getReview(char*review)const;
	void getRating(int &rating)const;
	void getKey(char*key)const;

	void setTopic(char*topic);
    void setWebsite(char*website);
    void setSummary(char*summary);
    void setReview(char*review);
    void setRating(int rating);
	void setKey(char*key);

	const data& operator=(const data& aData);
	friend ostream& operator<< (ostream& out, const data& aData);

};
bool operator< (const data& d1, const data& d2);

#endif
