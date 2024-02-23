#include "agent.h"
#include "types.h"
#include <math.h>


// w(i) are the # of agent pieces > opponent pieces
// n(i) is the # of times this state was visited
// N(i) is the # of times the parent node was visited
// c is exploration param. (sqrt(2))
double stateEval(char player, StateNode* state) {
  int black = 0, white = 0;

  for (U64 square = 0; square < 64; square++) {
    if (square % 2 && (state->board.whole[square] & 1)) black++;
    else if (state->board.whole[square] & 1) white++;
  }

  int w = (player == 'B') ? black-white : white-black; 
  
  int smallN = state->visits;
  int bigN = state->prev->visits;
  
  return (w/smallN) + (ROOT2 * sqrt(log(bigN)/smallN));
}
