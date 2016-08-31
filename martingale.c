#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "martingale.h"

int main() {
	// Seed the number generator
	srand((unsigned)time(NULL));

	int round = 0;
	int bank = 2000;
	int baseBet = 10;
	int odds = 2;
	double chance = 0.4;

	int currentBet = baseBet;
	while (bank > 0 && bank <= MAX_BANK) {
		round++;
		int winnings = computeRound(currentBet, chance, odds);
		bank += winnings;
		currentBet = (winnings < 0) ? currentBet * 2 : baseBet;
		if (round % 10 == 0)
			printf("Round %5d | bank %9d | bet %9d\n", round, bank, currentBet);
	}
	printf("Round %5d | bank %9d | bet %9d\n", round, bank, currentBet);

}

/*
 * Compute a single round. Win chance of 'chance' to scale the 'bet' by 'odds'.
 * Return amount won/lost.
 */
int computeRound(int bet, double chance, int odds) {
	return (((double)rand() / (double)RAND_MAX) < chance) ? bet * odds : bet * -1;
}

