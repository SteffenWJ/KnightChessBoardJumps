#include "driver.h"

Driver::Driver()
{

}

int Driver::MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition, int KnightStartYPosition, int KnightEndXPosition, int KnightEndYPosition)
{

    std::cout << "Getting ready to start" << std::endl;

    chessBoard myChessBoard(BoardHeight,BoardWidth,KnightEndXPosition,KnightEndYPosition);

    node rootNode(KnightStartXPosition,KnightStartYPosition,0);

    node * rootPtr;

    rootPtr = &rootNode;

    tree myTree(rootPtr);

    //These are all the possible jumps a night can do.
    int travelX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int travelY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    std::queue<node> nextInLine;

    nextInLine.push(rootNode);

    double distanceOrg;
    double distanceTest;

    int counter = 0;

    std::cout << "Starting the Jumping!!" << std::endl;

    while (!nextInLine.empty()) {
        node newNode = nextInLine.front();
        nextInLine.pop();

        //This was a debug code to see if it was still running
        //if (counter% BoardWidth*BoardHeight == 0) {
        //    std::cout << "Still running we are at " << counter << std::endl;
        //}

        //If the new node created is in the end position it will return how many jumps where done
        if (newNode.xNode == KnightEndXPosition && newNode.yNode == KnightEndYPosition) {
            return newNode.getJumps();
        }

        for (int i = 0; i < 8; ++i) {
            if (newNode.xNode+travelX[i] >= 0 && newNode.xNode+travelX[i] < BoardWidth && newNode.yNode+travelY[i] >= 0 && newNode.yNode+travelY[i] < BoardHeight
                    &&  myChessBoard.mChessBoard[newNode.xNode+travelX[i]][newNode.yNode+travelY[i]] == 0) {
                //Checks if the jump is closer to the end compared to it's origin position.
                distanceOrg = std::sqrt(std::pow(newNode.xNode-KnightEndXPosition,2) + std::pow(newNode.yNode-KnightEndYPosition,2));
                distanceTest = std::sqrt(std::pow((newNode.xNode+travelX[i])-KnightEndXPosition,2) + std::pow((newNode.yNode+travelY[i])-KnightEndYPosition,2));
                //If yes a new node is created or else the next position next position is tested
                if (distanceOrg > distanceTest ) {
                    node puttingIn(newNode.xNode+travelX[i],newNode.yNode+travelY[i],newNode.getJumps()+1);
                    nextInLine.push(puttingIn);
                    newNode.addChild(puttingIn);
                    myChessBoard.mChessBoard[newNode.xNode+travelX[i]][newNode.yNode+travelY[i]] = 1;
                }
            }
        }
        counter ++;
    }

    return -999; //Old dumb error way that i like to use for rnadom test code.
}

Driver::node::node()
{
    std::cout << "This is a Default node should not be used" << std::endl;
}

Driver::node::node(int xCordinates, int yCordinates, int jumps)
{
    xNode = xCordinates;
    yNode = yCordinates;
    mJumps = jumps;
}

std::queue<Driver::node> Driver::node::getNodeChildren() const
{
    return nodeChildren;
}

int Driver::node::getXNode() const
{
    return xNode;
}

int Driver::node::getYNode() const
{
    return yNode;
}

int Driver::node::getJumps() const
{
    return mJumps;
}

void Driver::node::addChild(Driver::node &node)
{
    nodeChildren.push(node);
}

Driver::tree::tree()
{
    std::cout << "This is a Default Tree should not be used" << std::endl;
}

Driver::tree::tree(Driver::node *myRootNode)
{
    root = myRootNode;
}

Driver::node *Driver::tree::getRoot() const
{
    return root;
}

Driver::chessBoard::chessBoard(int height, int width, int xGoal, int yGoal)
{
    for (int i = 0; i < height; ++i) {
        std::vector<int> temp;
        for (int j = 0; j < width; ++j) {
            temp.push_back(0);
        }mChessBoard.push_back(temp);
    }
    mBoardHeight = height;
    mBoardWidth = width;
    xBoardGoal = xGoal;
    yBoardGoal = yGoal;
}

void Driver::chessBoard::setValueOnBoard(int xPosition, int yPosition, int value)
{
    mChessBoard[xPosition][yPosition] = value;
}
