/******************************************************************************
Kenneth Ly
Kll200003
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <list>
#include "Graph.cpp"
#include<fstream>
#include<sstream>
#include <utility>
#include <stack>
using namespace std;



class Driver
{
    private: 
        std::string name;
        int path;
    public:
    Driver(){name=""; path = 0;}
    Driver(std::string n){name=n; path = 0;}
    void addPath(int p);
    int getPath(){return path;}
    void setName(std::string n){name = n;}
    std::string getName(){return name;}
    friend std::ostream& operator<<(std::ostream& out, const Driver& d);
}; 

std::ostream& operator<< (std::ostream& out, const Driver& d)
{

    out << d.name << '\t' << d.path;
    if(d.path == 0)
        out << "\tinvalid";
    else
        out << "\tvalid";
  return out;
}

void Driver::addPath(int p)
{
    if(p==-1)
        path = 0;
    else
        path += p;
}

void initEdges(ifstream& input, Graph& g)
{
    string line;
    string name;
    while(getline(input,line))
    {
        istringstream iss(line);
        string vertex;
        iss>>name;
        
        while(iss >> vertex)
        {
            int index = vertex.find(",");
            string des = vertex.substr(0, index);
            int weight = stoi(vertex.substr(index + 1));
            g.addEdge(name,des,weight);
        }
    }
}

void initVertex(ifstream& input, Graph& g)
{
    string line;
    string name;
    while(getline(input,line))
    {
        int index = line.find(" ");
        name = line.substr(0,index);
        g.addVertex(name);
    }
}

bool compare(Driver d1, Driver d2)
{
    if (d1.getPath() < d2.getPath())
        return true;
    else if (d1.getPath() == d2.getPath())
        return (d1.getName() < d2.getName());
    else
        return false;
}

void readRoutes(ifstream& input, Graph& g)
{
    string line;
    vector<Driver> drivers;
    while(getline(input,line))
    {
        if(line.length() == 0)
              continue;
        istringstream iss(line);
        string name;
        string path1;
        string path2;
        int weight;
        iss>>name;
        if(name=="")
            continue;
        Driver d(name);
        //cout << name << endl;
        iss>>path1;
        while(iss>>path2)
        {
            weight = g.check(path1,path2);
            if(weight == -1)
            {
                d.addPath(weight);
                break;
            }
            else
                d.addPath(weight);
                //cout << path1 << endl;
                //cout << path2 << endl;
            path1=path2;
        }
        drivers.push_back(d); 
    } 
    sort(drivers.begin(), drivers.end(), compare);
    for(int i = 0; i < drivers.size(); i++)
    {
        cout << drivers.at(i) << endl;
    }
}

int main()
{
    string gFile;
    string rFile;
    string line; 
    int count;
    cout << "Enter Graph File Name" << endl;
    cin >> gFile;
    cout << "Enter Routes File Name" << endl;
    cin >> rFile;
    cout << endl;
    //gFile = "samplegraph.txt";
    //rFile = "sample_routes_p5.txt";
    ifstream input (gFile);
    if(input.is_open())
    {
        while(getline(input,line))
        {
            count ++;
        }
    }
        Graph g(count);
        input.close(); 
        
        input.open(gFile);
        initVertex(input, g);
        input.close();

        input.open(gFile);
        initEdges(input, g);
        input.close();
    input.open(rFile);
    if(input.is_open())
    {
        readRoutes(input,g);
        input.close();
    }
    cout << endl;
    //g.test();
    //cout << "Finished" <<endl; 
    return 0;
}
