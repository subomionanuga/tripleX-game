#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
  std::cout << "\nYou are a secret agent breaking into a level " << Difficulty;
  std::cout << " secure server room\nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  std::cout << std::endl;
  std::cout << "There are 3 numbers in the code\n";
  std::cout << "The sum of the codes gives: " << CodeSum;
  std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

  int GuessA, GuessB, GuessC;

  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  if (GuessProduct == CodeProduct && GuessSum == CodeSum)
  {
    std::cout << "\nWell done, Agent. Move on to the next phase.\n";
    return true;
  }
  else
  {
    std::cout << "\nShame, Agent. You failed...miserably. The answer was\n";
    std::cout << CodeA << CodeB << CodeC << std::endl;
    std::cout << "Try again or end your career here.\n";
    return false;
  }
}

int main()
{
  srand(time(NULL));
  int LevelDifficulty = 1;
  const int MaxDifficulty = 5;
  while (LevelDifficulty <= MaxDifficulty)
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();  //clears any errors
    std::cin.ignore(); //Discards the buffer

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
  }

  std::cout << "\nCongratulations, Agent. Mission accomplished\n";
  return 0;
}