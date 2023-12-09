Language detection is just a lookup table for a string. In retrospect, an STL map wouldve been perfect for this but I didnt think of that
at the time for some reason. Basically you are given in input file with hello written in different lanuages. Then you must print out what language it is.
Here is the key value pairs for the map if i had implemented one.
("HELLO",        "ENGLISH"),
("HOLA",         "SPANISH"),
("HALLO",        "GERMAN"),
("BONJOUR",      "FRENCH"),
("CIAO",         "ITALIAN"),
("ZDRAVSTVUJTE", "RUSSIAN")

Instead I just used a big long if else if else if else statement. Womp womp.
