Fire is a problem in which a man named joe has to escape from some fire. The fire spreads at the same rate that that joe can run. There are also walls in joes way sometimes.
This is a breadth first search problem because the way that the fire and joe spread can be accomplished using a similar method to breadth frist search. To start i took in the data
which represents the "maze" joe will be trying to escape. The maze contains 1 fire source and Joes starting point as well as several walls in his way.

I approached this by calling upon a project I did in discrete data structures where a walled maze was explored using an algorithm that checked each adjacent square and moved to it if it was available to move to. 
I applied this approach to both joe and the fire. If the fire blocks off all of joe's exit then he dies and the maze is inescapeable! But if joe tries to access a coordinate address that is outside the bounds of
the maze then he escapes successfully!
