# Overview

A very basic program for the word guessing game Wordle. It uses the command line instead of fancy graphics, isn't particularly robust, and lacks much replayability for now, but that's okay.

Why? Because this was primarily written as a means to explore using the C++ language, and make something I deem interesting while doing it.

Note: Visual Studio has some automatic file structuring to it that can make things a bit tricky to find; the main things are the .cpp file found in the Wordle folder (a little strange and redundant, I know), and the .exe located in x64.

[Software Demo Video](https://youtu.be/0lg0hQb3htg)

# Development Environment

Developed using Visual Studio - Community 2022

Languages used: C++

Libraries used: stdlib, string, vector, iostream, time

# Useful Websites

These each link to specific pages that I found helpful while working on particular parts of my project; each parent site is just a general source I found useful:
* [Microsoft Devblogs - Hello World Tutorial](https://devblogs.microsoft.com/cppblog/cpp-tutorial-hello-world/)
* [LearnCPP - Cin and Inputs](https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/)
* [GeeksForGeeks - Ways to Create String Arrays](https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/)
* [CPlusPlus - Rand](https://www.cplusplus.com/reference/cstdlib/rand/)
* [CPlusPlus - String](https://www.cplusplus.com/reference/string/string/)
* [W3Schools - Class Constructors](https://www.w3schools.com/cpp/cpp_constructors.asp)

# Future Work

* Fix: Handle non-uniform user input (not enough/too many letters, wrong data type, uppercases, etc.)
* Add: Have an external word list file with a lot more words and allow users to add to a dynamic list of words
* Add: Allow for 4- and 6-world wordles
* Change: Put the Wordle class in its own file