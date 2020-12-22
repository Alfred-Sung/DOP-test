# DOP-test
A simple experiment comparing data-oriented design to object-oriented design code

Program does ten tests that creates 1,000,000 objects and moves their position 20 times. 
Both g++ and MSVC was used to compile the code to show that DOP is effective regardless of compiler.


The data-oriented method differs by:
- Storing all and inherited variables into arrays
- Removing inheritence
- Separating functions from data
- Modifying functions to apply to arrays

### Benchmark Results
![Benchmark](/images/OOP%20vs%20DOP%20(MSVC).png)
![Benchmark](/images/OOP%20vs%20DOP%20(g++).png)

<sup><sup><sup> Tests were done on an AMD Ryzen 5 3600X 