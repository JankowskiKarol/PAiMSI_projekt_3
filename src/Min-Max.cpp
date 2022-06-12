#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "Min-Max.hh"
#include "Positions_status.hh"
#include "Game_status.hh"

using namespace std;

/*!
 * \brief realizuje algorytmu minimalizowania maksymlanyvh możliwych strat wraz z redukowaniem liczby węzłów, które muszą być przeszukane
 *
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * \param[in] depth - głębokość przeszukiwań
 * \param[in] alpha - wartość min dla redukcji liczby węzłów
 * \param[in] beta - wartość max dla redukcji liczby węzłów
 * \param[in] sign - znak gracza
 * \param[in] vector<vector<pair<int,int>>> win_options - wektor wszystkich możliwych opcji wygranej
 * 
 * \return pair<int,pair<int,int>> - wartość dla danego ruchu oraz ruch
 * 
 */
pair<int,pair<int,int>> Minimax_with_alpha_and_beta_pruning(char **board, unsigned int size, int depth, int alpha, int beta, char sign, vector<vector<pair<int,int>>> win_options)
{
    pair<int,int> move;
    vector<pair<int,int>> all_options = free_positions(board,size);
    int Best_case = (sign == 'o') ? -1000 : 1000;

    if(is_it_end(board,size,win_options) or depth == 0)
    {
        Best_case = check_status(board,size,win_options, 'o');
        return make_pair(Best_case,move);
    }

    for(int i=0; i<all_options.size(); i++)
    {
        pair<int,int> current = all_options[i];
        board[current.first][current.second] = sign; // możliwy ruch

        if(sign == 'o')
        {
            int score = Minimax_with_alpha_and_beta_pruning(board,size,depth-1,alpha,beta,'x', win_options).first;
            board[current.first][current.second] = ' '; // cofa ruch

            if(Best_case < score)
            {
                Best_case = score - depth * 10;
                move = current;
                alpha = max(alpha,Best_case);
                board[current.first][current.second] = ' '; // cofa ruch
                if(beta <= alpha) break;
            }
        }
        else
        {
            int score = Minimax_with_alpha_and_beta_pruning(board,size,depth-1,alpha,beta,'o', win_options).first;
            board[current.first][current.second] = ' '; // cofa ruch
            if(Best_case > score)
            {
                Best_case = score + depth * 10;
                move = current;
                beta = min(beta,Best_case);
                if(beta <= alpha) break;
            }

        }
        board[current.first][current.second] = ' '; // cofa ruch
    }
    return(make_pair(Best_case,move));
}