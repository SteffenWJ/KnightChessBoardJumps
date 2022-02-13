#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <chrono>

/*
I am using three different nested classes under the driver class.

The node that knows its position and how many jumps it took and knows its child nodes memory locations.
A Tree class takes the nodes and gives us a start node, the so-called root.
The chessboard class is used to know what locations have gotten visited already.
*/
class Driver
{
public:
    Driver();

    class node
    {
    public:

        node();
        //It takes it's current cordinates and what jump it is part of.
        node(int xCordinates,int yCordinates, int jumps);


        std::queue<node> getNodeChildren() const;

        //Getters for the Node
        int getXNode() const;
        int getYNode() const;
        int getJumps() const;

        int xNode;
        int yNode;
        int mJumps;

        //Adds a new node for
        void addChild(node &node);

        //Creats a queue that keeps the child nodes in it.
        std::queue<node> nodeChildren;
    };

    class tree
    {
    public:
        tree();
        tree(node *myRootNode);

        node *getRoot() const;

    private:
        node *root;

    };

    class chessBoard
    {
    public:
        chessBoard();
        chessBoard(int height, int width, int xGoal, int yGoal);

        void setValueOnBoard(int xPosition,int yPosition, int value);


        std::vector<std::vector<int>> mChessBoard;

    private:
        int mBoardHeight;
        int mBoardWidth;
        int xBoardGoal;
        int yBoardGoal;

    };

    //This is the main program for counting steps, takes the board size. The start position and where it is supposed to end op.
    int static MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition,int KnightStartYPosition, int KnightEndXPosition, int KnightEndYPosition);

};

#endif // DRIVER_H
