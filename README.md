# Route-Tracker

This program can take in a file that contains a series of locations and their routes to other destinations and implements 
this data into a weighted graph represented by an adjacency matrix. This program can then take in another file that contains
a list of drivers and their routes along with these locations. The program can use this graph to determine if the driver's route is
valid and the total distance the driver will travel and print this information to the console. 

The program will prompt the user for a graph file that will contain all the destinations and the routes connecting them. The file
begins with the name of the location then followed by terms for each connecting location separated by a space. Each term 
contains the name of the connecting location a comma then a number representing the distance of that location. Each location will be separated by a new 
line and can consist of alphanumeric characters with no spaces allowed. 
Ex:

[NAME] [DESTINATION 1],[DISTANCE 1] [DESTINATION 2],[DISTANCE 2] [DESTINATION n],[DISTANCE n]

The program will also prompt the user for a routes file containing the drivers and their designated routes to check if they are valid in accordance with the graph.
This file begins with the name of the driver which can consist of alphanumeric characters with no spaces. Then the name of each destination they will be traveling
to in order separated by a space. Each driver is separated by a new line.
Ex:

[NAME] [DESTINATION 1] [DESTINATION 2] [DESTINATION 3] [DESTINATION n] 



*samplegraph.txt and sample_routes_p5.txt are test files that can be used to test this program and this program supports the implementation of a complex graph, meaning that locations can have multiple paths to the same destination and also have paths leading to themselves. 

