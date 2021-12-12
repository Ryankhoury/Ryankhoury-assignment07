#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

#define playerNumb 10 //10 players in file


//STRUCTURE DEFINITIION
typedef struct{

    char name [100];//PLAYER NAME
    int scores [5];//TABLE OF SCORES OF A PLAYER
    double average; //AVERAGE SCORE OF A PLAYER

} t_player;


void GetBowlingData(t_player players[10])
{
    //open the file
    ifstream FILE("BowlingScores.txt");

    int i = 0 ;
    //Test the file
    if(!FILE.fail())
    {
        //Go through all the file until the end of the file
        while((!FILE.eof())&& (i<playerNumb))
        {
            FILE>>players[i].name>>players[i].scores[0]>>players[i].scores[1]>>players[i].scores[2]>>players[i].scores[3]>>players[i].scores[4]; //read the name and the scores of all the players
            i++;
        }
    }
    else
    {
        cout<<"\nError in opening the file"<<endl ;
    }
}

void GetAverageScore(t_player players[playerNumb])
{
    for(int i=0; i<playerNumb; i++)//Calculate the average of EACH player
    {
        players[i].average = 0; //Initialise
        for(int j=0; j<5; j++)
        {
            players[i].average += players[i].scores[j];//Sum the scores of 1 player
        }
        players[i].average /= 5.0;//Calculate the average of the player
    }
}

void PrettyPrintResults(t_player players[playerNumb])
{
    //Print the table using a loop for each dimension and respecting the tabulation and line returns
    cout<<left<<setw(15)<<"Name"<<"Score1\tScore2\tScore3\tScore4\tAvg_Score"<<endl;

    for(int i=0; i<playerNumb; i++)
    {
        cout<<left<<setw(15)<<players[i].name<<"\t";
        for(int j=0; j<5; j++)
        {
            cout<<players[i].scores[j]<<"\t";
        }
        cout<<players[i].average<<endl;
    }
}

int main()
{
    cout<<"\n**********************************************************\n" ;

    //TABLE OF STRUCTURE TO STORE 10 PLAYERS (EACH PLAYER AS EACH ENTITY)
    t_player players[10] ;

    //Call all the functions
    GetBowlingData(players) ;
    GetAverageScore(players);
    PrettyPrintResults(players);

    cout<<"\n*********************************************************\n" ;

    return 0;



}
