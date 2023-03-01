//Implementation for helper header

#include "helper.h"
#include "tree.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;
int CHAR = 1024;

//conver string to upper
void toUpper(char*word)
{
    int c = 0;
    while (word[c])
    {
        word[c] = toupper(word[c]);
        c++;
    }
}

//prompt for topic
void promptTopic(char*topic)
{
    cout<<"Please enter the topic to delete: ";
    cin.clear();
    cin.get(topic, 100);
    cin.ignore();
    toUpper(topic);
}

//prompt for a key
void promptKey(char*key)
{
    cout<<"Please enter the key word: ";
    cin.clear();
    cin.get(key, 100);
    cin.ignore();
}

//promt for a new data set
void promptData(data*newData)
{
    char newTopic[CHAR];
    char newWebsite[CHAR];
    char newSummary[CHAR];
    char newReview[CHAR];
    char newKey[CHAR];
    int newRating;
    
    //getting topic
    cout<<"Please enter topic name: ";
    cin.clear();
    cin.get(newTopic, CHAR);
    cin.ignore();
    
    //getting website
    cout<<"Please enter website: ";
    cin.clear();
    cin.get(newWebsite, CHAR);
    cin.ignore();
    
    //getting summary
    cout<<"Please enter the summary: ";
    cin.clear();
    cin.get(newSummary, CHAR);
    cin.ignore();
    
    //getting review
    cout<<"Please enter your review: ";
    cin.clear();
    cin.get(newReview, CHAR);
    cin.ignore();
    
    //getting rating
    cout << "Enter your rating from 1 to 10 only: ";
    cin >> newRating;
    cin.ignore();
    while(!cin || newRating > 10)
    {
        cout<<endl;
        cout<<"Please enter interger from 1 to 10  only: ";
        cin.clear();
        cin.ignore(100,'\n');
        cin>>newRating;
    }
    
    getKey(newWebsite, newKey);
    
    newData->setTopic(newTopic);
    newData->setWebsite(newWebsite);
    newData->setSummary(newSummary);
    newData->setReview(newReview);
    newData->setKey(newKey);
    newData->setRating(newRating);
}
//displaying menu
void menu()
{
    
    cout<<endl<<endl;
    cout<<"---------------------------------------------";
    cout<<endl;
    cout<<" List of operations for the website fav list :"<<endl;
    
    cout<<" a:      to add new website"<<endl;
    cout<<" b:      to remove all websites of a topic"<<endl;
    cout<<" c:      to remove a website base on key word"<<endl;
    cout<<" d:      to display all websites"<<endl;
    cout<<" e:      to search for a website base on key word"<<endl;
    cout<<" m:      to display the menu"<<endl;
    cout<<" q:      to quit"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Please enter your choice here: ";
    
    
}

//getting key from website
void getKey(char*website, char*key)
{
    char*words = killSymbols(website); //removing all non_alphabetics
    
    char**array= new char*[10];; //Creating a array of char* to load words
    
    for(int i = 0; i<10; i++)
        array[i] = NULL;
    
    arrayWords(array, words); //loading each word to 6 slots
    
    delete[]words;  //deleting words arrays after done
    
    convertKey(array,key);
    delete[]array;
}

//loading desired words to key array
void convertKey(char**array, char*key)
{
    int k = 0;  //counter for key array
    int j = 0;  //counter for tempKey array
    int i = 0;  //counter for Array
    while(array[i] && j<keyCap)
    {
        
        //checking and remove all useless generic words
        if(strcmp(array[i], "www") == 0 ||strcmp(array[i], "https") == 0
           || strcmp(array[i], "http") == 0
           || strcmp(array[i], "com") == 0 || strcmp(array[i], "net") == 0
           || strcmp(array[i], "org") == 0)
            i++;
        
        //If the slot is not generic words, copy it over to key Array
        else
        {
            int g = 0;
            while(array[i][g])   //looping until end
            {
                key[k] = array[i][g];
                g++;
                k++;
            }
            
            key[k] = ' ';   //adding a space after each words
            k++;    //go to the next key position
            i++;
            j++;
            
        }
        
    }
    k = k - 1;
    key[k] = '\0';
    
    cout<<"here: " <<key<<endl;
    if(strcmp("toe", key) == 0)
        cout<<"found!"<<endl;
}


//taking an array of char and convert it to array of key words --------------------------------
void arrayWords(char**array, char*words)
{
    char*point;
    int i = 0;
    point = strtok(words, " ");
    while(point && i < 10)
    {
        cout<<"here"<<endl;
        array[i] = new char[strlen(point)+1];
        strcpy(array[i], point);
        point = strtok(NULL, " ");
        i++;
    }

}

//taking a char array and Return only alphabet letters to the array -----------------------------
char* killSymbols(char*website)
{
    int i=0;
    int j = 0;
    bool space = false;
    char words[100];
    
    while (website[i])
    {
        if (isalpha(website[i]))
        {
            words[j] = website[i];
            j++;
            i++;
            space = false;
        }
        else
        {
            if(space == false)
            {
                words[j] = ' ';
                j++;
                i++;
                space = true;
            }
            else
                i++;
        }
    }
    
    words[j] = '\0';
    
    char*alphabet = new char[strlen(words)+1];
    strcpy(alphabet, words);
    
    return alphabet;    //returning the char array with words only
}

////////////////////////// extra ///////////////////////////////////////////////////////////


//converting array of key words to single char array to be the key
void arrayToChar(char**keyArray, char*key)
{
    int k = 0;  //counter for key array
    
    for(int i = 0; i <keyCap; i++)  //looping until end of keyArray
    {
        if(keyArray[i])
        {
            int j = 0;  //counter for inside keyArray[i]
            while(keyArray[i][j])   //looping until end
            {
                key[k] = keyArray[i][j];
                j++;
                k++;
            }
            
            key[k] = ' ';   //adding a space after each words
            k++;    //go to the next key position
        }
        
    }
}

//processing the website array to get the key as array of keys -------------------------------------------------
void keyInArray(char*website, char**keyArray)
{
    char*words = killSymbols(website); //removing all non_alphabetics
    
    char**array = new char*[10]; //Creating a array of char* to load words
    arrayWords(array, words); //loading each word to 6 slots
    delete[]words;  //deleting words arrays after done
    
    loadKey(keyArray, array);  //loading only desired words to be key
    delete[]array;  //deleting temporary array after key is loaded
    
}

//loading the desire words to be the key -------------------------------------------------------
void loadKey(char**keyArray, char**tempKey)
{
    
    int j = 0;  //counter for tempKey array
    int i = 0;  //counter for keyArray
    while(j<10 && i<keyCap)
    {
        if(tempKey[j])  //check if the tempKey psosition is empty or not
        {
            //checking and remove all useless generic words
            if(strcmp(tempKey[j], "www") == 0 ||strcmp(tempKey[j], "https") == 0
               || strcmp(tempKey[j], "http") == 0
               || strcmp(tempKey[j], "com") == 0 || strcmp(tempKey[j], "net") == 0
               || strcmp(tempKey[j], "org") == 0)
                j++;
            
            //If the slot is not generic words, copy it over to key Array
            else
            {
                keyArray[i] = new char[100];
                strcpy(keyArray[i], tempKey[j]);
                j++;
                i++;
            }
        }
        else    //if the tempKey position is empty, go to the next slot
            j++;
    }
}


