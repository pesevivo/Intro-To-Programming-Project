#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

short const WORDS_IN_DICTIONARY = 4;

struct FourLetterWords {
	char fourWord[5];
};

struct FiveLetterWords {
	char fiveWord[6];
};

struct SixLetterWords {
	char sixWord[7];
};

struct AllWords {
	char anyWord[7];
};

FourLetterWords fourLetterDict[WORDS_IN_DICTIONARY] = {

	{"duck"},
	{"sand"},
	{"crab"},
	{"cork"}
};

FiveLetterWords fiveLetterDict[WORDS_IN_DICTIONARY] = {

	{"horse"},
	{"baron"},
	{"graph"},
	{"flare"}
};

SixLetterWords sixLetterDict[WORDS_IN_DICTIONARY] = {

	{"shovel"},
	{"marble"},
	{"sunday"},
	{"spring"}
};

AllWords fullDict[3*WORDS_IN_DICTIONARY] = {
	{"duck"},
	{"horse"},
	{"marble"},
	{"sand"},
	{"shovel"},
	{"crab"},
	{"baron"},
	{"graph"},
	{"sunday"},
	{"spring"},
	{"flare"},
	{"cork"}
};

short StrlenAllWords(AllWords gameWord[], short randomWord) {			// Finds the length of the randomly picked word for the game;
	short i = 0;
	short counter = 0;
	while (gameWord[randomWord].anyWord[i] != '\0') {
		counter++;
		i++;
	}
	return counter;
}

short StrlenFourLetterWords(FourLetterWords gameWord[], short randomWord) {			// Finds the length of the randomly picked word for the game;
	short i = 0;
	short counter = 0;
	while (gameWord[randomWord].fourWord[i] != '\0') {
		counter++;
		i++;
	}
	return counter;
}

short StrlenFiveLetterWords(FiveLetterWords gameWord[], short randomWord) {			// Finds the length of the randomly picked word for the game;
	short i = 0;
	short counter = 0;
	while (gameWord[randomWord].fiveWord[i] != '\0') {
		counter++;
		i++;
	}
	return counter;
}

short StrlenSixLetterWords(SixLetterWords gameWord[], short randomWord) {			// Finds the length of the randomly picked word for the game;
	short i = 0;
	short counter = 0;
	while (gameWord[randomWord].sixWord[i] != '\0') {
		counter++;
		i++;
	}
	return counter;
}

