Before starting this assignment, you need to read through Chapters 18  Dictionaries. In particular, you need to focus on section 18.4.7 Using Hashing and Separate Chaining to Implement the ADT Dictionary.
The files in the next section contain a simplified version of the dictionary implementation from section 18.4.7 of your textbook. The main difference between this code and the code in the textbook is that it uses raw pointers.
Notice that for the class templates, the implementation has been added to the header file so that the class templates are compiled along with the driver program. 

For this assignment, you need to do the following:
Download all the files included in the next section. You will probably want to add all these files to a project. The code should compile and run without errors.Be sure you understand how the code works.

You can use the traverse method along with the print functions in the driver to print all the entries in the dictionary. However, this output does not give you a clear picture of how the data is organized. For debugging purposes, I want you to add a print() method to the HashedDictionary class template that displays the list of entries stored at each index of the dictionary. The ouput from a call to your print method might look like:

At index 0:
    No entries
At index 1:
    Entry: Key =        1  Item =            A
At index 2:
    Entry: Key =       53  Item =          AAA
    Entry: Key =        2  Item =            B
At index 3:
    Entry: Key =       20  Item =            T
    Entry: Key =        3  Item =            C
. . .
Add one or more calls to your new print() method to your driver program to show the state of the Dictionary. You should note that a Dictionary that uses open addressing should generally keep the number of entries under 30% of the dictionary size (DEFAULT_CAPACITY). With separate chaining, it is possible for the number of entries to exceed the dictionary size since each index in the dictionary contains a list of entries that hash to that index.

Generally a Dictionary does not allow multiple entries with the same key. If you look at the documentation for the add() method in DictionaryInterface.h it includes this precondition:

     @pre  The search key of the new item differs from all search keys presently in the dictionary.

However, the implementation of the add() method in HashedDictionary.h does not enforce this prerequisite. Modify this add() method so that it checks to see if there is already an entry in the dictionary with this key before trying to insert the new entry. Note that there is an existing method that will do this check for you - you just need to call it. If there is already an entry in the dictionary, the add() method should throw a PreconditionViolated exception. To do this, you will need to add the files PrecondViolatedExcep.h and precondViolatedExcep.cpp from Programming Assignment 9 to your project.

Be sure to add code to your driver to test this new code. Note that an unhandled exception will cause your driver program to abort. It is okay to leave your code like this, but you might want to try including try/catch code in your driver to prevent it from aborting.
