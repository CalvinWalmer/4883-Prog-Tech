### P161 Traffic Lights

Calvin Walmer

Objective of this program is to determine if traffic lights become synced up (green) within a reasonable time. Time
is measured from the instant when they all turned green simultaneously, although the initial portion
while they are all still green is excluded from the reckoning.

I actually had a pretty difficult time with this program. Wanted to use a formulaic approach to it originally but couldn't
get a good version of that working. Instead I just used an interative approach that loops over each second of each test case
and finds if all three of the lights are green at that time.

### Files

|   #   | File             | Description                                        |
| :---: | ---------------- | -------------------------------------------------- |
|   1   | P161.cpp         | Main solution code. Solves the problem     |
|   2   | input            | input from udebug used to test solution code         |
|   3   | p161.pdf         | pdf that outlines the problem |

### Instructions
- run and compile in terminal
- place input and p161.cpp in the same directory
- navigate to the directory in a cmd terminal using cd ...
- run the following command: cls && g++ p161.cpp && a < input
- profit
