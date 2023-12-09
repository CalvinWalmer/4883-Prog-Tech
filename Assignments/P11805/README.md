For this problem you are tasked with finding which player will be holding a soccer ball given the amount of passes, how many players on the team, and who has the ball at the start. What makes
this problem easier is that the players are standing in a circle and the ball is always passed to the player standing next to who has it, in one direction.
I saw this problem as being able to be solved with just some simple math operations. I started out on paper by writing down what would happen if certain numbers equaled wach other.
For example, if the amount of passes is equal to the number of players means that the player who started with the ball will end with the ball. The next thing I thought to do was simplify the
problem by removing "loops". That is, If the number of passes exceeds the amount of players, then I took the the modulus of players divided by passes. After all this i decided to start trying
to code up a solution. Once I did this I began adding logic for the starting player into the mix. The starting player made a difference if the number of passes plus the starting player passed over the "0th"
player. This was just a symptom of using a purely math based system. In the end I was able to come up with conditions for all of the cases that the initial conditions could produce!
