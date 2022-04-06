#include <string>
// Rpg headers
#include "graphics.h" 
/*
   string healthBar(int userHealth) {
   for (int i = 20; i < 200; i+20) {
   if userHealth < i+

*/
string healthBar(int userHealth) {
	if (userHealth < 20) return "🤍";
	else if (userHealth < 30) return "🤍🤍";
	else if (userHealth < 40) return "🤍🤍🤍";
	else if (userHealth < 50) return "🤍🤍🤍🤍";
	else if (userHealth < 60) return "🤍🤍🤍🤍🤍";
	else if (userHealth < 70) return "🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 80) return "🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 90) return "🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 100) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 110) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 120) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 130) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 140) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 150) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 150 && userHealth < 160) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 160 && userHealth < 170) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 170 && userHealth < 180) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 180 && userHealth < 190) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 190 && userHealth < 200) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth == 200) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth > 200) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍+";
	return "ERROR";
}
void combatGameAttack(int &bossHealth) {
	int attackDamage = rand() % 20 + 20;
	bossHealth = bossHealth - attackDamage;
	cout << "Wow! You did " << attackDamage << " damage to the boss!" << endl;
}
void combatGamePotion(int &userHealth, int &numPotions) {
	userHealth = userHealth + 20;
	numPotions--;
	cout << "Your health is now " << userHealth << "." << endl;
}
void youMessedUp(string moveChoice) {
	if (moveChoice != "1" and moveChoice != "2") {
		cout << "You lost your turn and did no damage!" << endl;
	} else {
		cout << "ERROR" << endl;
	}
}
void combatGame(int numCheese, int numPots) {
	system("clear");
	int userHealth = 100, bossHealth = 200;
	string moveChoice;
	cout << "Hello! Welcome to the final boss!\n";
	cout << "Choose your attacks wisely, you're facing a final boss who has double your health!\n";
	cout << "I advise you to use whatever potions you have earned, those will help you last with the final boss and defeat him!\n";
	while (userHealth > 0 or bossHealth > 0) {
		if (userHealth <= 0 or bossHealth <= 0) break;
		cout << "Your Health: " << userHealth << " " << healthBar(userHealth) << endl;
		cout << "Boss Health: " << bossHealth << " " << healthBar(bossHealth) << endl;
		if (numPots > 0) {
			cout << "Number of Potions: " << numPots << endl;
		}
		cout << "Number of Cheese: " << numCheese << endl;
		if (numPots > 0) {
			cout << "Choose your move: Sword Attack (1) (Damage 0-20), Potion (2) (+20 health)\n";
		} else {
			cout << "Choose your move: Sword Attack (1) (Damage 0-20)\n";
		}

		cin >> moveChoice;
		if (moveChoice == "1") {
			combatGameAttack(bossHealth);
		} else if (moveChoice == "2" && numPots > 0) {
			combatGamePotion(userHealth, numPots);
		} else {
			youMessedUp(moveChoice);
		}

		if (userHealth <= 0 or bossHealth <= 0) break;
		int bossAttackDamage = rand() % 30;
		userHealth = userHealth - bossAttackDamage;
		cout << "The boss did " << bossAttackDamage << " damage to your health." << endl;
	}
	if (userHealth <= 0) print_ending(0);
	if (bossHealth <= 0) print_ending(1);
}
