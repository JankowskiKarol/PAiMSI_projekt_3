#ifndef GAMESTATUS_HH
#define GAMESTATUS_HH

using namespace std;

/*!
 * \brief Deklaracja funkcji sprawdzającej czy jest wygrana 
 *
 */
bool is_it_won(vector<pair<int,int>> ,unsigned int, vector<vector<pair<int,int>>> );

/*!
 * \brief Deklaracja funkcji sprawdzającej czy gra będzie kontynuowana
 *
 */
bool are_we_still_playing(char **, unsigned int, vector<vector<pair<int,int>>>, int &);

/*!
 * \brief Deklaracja funkcji sprawdzającej status jednej ze strony gry
 *
 */
int check_status(char **, unsigned int, vector<vector<pair<int,int>>>, char);

/*!
 * \brief Deklaracja funkcji sprawdzającej czy gra nie zakończyła się
 *
 */
bool is_it_end(char **, unsigned int, vector<vector<pair<int,int>>>);

#endif
