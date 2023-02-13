// Blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>


using namespace std;

void showIntro()
{
    //Introducing the game
    cout << "________________________________________" << endl;
    cout << "|        Welcome to Blackjack!         |" << endl;
    cout << "|      I made this so I can train      |" << endl;
    cout << "|    Blackjack against Tayton without  |" << endl;
    cout << "|      him taking all my Jimbucks      |" << endl;
    cout << "|  Press one of the two keys to play!  |" << endl;
    cout << "|______________________________________|" << endl;

}

void printData(int PlayerTotal, int dCard)
{
    cout << "==========================================" << endl;
    cout << "\nThe total of your cards is " << PlayerTotal << endl;
    cout << "\nTayton has " << dCard << " face up" << endl;
}

int getCard()
{
    return rand() % 11 + 1; //range of possible cards
}

void turn(int& PlayerTotal, char pick, bool& pass)
{
    //if the player wants to hit
    if (pick == 'H' || pick == 'h')
    {
        PlayerTotal += getCard();
        cout << "\t***Your total is " << PlayerTotal << "***\n";
        if (PlayerTotal >= 22)
        {
            pass = true;
        }
    }

    if (pick == 'P' || pick == 'p')
    {
        pass = true;
    }
    return;

}

int main()
{
    string answer;

    showIntro();

    bool pass;
    char pick = NULL;

    while (true)
    {
        cout << "==========================================" << endl;
        pass = false;

        //Initialize srand and get random card numbers
        srand(time(0));
        int dCard = getCard();
        int PlayerTotal = getCard();// + getCard();
        int DealerTotal = dCard + getCard();

        //Player's turn
        while (!pass)
        {
            printData(PlayerTotal, dCard);
            cout << "\nWould you like to hit or pass?   (H/P) \n" << endl;
            cin >> pick;
            turn(PlayerTotal, pick, pass);
        }

        pass = false;

        cout << "It's Tayton's turn!\n";
        Sleep(900);
        cout << ".\n";
        Sleep(900);
        cout << "..\n";
        Sleep(900);
        cout << "...\n";
        Sleep(900);
        cout << "....\n";
        Sleep(900);
        cout << "The deal went in...\n";
        Sleep(2000);

        //Dealer's turn
        while (DealerTotal <= 21 && !pass)
        {
            if (DealerTotal >= 17) pass = true;
            else DealerTotal += getCard();
        }


        //Display winner
        cout << "\n\nThe player has " << PlayerTotal << ".\nTayton has " << DealerTotal << ".\n\n";

        if ((PlayerTotal < 22) && (PlayerTotal > DealerTotal) || (DealerTotal > 21 && (PlayerTotal < 22)))
        {
            cout << "You Win!" << endl;
        }
        else if ((PlayerTotal < 22) && (PlayerTotal == DealerTotal))
        {
            cout << "Bust!" << endl;
        }
        else
        {
            cout << "You Lose!" << endl;
        }
    }
    return (0);
}
