#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <conio.h>
#include "Core/base/print.h"

bool gameOver;
const int width = 18;
const int height = 12;
int x, y, fruitX[2], fruitY[2], score, eatenFruitsScore, tailCount;
int tailX[12], tailY[12];
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void snakeGameSetup() {
    gameOver = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    tailCount = 0;
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            fruitX[i] = rand() % width;
            fruitY[i] = rand() % height;
            continue;           
        }
        fruitX[i] = 35;
        fruitY[i] = 35;
    }
    score = 0;
    eatenFruitsScore = 0;
}

void snakeGameDraw() {
    system("cls");
    for (int i = 0; i < width + 1; i++)
        std::cout << "#";
    std::cout << '\n';
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                std::cout << "#";
            }
            if (i == y && j == x) {
                core::print("0", core::aqua);
            }
            else {
                bool print = false;
                for (int a = 0; a < 2; a++) {
                    if (i == fruitY[a] && j == fruitX[a]) {
                        print = true;
                        core::print("F", core::green);
                    }
                }
                for (int k = 0; k < tailCount; k++) {
                    if (tailX[k] == j && tailY[k] == i && tailCount > 0) {
                        print = true;
                        core::print("o", core::light_aqua);
                    }
                }
                if (!print)
                    std::cout << " ";
            }
        }
        std::cout << '\n';
    }

    for (int i = 0; i < width + 1; i++)
        std::cout << "#";
    std::cout << '\n' << "Score: " << score << '\n' <<
        "Eaten fruits: " << eatenFruitsScore << '\n';
}

void snakeGameInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                dir = STOP;
                gameOver = true;
                break;
        }
    }
}

void snakeGameLogic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < tailCount; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y; 
    }
    switch (dir) {
        case LEFT:
            x--;
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            snakeGameDraw();
            break;
        case RIGHT:
            x++;
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            snakeGameDraw();
            break;
        case UP:
            y--;
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            snakeGameDraw();
            break;
        case DOWN:
            y++;
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            snakeGameDraw();
            break;
        case STOP:
            break;
    }

    if (x >= (width - 1) || x < 0 || y >= height || y < 0)
        gameOver = true;
    for (int i = 0; i < 2; i++) {
        if (x == fruitX[i] && y == fruitY[i]) {
            score += 10;
            eatenFruitsScore += 1;
            if (tailCount <= 12) tailCount++;
            if (eatenFruitsScore >= 4 && fruitX[1] >= 35) {
                for (int a = 0; a < 2; a++) {
                    fruitX[a] = rand() % (width - 2);
                    fruitY[a] = rand() % height;
                }
            }
            fruitX[i] = rand() % (width - 2);
            fruitY[i] = rand() % height;
        }
    }
}

void snakeGameUpdate() {
    snakeGameInput();
    snakeGameLogic(); 
}

void snakeGameStart() {
    snakeGameSetup();
    snakeGameDraw();
    while (!gameOver) {
        snakeGameUpdate();
    }
}