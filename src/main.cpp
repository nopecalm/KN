#include <iostream>

using namespace std;

	char cells[3][3];
        int row;
        int column;

void start()
{
    cout << "Welcome to the game!" << endl;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cells[i][j]='7';
            cout << cells[i][j];
        }
        cout << endl;
    }
}

bool stepCheck(string sRow, string sColumn)
{
    if (sRow.length() != 1)
        return true;
    else
    {
        if (!isdigit(sRow[0]))
            return true;
        else
        {
            row = stoi(sRow);
            if ((row < 1) || (row > 3))
                 return true;
        }
    }

    if (sColumn.length() != 1)
        return true;
    else
    {
        if (!isdigit(sColumn[0]))
            return true;
        else
        {
            column = stoi(sColumn);
            if ((column < 1) || (column > 3))
                 return true;
        }
    }

    cout << "cells[row][column] " << cells[row-1][column-1] << endl;

    if (cells[row-1][column-1] != '7')
    {
        return true;
    }


    return false;
}


void step(bool playerNum)
{	
	char c;
        string sRow;
        string sColumn;

	if (playerNum == false)
		c = 'x';
	else
		c = '0';

 	int iPlayerNum;

	if (playerNum == false)
		iPlayerNum = 1;
	if (playerNum == true)
		iPlayerNum = 2;

	cout << "Player " << iPlayerNum << ": enter the row number" << endl;
        cin >> sRow;

	cout << "Player " << iPlayerNum << ": enter the column number" << endl;
        cin >> sColumn;

        if (stepCheck(sRow, sColumn) == true)
        {
            cout << "Error." << endl;
            step(playerNum);
        }
        else
        {
             row = stoi(sRow);
             column = stoi(sColumn);
             cells[row-1][column-1]= c;

             for(int i=0;i<3;i++)
             {
                  for(int j=0;j<3;j++)
                  {
                    cout << cells[i][j];
                  }
                  cout << endl;
             }
        }
}

bool winCheck()
{
		if (

                       ((cells[0][0] == cells[0][1]) && (cells[0][1] == cells [0][2]) && cells[0][0] != '7')
                    || ((cells[1][0] == cells[1][1]) && (cells[1][1] == cells [1][2]) && cells[1][1] != '7')
                    || ((cells[2][0] == cells[2][1]) && (cells[2][1] == cells [2][2]) && cells[2][2] != '7')
                    || ((cells[0][0] == cells [1][0]) && (cells[1][0] == cells[2][0]) && cells[0][0] != '7')
                    || ((cells[0][1] == cells [1][1]) && (cells[1][1] == cells[2][1]) && cells[1][1] != '7')
                    || ((cells[0][2] == cells [1][2]) && (cells[1][2] == cells[2][2]) && cells[2][2] != '7')
		    || ((cells[0][0] == cells [1][1]) && (cells[2][2] == cells[1][1]) && cells[0][0] != '7')
                    || ((cells[0][2] == cells [1][1]) && (cells[2][0] == cells[1][1]) && cells[1][1] != '7')

		    )
		    return true;

                return false;
}

bool tieCheck()
{
        for(int i=0;i<3;i++)
        {
          for(int j=0;j<3;j++)
          {
            if (cells[i][j] == '7')
	    return false;
          }
	}

	return true;
	
}

int main()
{

    start();

    while (true)
    {
        step(false);

        if (winCheck() == true)
        {
            cout << "Player 1 wins!" << endl;
            break;
        }

        if (tieCheck() == true)
        {
            cout << "Tie." << endl;
            break;
        }

        step(true);

      	if (winCheck() == true)
	{
	    cout << "Player 2 wins!" << endl;
	    break;
	}


    }
        cout << "Game is over" << endl;
    return 0;
}

