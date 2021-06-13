#ifndef UNTITLED1_CONWAY_HPP
#define UNTITLED1_CONWAY_HPP


class Conway
{
public:
    /**
     * Constructor for Conway
     * Creates everything for the Game
     * @param size
     */
    Conway(int size);

    /**
     * This Methods Updates the game by the Rules
     * so 1Generations update
     */
    void upate();

    /**
     * This Method returns if the specified cell is alive or not
     */
    bool is_alive(int x, int y) const;

    /**
     * This method changes the state of a specific cell
     *
     *
     *
     * @param x x position in the gamefield (not screen x)
     * @param y y position in the gamefiled (not screen y)
     */
    void changeState(int x, int y) const;

    /**
     * This method sets kills every cell
     * (every value in gamefield will be false after this)
     */
    void clearField();

private:
    ///Always square
    int size;
    ///Gamefield
    bool **tmpField;

    ///GetTopLeft
    bool getTopLeft(int x, int y) const;

    ///GetTopRight
    bool getTopRight(int x, int y) const;

    ///GetBottomLeft
    bool getBottomLeft(int x, int y) const;

    ///GetBottomRight
    bool getBottomRight(int x, int y) const;

    ///GetTop
    bool getTop(int x, int y) const;

    ///GetBottom
    bool getBottom(int x, int y) const;

    ///GetLeft
    bool getLeft(int x, int y) const;

    ///GetRight
    bool getRight(int x, int y) const;

    ///Counts the Neighbours
    int countNeighbours(int x, int y) const;

    ///GameField
    bool **gamefield;

public:
    virtual ~Conway();
};


#endif //UNTITLED1_CONWAY_HPP
