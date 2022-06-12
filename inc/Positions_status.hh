#ifndef POSITIONSSTATUS_HH
#define POSITIONSSTATUS_HH

#include "vector"

using namespace std;

/*!
 * \brief Deklaracja funkcji realizującej zapis wszystkich zajętych pozycji w grze
 *
 */
vector<pair<int,int>> busy_positions(char **, unsigned int);

/*!
 * \brief Deklaracja funkcji realizującej zapis wszystkich zajętych pozycji w grze przez wybrana strone rywalizacji
 *
 */
vector<pair<int,int>> busy_positions_by(char **, unsigned int, char );

/*!
 * \brief Deklaracja funkcji realizującej zapis wszystkich wolnych pozycji w grze
 *
 */
vector<pair<int,int>> free_positions(char **, unsigned int);

/*!
 * \brief Deklaracja funkcji realizującej sprawdzenie czy pozycja jest zajęta
 *
 */
bool check_if_busy(char **, unsigned int, pair<int,int> );

/*!
 * \brief Deklaracja funkcji realizującej sprawdzenie czy plansza jest zapełniona
 *
 */
bool check_if_full(char **, unsigned int);


#endif


