#include <iostream>
#include <algorithm>
#include "Positions_status.hh"

using namespace std;

/*!
 * \brief Realizuje sprawdzenie czy dane pole jest zajęte
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar palnszy
 * \param[in] area - pole na planszy
 * 
 * \return true - w przypadku kiedy pole jest zajęte
 * \return false - w przypadku kiedy pole jest wolne
 */
bool check_if_busy(char **board, unsigned int size, pair<int,int> area)
{
    vector<pair<int,int>> all_busy_positions = busy_positions(board, size);
    vector<pair<int,int>>::iterator iter;

    iter = find(all_busy_positions.begin(),all_busy_positions.end(),area);
    if(iter != all_busy_positions.end()) return true; //jezeli jest znaleziony to wskazuje na pierwszy

    return false;
}


/*!
 * \brief Realizuje zapis wszystkich zajetych pozycji na planszy do wektora
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar palnszy
 * 
 * \return vector<pair<int,int>> - wszystkie zajęte pola
 */
vector<pair<int,int>> busy_positions(char **board, unsigned int size)
{
    vector<pair<int,int>> all_busy_positions;
    all_busy_positions.clear();

    for(unsigned int i=0; i<size; i++)
    {
      for(unsigned int j=0; j<size; j++)
      {
        if(board[i][j] == 'x' or board[i][j] == 'o')
        {
            all_busy_positions.push_back(make_pair(i,j));
        }
      }
    }
    return all_busy_positions;
}


/*!
 * \brief Realizuje zapis wszystkich zajetych pozycji przez jedną z wybranych 
 *        stron rywalizacji na planszy do wektora
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar palnszy
 * \param[in] by_who - wybrana strona rywalizacji
 * 
 * \return vector<pair<int,int>> - wszystkie zajęte pola
 */
vector<pair<int,int>> busy_positions_by(char **board, unsigned int size, char by_who)
{
    vector<pair<int,int>> all_busy_positions;
    all_busy_positions.clear();

    for(unsigned int i=0; i<size; i++)
    {
      for(unsigned int j=0; j<size; j++)
      {
        if(by_who == 'o')
        {
            if(board[i][j] == 'o')
            {
                all_busy_positions.push_back(make_pair(i,j));
            }
        }
        else if(by_who == 'x')
        {
            if(board[i][j] == 'x')
            {
                all_busy_positions.push_back(make_pair(i,j));
            }
        }
      }
    }
    return all_busy_positions;
}


/*!
 * \brief Realizuje zapis wszystkich wolnych pozycji na planszy do wektora
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar palnszy
 * 
 * \return vector<pair<int,int>> - wszystkie wolne pola
 */
vector<pair<int,int>> free_positions(char **board, unsigned int size)
{
    vector<pair<int,int>> all_free_positions;
    all_free_positions.clear();

    for(unsigned int i=0; i<size; i++)
    {
      for(unsigned int j=0; j<size; j++)
      {
        if((board[i][j] != 'x') and (board[i][j] != 'o'))
        {
            all_free_positions.push_back(make_pair(i,j));
        }
      }
    }
    return all_free_positions;
}


/*!
 * \brief Realizuje sprawdzenie czy plansza do gry posiada wszystkie zajęte pola
 * 
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar palnszy
 * 
 * \return true - w przypadku pełnej planszy
 * \return false - w przypadku niezapełnionej planszy
 */
bool check_if_full(char **board, unsigned int size)
{
    if(busy_positions(board,size).size() == (size*size)) return true;

    return false;
}