short CorrectInputUserNav(short userNav, short lowerBound, short upperBound) {
	while (true) {

		cin >> userNav;

		if (std::cin.fail()) {
			cout << "\n" << "Incorrect input! " << "\n" << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if ((userNav <= lowerBound) || (userNav >= upperBound)) {
			cout << "\n" << "Incorrect input! " << "\n" << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}
	return userNav;
}

char CorrectInputLetter(char inputLetter, char lowerBound, char upperBound) {
	while (true) {

		cout << "Your letter: ";
		cin >> inputLetter;

		if (std::cin.fail()) {
			cout << "\n" << "Incorrect input! " << "\n" << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if ((inputLetter < lowerBound) || (inputLetter > upperBound)) {
			cout << "\n" << "Incorrect input! " << "\n" << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}
	return inputLetter;
}


int main() {

	srand(time(NULL));				// Generates a seed for the generation of random numbers;
	short attemptsCount = 5;
	short attemptCountReadjust = 5;

	while (true) {		// After the game ends, the player is redirected back to the main menu below;

		short userNav = 0;
		char inputLetter = NULL;

		short wordLen = 0;
		bool wrongLetter = true;		// Flag for attemptsCount;
		char usedLetters[27];			// For 26 letters in the English alphabet;

		char correctLetters[6];			// Stores the correctly guessed letters by the user;
		short correctLettersCount = 0;	// Used as index for the 'CorrectLettersCount[6]' array;
		bool printUnderscore = false;	// If the value is 'true' an underscore will not be printed;

		attemptsCount = attemptCountReadjust;

		cout << "Select an option from the main menu: " << "\n" << endl;
		cout << "1. Start game" << endl;
		cout << "\n" << "2. Settings" << endl;
		cout << "\n" << "  1. Change word length" << endl;
		cout << "\n" << "  2. Change number of attempts" << endl;
		cout << "\n" << "3. Exit game" << "\n" << endl;

		userNav = CorrectInputUserNav(userNav, 0, 4);

		// Exit game;
		if (userNav == 3) {
			cout << "\n" << "Thank you for playing! " << endl;
			return 0;
		}

		// Settings;
		else if (userNav == 2) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n" << "Choose option '1' or '2' from 'Settings': " << "\n" << endl;
			userNav = CorrectInputUserNav(userNav, 0, 3);

			// Settings / Change word length;
			if (userNav == 1) {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				cout << "\n" << "Choose word length: " << endl;
				cout << "\n" << "1. Words with 4 letters " << endl;
				cout << "\n" << "2. Words with 5 letters " << endl;
				cout << "\n" << "3. Words with 6 letters " << "\n" << endl;

				userNav = CorrectInputUserNav(userNav, 0, 4);


				// Settings / Change word length / Game starts with only 4-letter words;
				if (userNav == 1) {

					attemptsCount = attemptCountReadjust;

					short randomWord = rand() % WORDS_IN_DICTIONARY;			// Generates a random number between 0 and (WORDS_IN_DICTIONARY - 1), (including those two);

					wordLen = StrlenFourLetterWords(fourLetterDict, randomWord);

					// Prints Guess a letter: _ _ _ _ (_ _)		"Attempts left: (count)	"

					cout << "\n" << "Guess a letter: ";
					for (int i = 0; i < wordLen; i++) {
						cout << "_ ";
					}
					cout << "	Attempts left: " << attemptsCount << "\n" << endl;

					short usedLettersCount = 0;		// Counter for used letters;
					bool flag = false;				// It is used when a repeating input letter is encountered; it tells the 'While' loop to skip the current iteration;

					while (attemptsCount > 0) {
						flag = false;
						inputLetter = CorrectInputLetter(inputLetter, 'a', 'z');

						for (int i = 0; i < usedLettersCount; i++) {

							if (inputLetter == usedLetters[i]) {
								cout << "\n" << "Try another letter, you have already used this one! " << "\n" << endl;
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								flag = true;
							}
						}
						if (flag == true) continue;

						cout << "\n" << "Guess a letter: ";

						for (int i = 0; i < wordLen; i++) {
							if (inputLetter == fourLetterDict[randomWord].fourWord[i]) {

								correctLetters[correctLettersCount] = inputLetter;
								correctLettersCount++;

								wrongLetter = false;
							}
						}


						for (int i = 0; i < wordLen; i++) {
							for (int j = 0; j < correctLettersCount; j++) {

								if (fourLetterDict[randomWord].fourWord[i] == correctLetters[j]) {
									cout << correctLetters[j] << " ";
									printUnderscore = true;
								}
								else if ((j == correctLettersCount - 1) && printUnderscore == false) cout << "_ ";
							}

							if (correctLettersCount == 0) cout << "_ ";		// For the case in which the user hasn't guessed a single letter yet;

							printUnderscore = false;
						}


						if (wrongLetter == true) attemptsCount--;

						usedLetters[usedLettersCount] = inputLetter;
						usedLettersCount++;
						cout << "	Attempts left: " << attemptsCount << "\n" << endl;

						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						wrongLetter = true;

						if (wordLen == correctLettersCount) {
							cout << "\n" << "Congratulations, you guessed the word '" << fourLetterDict[randomWord].fourWord << "' !" << "\n" << "Returning to main menu..." << "\n \n" << endl;
							break;
						}
						else if (attemptsCount == 0) {
							cout << "\n" << "You lose! The word is: '" << fourLetterDict[randomWord].fourWord << "'" << "\n" << "Returning to main menu..." << "\n \n" << endl;
						}
					}
				}


				// Settings / Change word length / Game starts with only 5-letter words;
				else if (userNav == 2) {

					attemptsCount = attemptCountReadjust;

					short randomWord = rand() % WORDS_IN_DICTIONARY;			// Generates a random number between 0 and (WORDS_IN_DICTIONARY - 1), (including those two);

					wordLen = StrlenFiveLetterWords(fiveLetterDict, randomWord);

					// Prints Guess a letter: _ _ _ _ (_ _)		"Attempts left: (count)	"

					cout << "\n" << "Guess a letter: ";
					for (int i = 0; i < wordLen; i++) {
						cout << "_ ";
					}
					cout << "	Attempts left: " << attemptsCount << "\n" << endl;

					short usedLettersCount = 0;		// Counter for used letters;
					bool flag = false;				// It is used when a repeating input letter is encountered; it tells the 'While' loop to skip the current iteration;

					while (attemptsCount > 0) {
						flag = false;
						inputLetter = CorrectInputLetter(inputLetter, 'a', 'z');

						for (int i = 0; i < usedLettersCount; i++) {

							if (inputLetter == usedLetters[i]) {
								cout << "\n" << "Try another letter, you have already used this one! " << "\n" << endl;
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								flag = true;
							}
						}
						if (flag == true) continue;

						cout << "\n" << "Guess a letter: ";

						for (int i = 0; i < wordLen; i++) {
							if (inputLetter == fiveLetterDict[randomWord].fiveWord[i]) {

								correctLetters[correctLettersCount] = inputLetter;
								correctLettersCount++;

								wrongLetter = false;
							}
						}


						for (int i = 0; i < wordLen; i++) {
							for (int j = 0; j < correctLettersCount; j++) {

								if (fiveLetterDict[randomWord].fiveWord[i] == correctLetters[j]) {
									cout << correctLetters[j] << " ";
									printUnderscore = true;
								}
								else if ((j == correctLettersCount - 1) && printUnderscore == false) cout << "_ ";
							}

							if (correctLettersCount == 0) cout << "_ ";		// For the case in which the user hasn't guessed a single letter yet;

							printUnderscore = false;
						}


						if (wrongLetter == true) attemptsCount--;

						usedLetters[usedLettersCount] = inputLetter;
						usedLettersCount++;
						cout << "	Attempts left: " << attemptsCount << "\n" << endl;

						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						wrongLetter = true;

						if (wordLen == correctLettersCount) {
							cout << "\n" << "Congratulations, you guessed the word '" << fiveLetterDict[randomWord].fiveWord << "' !" << "\n" << "Returning to main menu..." << "\n \n" << endl;
							break;
						}
						else if (attemptsCount == 0) {
							cout << "\n" << "You lose! The word is: '" << fiveLetterDict[randomWord].fiveWord << "'" << "\n" << "Returning to main menu..." << "\n \n" << endl;
						}
					}
				}


				// Settings / Change word length / Game starts with only 6-letter words;
				else if (userNav == 3) {

					attemptsCount = attemptCountReadjust;

					short randomWord = rand() % WORDS_IN_DICTIONARY;			// Generates a random number between 0 and (WORDS_IN_DICTIONARY - 1), (including those two);

					wordLen = StrlenSixLetterWords(sixLetterDict, randomWord);

					// Prints Guess a letter: _ _ _ _ (_ _)		"Attempts left: (count)	"

					cout << "\n" << "Guess a letter: ";
					for (int i = 0; i < wordLen; i++) {
						cout << "_ ";
					}
					cout << "	Attempts left: " << attemptsCount << "\n" << endl;

					short usedLettersCount = 0;		// Counter for used letters;
					bool flag = false;				// It is used when a repeating input letter is encountered; it tells the 'While' loop to skip the current iteration;

					while (attemptsCount > 0) {
						flag = false;
						inputLetter = CorrectInputLetter(inputLetter, 'a', 'z');

						for (int i = 0; i < usedLettersCount; i++) {

							if (inputLetter == usedLetters[i]) {
								cout << "\n" << "Try another letter, you have already used this one! " << "\n" << endl;
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								flag = true;
							}
						}
						if (flag == true) continue;

						cout << "\n" << "Guess a letter: ";

						for (int i = 0; i < wordLen; i++) {
							if (inputLetter == sixLetterDict[randomWord].sixWord[i]) {

								correctLetters[correctLettersCount] = inputLetter;
								correctLettersCount++;

								wrongLetter = false;
							}
						}


						for (int i = 0; i < wordLen; i++) {
							for (int j = 0; j < correctLettersCount; j++) {

								if (sixLetterDict[randomWord].sixWord[i] == correctLetters[j]) {
									cout << correctLetters[j] << " ";
									printUnderscore = true;
								}
								else if ((j == correctLettersCount - 1) && printUnderscore == false) cout << "_ ";
							}

							if (correctLettersCount == 0) cout << "_ ";		// For the case in which the user hasn't guessed a single letter yet;

							printUnderscore = false;
						}


						if (wrongLetter == true) attemptsCount--;

						usedLetters[usedLettersCount] = inputLetter;
						usedLettersCount++;
						cout << "	Attempts left: " << attemptsCount << "\n" << endl;

						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						wrongLetter = true;

						if (wordLen == correctLettersCount) {
							cout << "\n" << "Congratulations, you guessed the word '" << sixLetterDict[randomWord].sixWord << "' !" << "\n" << "Returning to main menu..." << "\n \n" << endl;
							break;
						}
						else if (attemptsCount == 0) {
							cout << "\n" << "You lose! The word is: '" << sixLetterDict[randomWord].sixWord << "'" << "\n" << "Returning to main menu..." << "\n \n" << endl;
						}
					}
				}
			}


			// Settings / Change number of attempts;
			else if (userNav == 2) {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				cout << "\n" << "Choose number of attempts: " << endl;
				cout << "\n" << "1. Attempts: 1" << endl;
				cout << "\n" << "2. Attempts: 2" << endl;
				cout << "\n" << "3. Attempts: 3" << endl;
				cout << "\n" << "4. Attempts: 4" << endl;
				cout << "\n" << "5. Attempts: 5" << endl;
				cout << "\n" << "6. Attempts: 6" << "\n" << endl;

				userNav = CorrectInputUserNav(userNav, 0, 7);

				if (userNav == 1) {
					attemptCountReadjust = 1;
				}
				else if (userNav == 2) {
					attemptCountReadjust = 2;
				}
				else if (userNav == 3) {
					attemptCountReadjust = 3;
				}
				else if (userNav == 4) {
					attemptCountReadjust = 4;
				}
				else if (userNav == 5) {
					attemptCountReadjust = 5;
				}
				else if (userNav == 6) {
					attemptCountReadjust = 6;
				}

				cout << "\n" << endl;

				// Player is redirected back to main menu (the 'while(true)' loop takes place)
			}
		}

		// Start game with random-length words and either default count of attempts, or user-defined count of attempts;
		else if (userNav == 1) {

			short randomWord = rand() % (3*WORDS_IN_DICTIONARY);			// Generates a random number between 0 and (3*WORDS_IN_DICTIONARY - 1), (including those two);

			wordLen = StrlenAllWords(fullDict, randomWord);

			// Prints Guess a letter: _ _ _ _ (_ _)		"Attempts left: (count)	"

			cout << "\n" << "Guess a letter: ";
			for (int i = 0; i < wordLen; i++) {
				cout << "_ ";
			}
			cout << "	Attempts left: " << attemptsCount << "\n" << endl;

			short usedLettersCount = 0;		// Counter for used letters;
			bool flag = false;				// It is used when a repeating input letter is encountered; it tells the 'While' loop to skip the current iteration;

			while (attemptsCount > 0) {
				flag = false;
				inputLetter = CorrectInputLetter(inputLetter, 'a', 'z');

				for (int i = 0; i < usedLettersCount; i++) {

					if (inputLetter == usedLetters[i]) {
						cout << "\n" << "Try another letter, you have already used this one! " << "\n" << endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						flag = true;
					}
				}
				if (flag == true) continue;

				cout << "\n" << "Guess a letter: ";

				for (int i = 0; i < wordLen; i++) {
					if (inputLetter == fullDict[randomWord].anyWord[i]) {

						correctLetters[correctLettersCount] = inputLetter;
						correctLettersCount++;

						wrongLetter = false;
					}
				}


				for (int i = 0; i < wordLen; i++) {
					for (int j = 0; j < correctLettersCount; j++) {

						if (fullDict[randomWord].anyWord[i] == correctLetters[j]) {
							cout << correctLetters[j] << " ";
							printUnderscore = true;
						}
						else if ((j == correctLettersCount - 1) && printUnderscore == false) cout << "_ ";
					}

					if (correctLettersCount == 0) cout << "_ ";		// For the case in which the user hasn't guessed a single letter yet;

					printUnderscore = false;
				}


				if (wrongLetter == true) attemptsCount--;

				usedLetters[usedLettersCount] = inputLetter;
				usedLettersCount++;
				cout << "	Attempts left: " << attemptsCount << "\n" << endl;

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				wrongLetter = true;

				if (wordLen == correctLettersCount) {
					cout << "\n" << "Congratulations, you guessed the word '" << fullDict[randomWord].anyWord << "' !" << "\n" << "Returning to main menu..." << "\n \n" << endl;
					break;
				}
				else if (attemptsCount == 0) {
					cout << "\n" << "You lose! The word is: '" << fullDict[randomWord].anyWord << "'" << "\n" << "Returning to main menu..." << "\n \n" << endl;
				}
			}
		}
	}


	return 0;
}