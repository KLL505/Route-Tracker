#include "Graph.h"


void Graph::addEdge(std::string v1, std::string v2, int w)
{
    int x = getIndex(v1);
    int y = getIndex(v2);
    if(adj.at(x).at(y) != -1 && adj.at(x).at(y) < w)
        return;
    else
        adj.at(x).at(y) = w;
}

void Graph::deleteEdge(std::string v1, std::string v2)
{
    int x = getIndex(v1);
    int y = getIndex(v2);
    adj.at(x).at(y) = -1;
}

void Graph::addVertex(std::string v1)
{
    des.push_back(v1);
}

void Graph::deleteVertex(std::string v1)
{
    int x = getIndex(v1);
    for(int i = 0; i < maxSize; i++)
    {
        adj.at(x).at(i) = -1;
        adj.at(i).at(x) = -1;
    }
    des.erase(des.begin()+x);
}

int Graph::getIndex(std::string s)
{
    auto it = std::find(des.begin(), des.end(), s);
    if (it != des.end())
    {
        int index = it - des.begin();
        return index;
    }
    else {
        return -1;
    }
}

void Graph::test()
{
    for(int i = 0; i < maxSize; i++)
    {
        for(int j = 0; j<maxSize; j++)
        {
            std::cout << adj.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

int Graph::check(std::string v1, std::string v2)
{
    int x = getIndex(v1);
    int y = getIndex(v2);
    if(x == -1 || y==-1)
        return -1;
    else
        return adj.at(x).at(y);
}


void Graph::buildEmpty(int s)
{
   adj.resize(s);
    for(int i = 0; i<s; i++)
    {
        adj.at(i).resize(s);
    }
    for(int i = 0; i < maxSize; i++)
    {
        for(int j = 0; j<maxSize; j++)
        {
            adj.at(i).at(j) = -1;
        }
    }

}




