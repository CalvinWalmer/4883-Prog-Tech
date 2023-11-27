import matplotlib.pyplot as plt
from scipy.spatial import Delaunay
import numpy as np

class Nation:
    def __init__(self):
        self.states = []
    
    # Methods

    def AddState(self, state):
        self.states.append(state)

    def InNation(self, state):
        return state in self.states
    
    def AtBack(self):
        return self.states[len(self.states) - 1]
    
    def PrintStates(self):
        c = 1
        for state in self.states:
            print("STATE {}".format(c))
            state.PrintCities()
            print("----------------------------")
            c = c + 1

    def DisplayNation(self):
        points = []
        print(len(self.states))
        for state in self.states:
            points = points + state.GetCities()
        
        print(points)

        points = np.array(points)
        plt.plot(points[:,0], points[:,1], 'o')
        plt.show()


    def GetStates(self):
        return self.states




class State:
    # default constructor
    def __init__(self, threshold):
        self.threshold = threshold
        self.thresholdsq = threshold**2
        self.cities = [] # should contain tuples of x and y
        self.citiesX = []
        self.citiesY = []

    # Methods

    def AddCity(self, x, y):
        self.cities.append([x,y])
        self.citiesX.append(x)
        self.citiesY.append(y)

    def InState(self, x, y):
        for city in self.cities:
            dx = city[0] - x
            dy = city[1] - y

            if dx**2 + dy**2 <= self.thresholdsq:
                return True
        
        return False
    
    def PrintCities(self):
        for city in self.cities:
            print("{} {}".format(city[0], city[1]))
    
    def GetCitiesX(self):
        return self.citiesX
    
    def GetCitiesY(self):
        return self.citiesY
    
    def GetCities(self):
        return self.cities

numCases = input()

c = 1
for _ in range(int(numCases)):
    nation = Nation()
    temp = input().split(" ")
    numLines = int(temp[0])
    threshold = int(temp[1])

    nation.AddState(State(threshold))

    # States.back (freshly appended)

    temp = input().split(" ")

    nation.AtBack().AddCity(int(temp[0]), int(temp[1]))

    for _ in range(numLines - 1):
        added = False
        temp = input().split(" ")
        x = int(temp[0])
        y = int(temp[1])

        for state in nation.GetStates():
            if state.InState(x, y):
                state.AddCity(x, y)
                added = True
        
        if not added:
            nation.AddState(State(threshold))
            nation.AtBack().AddCity(x, y)

    nation.DisplayNation()
    # print()
    # print("###################################")
    # print("NATION {}".format(c))
    # print("###################################")
    # nation.PrintStates()
    c = c + 1

    for state in nation.GetStates():
        points = np.array(state.GetCities())
        if len(points) > 3:
            dt = Delaunay(points, qhull_options="QJ")
            cvh = dt.convex_hull
            tri = dt.simplices

            print("CONVEX HULL")
            print(cvh)
            print("TRIANGULATION")
            print(tri)
            print("---------------------------")
            plt.triplot(points[:,0], points[:,1], tri)
            plt.plot(points[:,0], points[:,1], 'o')
            plt.show()





