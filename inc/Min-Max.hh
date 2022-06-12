#ifndef MINMAX_HH
#define MINMAX_HH

#include <vector>

using namespace std;

/*!
 * \brief Deklaracja funkcji realizującej algorytm minimax z alfa, beta cięciami
 */
pair<int,pair<int,int>> Minimax_with_alpha_and_beta_pruning(char **,unsigned int, int, int, int, char, vector<vector<pair<int,int>>> );

#endif
