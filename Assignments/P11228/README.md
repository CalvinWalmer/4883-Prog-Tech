This problem asks for the minimum amount of railroads and roads needed to connect all cities to each other. There is a constraint tat says that if cities are in a certain distance
of each other that they must be connected by roads. If they are too far apart then they must be connected by railroads instead.

I thought this problem would be an interesting one to tackle because for me it seems like its in that sweet spot where I dont really know how to go about solving it but I have a lot
of ideas baout how I MIGHT solve it. During researching this problem I found out alot about Convex Hull algorithms by researching Delauney triangulation.

Delauney triangulation provides a nice mesh between points instead of a spider web where every point is connected to every other point. The original investigation into Delauney Triangulation
was in an effort to save computation time down the line. 
This:

![image](https://github.com/CalvinWalmer/4883-Prog-Tech/assets/112140788/ea8f9266-f1ed-4e38-85fc-3c5ab48ecefe)


Instead of this:

![image](https://github.com/CalvinWalmer/4883-Prog-Tech/assets/112140788/f8925288-74db-4792-833c-7ae2262a084a)

Convienently, when obtaining the DT, a convex hull is generated as well! The importance of this is that at this moment it seems ome that the "solutions" to this problem
will consist of the outermost cities of one state being connected to the outermost cities of another state. For this i will need a convex hull of all states. Thats where
i stopped before other, more pressing problems, took over.
