#include <iostream> 
#include <string> 
#include <cmath>
#include <cstdlib>

using namespace std;

enum GameChoice{Stone = 1, Paper = 2, Scissors = 3};
enum GameWinner{Player = 1, Computer = 2, Draw = 3};

struct RoundInfo {
    short RoundNumber = 0;
    GameChoice PlayerChoice;
    GameChoice ComputerChoice;
    GameWinner Winner ;
    string WinnerName = "";
};
struct GameResult {
    short RoundNumber = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    GameWinner Winner;
    string WinnerName ="";
};
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}
GameChoice GetComputerChoice() {
    int ComputerChoice = RandomNumber(1, 3);
    return GameChoice(ComputerChoice);
}
GameChoice ReadPlayerChoice() {
    short Choice = 0;
    do {
        cout << "Your Choice: [1]:Stone , [2]:Paper , [3]:Scissors \n\n";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return GameChoice(Choice);
}
int ReadHowManyRounds() {
    short Choice = 0;
    do {
        cout << "How many rounds 1 to 10: ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 10);
    return Choice;
}
string Tabs(short TabsNumber) {
    string Tab = "";
    for (int i = 0; i < TabsNumber; i++) {
        Tab += "\t";
    }
    return Tab;
}
string ChoiceName(GameChoice Choice) {
    string ArrChoiceName[3] = { "Stone" , "Paper" , "Scissors" };
    return ArrChoiceName[Choice - 1];
}
string WinnerName(GameWinner Winner) {
    string ArrWinnerName[3] = { "Player" , "Computer" , "No Winner (Draw)" };
    return ArrWinnerName[Winner - 1];
}
GameWinner HowWonTheGame(short PlayerWinTimes , short ComputerWinTimes) {
    if (PlayerWinTimes > ComputerWinTimes)
        return GameWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes)
        return GameWinner::Computer;
    else
        return GameWinner::Draw;
}
GameResult FillGameResult(short HowManyRounds , short PlayerWinTimes, short ComputerWinTimes, short DrawTimes) {
    GameResult Result;
    Result.RoundNumber = HowManyRounds;
    Result.PlayerWinTimes = PlayerWinTimes;
    Result.ComputerWinTimes = ComputerWinTimes;
    Result.DrawTimes = DrawTimes;
    Result.Winner = HowWonTheGame(PlayerWinTimes, ComputerWinTimes);
    Result.WinnerName = WinnerName(Result.Winner);
    return Result;
}
GameWinner HowWonTheRound(RoundInfo RoundInfo) {
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
        return GameWinner::Draw;
    switch (RoundInfo.ComputerChoice) {
    case GameChoice::Stone:
        if (RoundInfo.PlayerChoice == GameChoice::Scissors) {
            return GameWinner::Computer;
        }break;
    case GameChoice::Paper:
        if (RoundInfo.PlayerChoice == GameChoice::Stone) {
            return GameWinner::Computer;
        }break;
    case GameChoice::Scissors:
        if (RoundInfo.PlayerChoice == GameChoice::Paper) {
            return GameWinner::Computer;
        }break;
    }
    return GameWinner::Player;
}
void ColorScreen(RoundInfo RoundInfo) {
    if (RoundInfo.Winner == GameWinner::Player)
        system("color 2F");
    else if (RoundInfo.Winner == GameWinner::Computer) {
        system("color 4F");
        cout << "\a";
    }  
    else
        system("color 6F");
}
void PrintRoundResults(RoundInfo RoundInfo)
{
    cout << "\n\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}
GameResult PlayGame(short HowManyRounds) {
    RoundInfo CurrentRound;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (short GameRound = 1; GameRound <= HowManyRounds;GameRound++) {
        cout << "Round [" << GameRound << "] begins:\n\n";
        CurrentRound.RoundNumber = GameRound;
        CurrentRound.PlayerChoice = ReadPlayerChoice();
        CurrentRound.ComputerChoice = GetComputerChoice();
        CurrentRound.Winner = HowWonTheRound(CurrentRound);
        CurrentRound.WinnerName = WinnerName(CurrentRound.Winner);

        if (CurrentRound.Winner == GameWinner::Player)
            Player1WinTimes++;
        else if (CurrentRound.Winner == GameWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        ColorScreen(CurrentRound);
        PrintRoundResults(CurrentRound);
    }
    return FillGameResult(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}
void ResetScreen() {
    system("cls");
    system("color 0F");
}
void ShowGameOverScreen() {
    cout << Tabs(2) << "________________________________________________________\n";
    cout << Tabs(4) << "+++ Game Over +++\n";
    cout << Tabs(2) << "________________________________________________________\n";
}
void  showGameResult(GameResult FinalResult) {
    cout << Tabs(2) << "_____________________[Game Result]______________________\n";
    cout << Tabs(2) << "Game Rounds       : " << FinalResult.RoundNumber << endl;
    cout << Tabs(2) << "Player Won Times  : " << FinalResult.PlayerWinTimes << endl;
    cout << Tabs(2) << "Computer Won Times: " << FinalResult.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times        : " << FinalResult.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner      : " << FinalResult.WinnerName << endl;
    cout << Tabs(2) << "________________________________________________________\n";
}
void StartGame() {
    char Choice = 'Y';
    do {
        ResetScreen();
        GameResult FinalResult = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        showGameResult(FinalResult);
        cout << "Do you want to play again? [Y]es / [N]o: ";
        cin >> Choice;
    } while (Choice == 'Y' || Choice == 'y');
}
int main()
{
    srand((unsigned)time(NULL)); 
    StartGame();
    return 0;  
}