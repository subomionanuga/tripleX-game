#include <iostream>

void PrintIntroduction(int Difficulty)
{
  std::cout << "You are a secret agent breaking into a level " << Difficulty;
  std::cout << " secure server room\nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  const int CodeA = 4;
  const int CodeB = 5;
  const int CodeC = 3;

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
    std::cout << "\nCongratulations, Secret Agent\n";
    return true;
  }
  else
  {
    std::cout << "\nShame, Agent. You failed...miserably\n";
    return false;
  }
}

int main()
{
  int LevelDifficulty = 1;
  while (true)
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();  //clears any errors
    std::cin.ignore(); //Discatds the buffer

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
  }

  return 0;
}