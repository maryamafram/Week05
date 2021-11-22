// Week05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void ShowUsage()
{
    //clear console
    if (system("CLS")) system("clear");
    //A function to show the user how could use the program
    cout << setfill('*') << setw(60) << "" << endl
        << setw(55) << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << "" << endl
        << setw(60) << "" << endl
        << setfill(' ') << endl << endl
        << "To show program usage 'S'\n"
        << "To purchase a surfboard press 'P'\n"
        << "To display current purchases press 'C'\n"
        << "To display total amount due press 'T'\n"
        << "To quit the program press 'Q'\n";
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS)
{
    //declare variables
    int i;
    string s;
    //recieve input
    cout << "Please enter the quanity and type (S=small, M=medium, L=large, X=XXXS squirrel-sized) of surfboard you would like to purchase: ";
    cin >> i >> s;
    //If statements to determine which type gets operated
    if (s == "S" || s == "s")
    {
        iTotalSmall += i;
    }
    else if (s == "M" || s == "m")
    {
        iTotalMedium += i;
    }
    else if (s == "L" || s == "l")
    {
        iTotalLarge += i;
    }
    else if (s == "X" || s == "x")
    {
        iTotalXXXS += i;
    }
};

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    //if statements to decide what information to output
    if (iTotalSmall > 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0)
    {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0)
    {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    if (iTotalXXXS > 0)
    {
        cout << "The total number of squirrel surfboards is " << iTotalXXXS << endl;
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0)
    {
        cout << "No purchases made yet.\n";
    }
};

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    //declare constants and variables
    const double dx = 50, ds = 175, dm = 190, dl = 200;
    double stotal, mtotal, ltotal, xtotal, total;
    //perform calculations to find totals
    stotal = ds * iTotalSmall;
    mtotal = dm * iTotalMedium;
    ltotal = dl * iTotalLarge;
    xtotal = dx * iTotalXXXS;
    total = stotal + mtotal + ltotal + xtotal;
    //if statements to determaine what information to output
    if (iTotalSmall > 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall << "at a total of $" << fixed << setprecision(2) << stotal << endl;
    }
    if (iTotalMedium > 0)
    {
        cout << "The total number of medium surfboards is " << iTotalMedium << "at a total of $" << fixed << setprecision(2) << mtotal << endl;
    }
    if (iTotalLarge > 0)
    {
        cout << "The total number of large surfboards is " << iTotalLarge << "at a total of $" << fixed << setprecision(2) << ltotal << endl;
    }
    if (iTotalXXXS > 0)
    {
        cout << "The total number of squirrel surfboards is " << iTotalXXXS << "at a total of $" << fixed << setprecision(2) << xtotal << endl;
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0)
    {
        cout << "No purchases made yet.\n";
    }
    else
    {
        cout << "Amount due: $" << fixed << setprecision(2) << total << endl;
    }
};

int main()
{
    //declare variables
    string s;
    int is = 0, im = 0, il = 0, ix = 0;
    //call first function
    ShowUsage();
    //loop until user decides to quit
    while (s != "Q" && s != "q")
    {
        cout << "\nPlease enter selection: ";
        cin >> s;
        if (s == "S" || s == "s")
        {
            ShowUsage();
        }
        else if (s == "P" || s == "p")
        {
            MakePurchase(is, im, il, ix);
        }
        else if (s == "C" || s == "c")
        {
            DisplayPurchase(is, im, il, ix);
        }
        else if (s == "T" || s == "t")
        {
            DisplayTotal(is, im, il, ix);
        }
        else if (s == "Q" || s == "q")
        {
            cout << "Thank you\n";
        }
        else
        {
            cout << "Not a valid selection\n";
            ShowUsage();
        }
    }
}