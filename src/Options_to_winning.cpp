#include <iostream>
#include <vector>
#include "Options_to_winning.hh"
#include "Positions_status.hh"

using namespace std;

/*!
 * \brief Realizuje ustalenie wszystkich konfiguracji możliwych wygranych i zapisuje je do wektora
 * 
 * \param[in] size - rozmiar pola
 * \param[in] win_options - rekurencja do wektora wszystkich konfiguracji wygranych 
 * 
 */
void Winning_options(unsigned int size, vector<vector<pair<int,int>>> &win_options)
{
    vector<pair<int,int>> help;

    /* ustawienie wszystkich opcji w kolumnach */
    help.clear();
    for(unsigned int i=0; i<size; i++)
    {
        for(unsigned int j=0; j<size; j++)
        {
            help.push_back(make_pair(j,i));
        }
        win_options.push_back(help);
        //help = win_options[0];
        help.clear();
    }

    /* ustawienie wszystkich opcji w wierszach */
    help.clear();
    for(unsigned int i=0; i<size; i++)
    {
        for(unsigned int j=0; j<size; j++)
        {
            help.push_back(make_pair(i,j));
        }
        win_options.push_back(help);
        help.clear();
    }

    /* ustawienie wszystkich opcji przekątnych */
    help.clear();
    for(unsigned int i=0; i<size; i++)
    {
        help.push_back(make_pair(i,i));
    }
    win_options.push_back(help);
    help.clear();
    for(unsigned int i=0; i<size; i++)
    {
        help.push_back(make_pair((size-(i+1)),i));
    }
    win_options.push_back(help);
   
}
