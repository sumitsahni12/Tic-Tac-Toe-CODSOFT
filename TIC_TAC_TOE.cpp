#include <iostream>
#include <vector>

// Function prototypes
void printBoard(const std::vector<std::vector<char>> &board);
bool isMoveValid(const std::vector<std::vector<char>> &board, int row, int col);
bool checkWin(const std::vector<std::vector<char>> &board, char player);
bool checkDraw(const std::vector<std::vector<char>> &board);
bool playAgain();

int main()
{
    char currentPlayer = 'X'; // Player 'X' starts the game

    std::cout << "\n=== Welcome to Tic-Tac-Toe! ===\n"
              << std::endl;

    do
    {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' ')); // Initialize 3x3 game board
        bool gameActive = true;

        // Main game loop
        while (gameActive)
        {
            // Display the board
            printBoard(board);

            int row, col;

            // Player input
            std::cout << "Player " << currentPlayer << ", enter the row (1-3) and column (1-3) numbers of your move: ";
            std::cin >> row >> col;

            // Validate the move
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3)
            {
                if (isMoveValid(board, row - 1, col - 1))
                {
                    board[row - 1][col - 1] = currentPlayer;

                    // Check for win
                    if (checkWin(board, currentPlayer))
                    {
                        printBoard(board);
                        std::cout << "\nPlayer " << currentPlayer << " wins! Congratulations!\n"
                                  << std::endl;
                        gameActive = false;
                    }
                    else
                    {
                        // Check for draw
                        if (checkDraw(board))
                        {
                            printBoard(board);
                            std::cout << "\nIt's a draw!\n"
                                      << std::endl;
                            gameActive = false;
                        }
                        else
                        {
                            // Switch player
                            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        }
                    }
                }
                else
                {
                    std::cout << "\nInvalid move! Please try again.\n"
                              << std::endl;
                }
            }
            else
            {
                std::cout << "\nInvalid input! Row and column values must be between 1 and 3.\n"
                          << std::endl;
            }
        }

    } while (playAgain());

    std::cout << "Thank you for playing Tic-Tac-Toe!\n"
              << std::endl;

    return 0;
}

// Function to print the current state of the board
void printBoard(const std::vector<std::vector<char>> &board)
{
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << " " << board[i][j];
            if (j < 2)
                std::cout << " |";
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "---+---+---" << std::endl;
    }
    std::cout << std::endl;
}

// Function to check if the move is valid
bool isMoveValid(const std::vector<std::vector<char>> &board, int row, int col)
{
    return (board[row][col] == ' ');
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>> &board, char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>> &board)
{
    // Check if there are any empty spaces left
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
                return false; // Found an empty space, game is not a draw
        }
    }
    return true; // No empty spaces left, game is a draw
}

// Function to ask if the players want to play again
bool playAgain()
{
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
