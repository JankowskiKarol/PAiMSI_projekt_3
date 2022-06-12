#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "Min-Max.hh"
#include "Game_support.hh"
#include "Positions_status.hh"
#include "Game_status.hh"
#include "Options_to_winning.hh"

using namespace std;

int main()
{
    vector<vector<pair<int,int>>> win_options;
    unsigned int size;
    int alpha = -1000;
    int beta = 1000;

    cout << endl << "Podaj rozmiar planszy do gry:\t";
    cin >> size;

    char **board = new char *[size];
    for(unsigned int i=0; i<size; i++)
    {
        board[i] = new char [size];
    }

    Winning_options(size,win_options);
    empty_board(board,size);
    show_board(board,size);
    int m_depth = depth(size);

    while(!is_it_end(board,size,win_options))
    {
        unsigned int x = 0;
        unsigned int y = 0;
        do
        {
            if(x >= size || y >= size)
            {
            cout << "Pozycja niedozwolona - brak pola na planszy" << endl;
            }
            cout << "Podaj pozycję w wierszu:\t";
            cin >> x;
            cout << "Podaj pozycję w kolumnie:\t";
            cin >> y;
            cout << endl << endl;
            if(check_if_busy(board,size,make_pair(x,y)))
            {
                cout << "Pozycja niedozwolona - pole jest już zajęte" << endl;
            }
        }
        while (x>=size || y>=size || check_if_busy(board,size,make_pair(x,y)));
        
        board[x][y] = 'x';

        if(is_it_end(board,size,win_options)) 
        {
            break;
        }
        else
        {     
           pair<int,int> move = Minimax_with_alpha_and_beta_pruning(board,size,m_depth,alpha,beta,'o', win_options).second;
           board[move.first][move.second] = 'o';
        }
        show_board(board,size);
    }
    show_info(board,size,win_options);
    
    return 0;
}

