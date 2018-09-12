## CYK Algorithm

This implementation is not complete, since it still has a few bugs, when it runs the algorithms. Some of the words work and some don't I was not able to understand why it was not working, before the deadline of this delivery.

# How it works:

1. This implementation will launch the console and will ask to load a grammar, that can be done by inserting the absolute path to the file (included in this folder), which includes the sample grammar
2. After loading the grammar it is needed to load the input strings, which are given in a file, that can also be found in this folder
3. Once the grammar and strings have been loaded it will show a prompt to choose the variant of the CYK algorithm.
4. After choosing the variant, the parser will start automatically and as the strings are being parsed the results will be shown in the console. The results are displayed as: "x,y,w,z", 'x' being the input string size, 'y' the time in milliseconds that the algorithm took to parse the string, 'w' the number of operations that took to get the result and finally 'z' the truth value that indicates whether the string belongs to the grammar.
