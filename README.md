# HyperSphere Intersection
 A program for detecting the relation between two N-dimensional hyperspheres in C++

## Detected cases:
1. No intersection
2. Tangent externally
3. Tangent internally
4. Regular intersection
5. One inside the other (without tangent)
6. Coincidence

## Return
The program returns the type of the intersection and the points of the intersection as another HyperSphere.

## Handling
The dimension N is given as a prepocessor macro, this can be changed if we want to check for a given dimension.

The function to be called is placed in the _main.cpp_ file named **checkIntersection**. It takes the two hyperspheres as input and gives back an Intersection object containing the data.

The **main** function contains an example code for creating two hyperspheres and calling the checkIntersection function then printing the results.