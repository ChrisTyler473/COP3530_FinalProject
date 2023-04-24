#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

//gets rid of quotation marks around a string
string trimString(string toTrim){
    toTrim.erase(0,1);
    toTrim.erase(toTrim.length()-1, 1);
    return toTrim;
}
int main() {

    //parsing data from file
    ifstream inFile("video_games.csv");
    if(inFile.is_open()){
        string fileLine;
        getline(inFile,fileLine);

        //all the data used, initially stored as a string
        string title, console, rating, yearS, multiplayer, usedpriceS, lengthS, genre, reviewS, skip;

        //will be converted from string values
        bool multiplayerTF;
        int year;
        float review, usedprice, length;
        while(getline(inFile,fileLine)){
            istringstream stream(fileLine);

            getline(stream, skip, '"');
            getline(stream, title, '"');
            getline(stream, skip, ',');
            getline(stream, skip, ',');

            getline(stream, multiplayer, ',');
            getline(stream, skip, ',');
            getline(stream, skip, ',');

            getline(stream, skip, '"');
            getline(stream, genre, '"');

            getline(stream, skip, ',');
            getline(stream, skip, ',');

            //there can also be multiple publishers, for some reason seperated by a comma
            getline(stream, skip, '"');
            getline(stream, skip, '"');
            getline(stream, skip, ',');
            getline(stream, skip, ',');

            getline(stream, reviewS, ',');
            reviewS = trimString(reviewS);
            review = stof(reviewS);

            getline(stream, skip, ',');
            getline(stream, usedpriceS, ',');
            usedpriceS = trimString(usedpriceS);
            usedprice = stof(usedpriceS);

            getline(stream, console, ',');
            getline(stream, rating, ',');
            getline(stream, skip, ',');
            getline(stream, yearS, ',');
            yearS = trimString(yearS);
            year = stoi(yearS);

            getline(stream, skip, ',');
            getline(stream, skip, ',');
            getline(stream, lengthS, ',');
            lengthS = trimString(lengthS);
            length = stof(lengthS);


            multiplayer = trimString(multiplayer);
            if(stoi(multiplayer) > 1){
                multiplayerTF = true;
            }
            else{
                multiplayerTF = false;
            }


            //insert data nodes
        }
    }

    //Gather data about user
    cout << "Hello, this program will help you search for a 2000's era video game based on your preferences and needs" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "First, what type of console are you playing on?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. Nintendo DS" << endl;
    cout << "   2. Nintendo Wii" << endl;
    cout << "   3. X-Box 360" <<endl;
    cout << "   4. PlayStation 3" <<endl;
    cout << "   5. Sony PSP" << endl;
    int consolenum;
    cin >> consolenum;
    cout << "---------------------------------------------------" << endl;
    cout << "Do you need the game to be a certain rating?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. E only (Everyone)" << endl;
    cout << "   2. T and under (Teen & Everyone)" << endl;
    cout << "   3. Any rating (including Mature)" <<endl;
    int rating;
    cin >> rating;

    cout << "---------------------------------------------------" << endl;
    cout << "Next, what type of genre do you prefer?" << endl;


    cout << "---------------------------------------------------" << endl;
    cout << "Do you want a singleplayer game, or one with multiplayer options?" << endl;
    cout << "Enter a number: " << endl;
    cout << "   1. Singleplayer only" << endl;
    cout << "   2. Multiplayer option" << endl;
    int multi;
    cin >> multi;

    cout << "---------------------------------------------------" << endl;
    cout << "Lastly, how long do you want the game to be? (hours)" << endl;
    return 0;
}
