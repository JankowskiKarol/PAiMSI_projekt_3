#include <iostream>
#include <vector>
#include <algorithm>
#include "Game_status.hh"
#include "Positions_status.hh"

using namespace std;

/*!
 * \brief Realizuje sprawdzenie czy gra będzie kontynuowana, czy nastąpiła wygrana którejś ze stron 
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * \param[in] win_options - wektor wszystkich konfiguracji wygranych 
 *
 * \return true - jezeli gra będzie kontynuowana
 * \return false - jezeli gra nie będzie kontynuowana
 */
bool are_we_still_playing(char **board, unsigned int size, vector<vector<pair<int,int>>> win_options)
{
    vector<pair<int,int>> all_busy_positions;
    all_busy_positions.clear();
    all_busy_positions = busy_positions_by(board,size,'o');
    if(is_it_won(all_busy_positions,size,win_options))
    {
        /* komputer wygarał */
        return false; 
    }
    all_busy_positions.clear();
    all_busy_positions = busy_positions_by(board,size,'x');
    if(is_it_won(all_busy_positions,size,win_options)) 
    {
        /* gracz wygrał */
        return false;
    }

    return true;
}


/*!
 * \brief Realizuje sprawdzenie stanu gry czy podana strona wygrywa czy przegrywa lub czy jest remis
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * \param[in] win_options - wszystkie mozliwosci wygranej
 * \param[in] player - znak gracza
 *
 * \return wartość przyporządkowaną dla stanu gry
 */
int check_status(char **board, unsigned int size, vector<vector<pair<int,int>>> win_options, char player)
{
    char the_other_side;
    vector<pair<int,int>> all_busy_positions;

    if(player == 'x')
    {
        the_other_side = 'o';
    }
    else
    {
        the_other_side = 'x';
    }

    all_busy_positions.clear();
    all_busy_positions = busy_positions_by(board,size,player);
    if(is_it_won(all_busy_positions,size,win_options))
    {
        return 1000;
    }
    all_busy_positions.clear();
    all_busy_positions = busy_positions_by(board,size,the_other_side);
    if(is_it_won(all_busy_positions,size,win_options)) 
    {
        return -1000;
    }

    return 0;
}


/*!
 * \brief Realizuje sprawdzenie, czy nastąpiła wygrana dla danego wektora pozycji zajętych przez jedną ze stron
 * 
 * \param[in] vector<pair<int,int>> all_busy_positions - wektor zajetych pozycji przez badaną stronę rozgrywki
 * \param[in] size - rozmiar planszy do gry
 * \param[in] win_options - wektor wszystkich konfiguracji wygranych 
 *
 * \return true - jezeli gra jest wygrana
 * \return false - jezeli gra nie jest wygrana
 */
bool is_it_won(vector<pair<int,int>> all_busy_positions, unsigned int size, vector<vector<pair<int,int>>> win_options)
{
    bool win = true;

    for(unsigned int i=0; i<win_options.size(); i++)
    {
        vector<pair<int,int>> option_to_win = win_options[i];
        vector<pair<int,int>>::iterator iter;
        win = true;
        for(unsigned int j=0; j<size; j++)
        {
            iter = find(all_busy_positions.begin(),all_busy_positions.end(),option_to_win[j]);
            if(!(iter != all_busy_positions.end()))
            {
                win = false; 
                break;
            }  
        }
        if(win) break;
    }
    return win;
}


/*!
 * \brief Realizuje sprawdzenie, czy nastąpiła wygrana jakiejkolwiek strony lub plansza jest pełna
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * \param[in] win_options - wektor wszystkich konfiguracji wygranych 
 *
 * \return true - jezeli gra jest zakończona
 * \return false - jezeli gra nie jest zakończona
 */
bool is_it_end(char **board, unsigned int size, vector<vector<pair<int,int>>> win_options)
{
    if((are_we_still_playing(board,size,win_options) == false)) return true;
    if(check_if_full(board,size)) return true;

    return false;
}