#include <iostream>
#include <vector>

using std::cout;

void printBoard(std::vector<int> posX, std::vector<int> posY, int roundNumber,std::vector<bool> isXTurn) {

    for (int i = 0; i < 3; i++) {
        cout << "     |     |     " << std::endl;
        cout << "  ";
        for (int j = 0; j < 3; j++) {
            bool marked = false;

            for (int move = 0; move <= roundNumber; move++) {
                if (i == posX[move] && j == posY[move]) {
                    if (isXTurn[move]) {
                        cout << "X";
                        marked = true;
                        break;
                    }
                    else
                    {
                        cout << "O";
                        marked = true;
                        break;
                    }
                }
            }
            if (!marked) {
                cout << " ";
            }
            if (j < 2) {
                cout << "  |  ";
            }
        }
        cout << std::endl;
        if (i < 2)
            cout << "_____|_____|_____" << std::endl;
        else
            cout << "     |     |     " << std::endl;

    }
}

void game()
{
    bool isOver = false;
    static int round = 0;

    std::vector<int> posX, posY;
    std::vector<bool> isXTurn;

    posX.resize(10);
    posY.resize(10);
    isXTurn.resize(10);

    while (!isOver)
    {
      

        cout << "[1][2][3]" << std::endl <<
                "[4][5][6]" << std::endl <<
                "[7][8][9]" << std::endl;

        int userInput;
        if (isXTurn[round])
        {
            cout << "X Turn!\nInput the number where you wish to play!\n>";
            std::cin >> userInput;
            cout << std::endl;
        }
        else
        {
            cout << "O Turn!\nInput the number where you wish to play!\n>";
            std::cin >> userInput;
            cout << std::endl;

        }
        
        switch (userInput)
        {
        case 1:
           
            posX[round] = 0;
            posY[round] = 0;

            printBoard(posX, posY, round,isXTurn);
            round++;
            break;
        case 2:
           
            posX[round] = 0;
            posY[round] = 1;

            printBoard(posX, posY, round,isXTurn);
            round++;
            break;
        
        case 3:

            posX[round] = 0;
            posY[round] = 2;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        case 4:

            posX[round] = 1;
            posY[round] = 0;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        case 5:

            posX[round] = 1;
            posY[round] = 1;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        case 6:

            posX[round] = 1;
            posY[round] = 2;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        case 7:

            posX[round] = 2;
            posY[round] = 0;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        case 8:

            posX[round] = 2;
            posY[round] = 1;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        case 9:

            posX[round] = 2;
            posY[round] = 2;

            printBoard(posX, posY, round, isXTurn);
            round++;
            break;

        default:

            if (isXTurn[round])
            {
                cout << "Stop being a little cunt!" << std::endl;
                isXTurn[round] = false;
                break;

            }
            else
            {
                cout << "Stop being a little cunt!" << std::endl;
                isXTurn[round] = true;
                break;
            }

          

    }
        

    cout << "Changing turns...\n";
    if (isXTurn[round - 1])
    {
        isXTurn[round] = false;
    }
    else
    {
        isXTurn[round] = true;
    }


    }




}

int main() {


    game();

}