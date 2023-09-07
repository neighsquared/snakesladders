#include <iostream>
#include <fstream>

using namespace std;

int rollDice() {
    int input;
    std::cout << "Enter a number from 1 to 1000: ";
    std::cin >> input;

    int diceRoll = 1 + (((input + 1) / 2 * 10 + 41) % 6);

    std::cout << "You rolled a " << diceRoll << "!\n";
    return diceRoll;
}

// gotta make this somehow cycle through 4 players, maybe use an index????
int main() {
    std::ifstream file("board.txt");
    int p1Position = 0, p2Position = 0, p3Position = 0, p4Position = 0, cPlayer = 1, cPosition = 0;
    bool game = true; //ngl idk how to start the game so yeah im just using this for now
    int playerCount; 
    cout << "Enter the number of players (2-4): ";
    cin >> playerCount;
    if (playerCount < 2 || playerCount > 4) {
        cout << "Invalid number of players. Please enter a number between 2 and 4." << endl;
        exit(1);
    }
    while (game = true) {
        std::cout << "-----\nPlayer 1's turn!\nCurrent cell position:  " << p1Position << endl;

        int diceRoll = rollDice();
        if(cPlayer = 1){
            cPosition = p1Position;
            //cPlayer += 1;
        }
        else if(cPlayer = 2) {
            cPosition = p2Position;
            //if (playerCount == 2){
                //cPlayer -= 1;
            //}
            //else{
                //cPlayer += 1;
            //}
        }
        else if(cPlayer = 3) {
            cPosition = p3Position;
            //if (playerCount == 3){
                //cPlayer -= 2;
            //}
            //else{
                //cPlayer += 1;
            //}
        }
        else {
            cPosition = p4Position;
            //cPlayer -= 3;
        }
        int newPosition = cPosition + diceRoll;

        if (newPosition > 99) {
            cout << "Player 1 wins!" << endl;
        }

        // insert something about getting the cell value from the txt file
        int cellValue = 0;

        if (cellValue = 0) {
            std::cout << "Player 1 landed on cell " << newPosition << ", which is a normal cell.\n-----";
        }

        else if (cellValue > 0 || cellValue < 0) {
            cPosition = newPosition + cellValue;

            if (cellValue > 0) {
                std::cout << "Player 1 landed on cell " << newPosition << ". However, it was a ladder cell! Moving forward to cell " << cPosition << "\n-----";
            }
            else if (cellValue < 0) {
                std::cout << "Player 1 landed on cell " << newPosition << ". However, it was a snake cell! Moving back to cell " << cPosition << "\n-----";
                if (cPosition < 0) {
                    cPosition = 0;
                }
            }
        }
        game = !game;
        return 0;
    }
}