#include <iostream>
#include <list>
#include <stack>
#include <algorithm> 
#include <vector>
#include <string>
#ifndef Graph_h_
#define Graph_h_

class Graph
{
    private: 
        int maxSize, curSize;
        std::vector<std::vector<int>> adj;
        std::vector<std::string> des;
        void buildEmpty(int s);
    public:
    Graph(){maxSize=0; buildEmpty(maxSize);}
    Graph(int num){maxSize=num; buildEmpty(maxSize);}
    bool isEmpty(){return (curSize == 0)?true:false;}
    int getIndex(std::string s);
    void addEdge(std::string v1, std::string v2, int w);
    int getMax(){return maxSize;}
    void addVertex(std::string v1);
    int check(std::string, std::string);
    void deleteVertex(std::string v1);
    void deleteEdge(std::string v1, std::string v2);

    void test();
};
#endif
