For this problem mario has to jump either up or down to land on top of the next wall as he is progressing though the level

![image](https://github.com/CalvinWalmer/4883-Prog-Tech/assets/112140788/433bd360-c298-4e7d-bdfd-dbb8230021ad)

You are tasked with finding the number of high jumps and low jumps he makes. If mario has to jump up to a wall that is
higher than the one he is currently on then it is considered a high jump. If the wall is lower than the one he is on, thenit is 
a low jump. My approach was to store the height of the wall mario is currently on and then compare it to the wall he has to jump to next
if the wall is higher, i would increment a counter that keeps track of the amount of high jumps he made; and do the same for low jumps.
Then after than update the height of the wall mario is currently at in preparation for the next comparison.
