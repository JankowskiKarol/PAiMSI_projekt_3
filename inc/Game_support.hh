#ifndef GAMESUPPORT_HH
#define GAMESUPPORT_HH

#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "Min-Max.hh"

using namespace std;

/*!
 * \brief Deklaracja funkcji wypełniającej planszę pustymi polami
 *
 */
void empty_board(char **, unsigned int );

/*!
 * \brief Deklaracja funkcji wyświetlającej planszę
 */
void show_board(char **, unsigned int );

/*!
 * \brief Deklaracja funkcji wyświetlającej informacje o zakończonej grze
 */
void show_info(char **, unsigned int , vector<vector<pair<int,int>>> );

/*!
 * \brief Deklaracja funkcji ustalającej głębopkość wywołań
 */
int depth(unsigned int );

#endif
