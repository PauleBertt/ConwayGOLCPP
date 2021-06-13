#include "Conway.hpp"

Conway::~Conway()
{
    //Frees the GameField Memory
    for (int i = 0; i < size; i++) {
        //Every Row
        delete (gamefield[i]);
    }
    //Index
    delete gamefield;
}

Conway::Conway(int i_size)
{
    size = i_size;
    //Creates an empty bool array
    //Index
    gamefield = new bool *[size];
    //Create Puffer GameField
    tmpField = new bool *[size];
    for (int i = 0; i < size; i++) {
        //Row
        gamefield[i] = new bool[size];
        tmpField[i] = new bool[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            gamefield[i][j] = false;
        }
    }
    //Some Data
    int offset = 50;
    /* blinker
    gamefield[0+offset][1+offset] = true;
    gamefield[1+offset][1+offset] = true;
    gamefield[2+offset][1+offset] = true;
     */

    ///r-Pentomino
    gamefield[0 + offset][1 + offset] = true;
    gamefield[0 + offset][2 + offset] = true;
    gamefield[1 + offset][0 + offset] = true;
    gamefield[1 + offset][1 + offset] = true;
    gamefield[2 + offset][1 + offset] = true;



    /*
    ///Komplett ausraster
    gamefield[0+offset][0+offset] = true;
    gamefield[0+offset][1+offset] = true;
    gamefield[0+offset][2+offset] = true;
    gamefield[1+offset][0+offset] = true;
    gamefield[1+offset][2+offset] = true;
    gamefield[2+offset][0+offset] = true;
    gamefield[2+offset][2+offset] = true;
    gamefield[4+offset][0+offset] = true;
    gamefield[4+offset][2+offset] = true;
    gamefield[5+offset][0+offset] = true;
    gamefield[5+offset][2+offset] = true;
    gamefield[6+offset][0+offset] = true;
    gamefield[6+offset][1+offset] = true;
    gamefield[6+offset][2+offset] = true;

     */


}

void Conway::upate()
{
    //Updates the Gamefield
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbours = countNeighbours(j, i);
            if (is_alive(j, i)) {
                //over population / under population
                bool value = !(neighbours > 3 || neighbours < 2);
                tmpField[i][j] = value;
            } else if (neighbours == 3) {
                //Perfet new live
                tmpField[i][j] = true;
            } else {
                tmpField[i][j] = false;
            }
        }
    }
    //Switch Fields
    bool **puffer = gamefield;
    gamefield = tmpField;
    tmpField = puffer;
}

bool Conway::getTop(int x, int y) const
{
    //If Already on top return bottom
    if (y == 0) {
        return gamefield[size - 1][x];

    }
    return gamefield[y - 1][x];
}

bool Conway::getBottom(int x, int y) const
{
    //If Already on bottom return top
    if (y == size - 1) {
        return gamefield[0][x];
    }
    return gamefield[y + 1][x];
}

bool Conway::getLeft(int x, int y) const
{
    //If Already on left edge return right edge
    if (x == 0) {
        return gamefield[y][size - 1];
    }
    return gamefield[y][x - 1];
}

bool Conway::getRight(int x, int y) const
{
    //If Already on the right edge return left edge
    if (x == size - 1) {
        return gamefield[y][0];
    }
    return gamefield[y][x + 1];
}

bool Conway::is_alive(int x, int y) const
{
    return gamefield[y][x];
}

int Conway::countNeighbours(int x, int y) const
{
    int neighbours = 0;
    if (getTop(x, y)) {
        neighbours++;
    }
    if (getLeft(x, y)) {
        neighbours++;
    }
    if (getRight(x, y)) {
        neighbours++;
    }
    if (getBottom(x, y)) {
        neighbours++;
    }
    if (getBottomLeft(x, y)) {
        neighbours++;
    }
    if (getBottomRight(x, y)) {
        neighbours++;
    }
    if (getTopLeft(x, y)) {
        neighbours++;
    }
    if (getTopRight(x, y)) {
        neighbours++;
    }
    return neighbours;
}

bool Conway::getTopLeft(int x, int y) const
{
    int pos_x = x;
    int pos_y = y;

    if (pos_x == 0) {
        pos_x = size - 1;
    } else {
        pos_x = pos_x - 1;
    }
    if (pos_y == 0) {
        pos_y = size - 1;
    } else {
        pos_y = pos_y - 1;
    }
    return gamefield[pos_y][pos_x];
}

bool Conway::getTopRight(int x, int y) const
{
    int pos_x = x;
    int pos_y = y;
    if (pos_x == size - 1) {
        pos_x = 0;
    } else {
        pos_x = pos_x + 1;
    }
    if (pos_y == 0) {
        pos_y = size - 1;
    } else {
        pos_y = pos_y - 1;
    }
    return gamefield[pos_y][pos_x];
}

bool Conway::getBottomLeft(int x, int y) const
{
    int pos_x = x;
    int pos_y = y;
    if (pos_x == 0) {
        pos_x = size - 1;
    } else {
        pos_x = pos_x - 1;
    }
    if (pos_y == size - 1) {
        pos_y = 0;
    } else {
        pos_y = pos_y + 1;
    }
    return gamefield[pos_y][pos_x];
}

bool Conway::getBottomRight(int x, int y) const
{
    int pos_x = x;
    int pos_y = y;
    if (pos_x == size - 1) {
        pos_x = 0;
    } else {
        pos_x = pos_x + 1;
    }
    if (pos_y == size - 1) {
        pos_y = 0;
    } else {
        pos_y = pos_y + 1;
    }
    return gamefield[pos_y][pos_x];
}

void Conway::changeState(int x, int y) const
{
    gamefield[y][x] = !gamefield[y][x];
}

void Conway::clearField()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            gamefield[i][j] = false;
        }
    }
}


