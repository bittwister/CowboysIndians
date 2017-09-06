#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	// Constants
	const char cCOWBOY = 'C';
	const char cINDIAN = 'I';

	// Random number generators
	default_random_engine randomEngine(time(NULL));
	uniform_real_distribution<float> whoAttacks(0.0f, 1.0f);
	uniform_real_distribution<float> attackGenerator(0.0f,1.0f);
	uniform_real_distribution<float> defenceGenerator(0.0f, 1.0f);

	// Set cowboy attributes
	float cowHealthMax = 95.0f;
	float cowCurrentHealth = cowHealthMax;
	float cowAttackSuccessProb = 0.4f;
	float cowAttackDamage = 70.0f;
	float cowDefenceSuccessProb = 0.15f;

	// Set indian attributes
	float indHealthMax = 100.0f;
	float indCurrentHealth = indHealthMax;
	float indAttackSuccessProb = 0.3f;
	float indAttackDamage = 30.0f;
	float indDefenceSuccessProb = 0.1f;

	// Number of combatants
	int cowStartCombatants;
	int cowCombatants;
	int	indStartCombatants;
	int indCombatants;

	// Other variables
	char turn;
	float whoAttacksResults;
	float attackResults;
	float defenceResults;

	cout << "--- Cowboys vs Indians ---";
	
	// Get number of combatants
	cout << "\n\n Enter number of cowboys: ";
	cin >> cowStartCombatants;
	cout << " Enter number of indians: ";
	cin >> indStartCombatants;

	cowCombatants = cowStartCombatants;
	indCombatants = indStartCombatants;

	// Determine who attacks first
	cout << "\n\n Determining who attacks first...";

	whoAttacksResults = whoAttacks(randomEngine);
	if (whoAttacksResults < .5) {
		turn = cCOWBOY;
		cout << "\n Cowboys attack first!";
	} else {
		turn = cINDIAN;
		cout << "\n Indians attack first!";
	}
	cout << "\n The battle is raging...";

	// Let the battle begin!!
	while ((cowCombatants > 0) && (indCombatants > 0)){

		attackResults = attackGenerator(randomEngine);
		defenceResults = defenceGenerator(randomEngine);

		if (turn == cCOWBOY) {

			if (attackResults <= cowAttackSuccessProb){
				indCurrentHealth -= cowAttackDamage;

				if (indCurrentHealth <= 0) {
					indCombatants--;
					indCurrentHealth = indHealthMax;
				}
			}
			turn = cINDIAN;
		} else {

			if (attackResults <= indAttackSuccessProb){
				cowCurrentHealth -= indAttackDamage;

				if (cowCurrentHealth <= 0) {
					cowCombatants--;
					cowCurrentHealth = cowHealthMax;
				}
			}
			turn = cCOWBOY;
		}
	}

	if (cowCombatants > 0){
		cout << "\n Cowboys win!\n Unfortunately " << cowStartCombatants - cowCombatants << " were killed.";
	} else {
		cout << "\n Indians win!\n Unfortunately " << indStartCombatants - indCombatants << " were killed.\n\n";
	}
	system("PAUSE");
	return 0;
}