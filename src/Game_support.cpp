#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Game_support.hh"
#include "Game_status.hh"

using namespace std;

/*!
 * \brief realizuje uzupełnienie planszy do gry pustymi polami
 *
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * 
 */
  void empty_board(char **board, unsigned int size)
  {
    for(unsigned int i=0; i<size; i++)
    {
      for(unsigned int j=0; j<size; j++)
      {
        board[i][j] = ' ';
      }
    }
  }


/*!
 * \brief realizuje wyświetlenie planszy do gry
 *
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * 
 */
  void show_board(char **board, unsigned int size)
  {
    cout << endl << "+-";
      for(unsigned int n=0; n<size-1; n++)
      {
        cout << "+-";
      }
      cout <<"+";
      cout << endl;
    for(unsigned int i=0; i<size; i++)
    {
      cout << "|";
      for(unsigned int j=0; j<size; j++)
      {
        cout<< board[i][j] << "|";  
      }
      cout << endl;
      cout << "+-";
      for(unsigned int n=0; n<size-1; n++)
      {
        cout << "+-";
      }
      cout <<"+";
      cout << endl;
    }
    cout << endl;
    
  }



/*!
 * \brief realizuje wyświetlenie rezultatu zakończonej gry
 *
 * \param[in] board - tablica z polami planszy
 * \param[in] size - rozmiar planszy do gry
 * \param[in] win_options - wektor wszystkich konfiguracji wygranych 
 * 
 */
void show_info(char **board, unsigned int size, vector<vector<pair<int,int>>> win_options)
{
  int who_won = check_status(board, size, win_options, 'x');
    switch (who_won)
    {
    case 0:
        cout << endl << "Remis" << endl << endl;
        break;
    case 1000:
        cout << endl << "Wygrałeś" << endl << endl;
        break;
    case -1000:
        cout << endl << "Komputer wygrał" << endl << endl;
        break;
    default:
        break;
    }
}


/*!
 * \brief realizuje ustalenie głębokości wywołań w zależności od rozmiaru planszy
 *
 * \param[in] size - rozmiar planszy do gry
 * 
 * \return głębokość wywołań
 * 
 */
int depth(unsigned int size)
{
    int Max = 0;
    switch (size)
    {
    case 3:
        Max = 9;
        break;
    case 4:
        Max = 5;
        break;
    case 5:
        Max = 4;
        break;
    case 6:
        Max = 3;
        break;
    case 7:
        Max = 3;
        break;
    case 8:
        Max = 3;
        break;
    
    default:
        break;
    }
    return Max;
}



