This problem is basically a checker to see if a triange with side lengths a, b, and c is a right triangle. The only annoying thing
in this problem is that the numbers are given in a random order, so they must be sorted. I just used a geeksforgeeks insertion sort
then used pythagorean theorem to check if a^2 + b^2 = c^2. The reason I had to sort them is because c^2 must be the largest side length always.
If the triangle passed the test i printed "right", if not. i printed "wrong".
