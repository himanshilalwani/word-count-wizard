# Word Count Wizard
Word Count Wizard is a powerful tool designed to count unique words, analyze word frequencies, and perform various operations on text provided by the user. This wizard employs hash tables for efficient organization and retrieval of information. Read on to discover how to unleash the power of the Word Count Wizard!

## Description
Word Count Wizard excels at processing text data. Key functionalities include:
* <b>Loading and Hash Function Selection: </b>
  * The wizard greets the user and requests an input file path. Additionally, users can choose from the following hash functions to handle the data organization within the hash table:
    * Cycle Shift Hash Function (Compression Method -> Division)
    * Polynomial Hash Function
    * Summation Hash Function
    * Cycle Shift Hash Function (Compression Method -> MAD)
    * Polynomial Hash Function 2
  * If no choice is made, Polynomial Hash Function 2 will be used as the default hash function because of its low collision rate.
* <b>Analytics: </b>
  * After loading the text, the wizard provides analytics such as total number of words in the text, number of unique words in the text, number of collisions caused by the hash function, and average number of collisions per unique entry caused by the hash function.
  * Users can then choose from these actions:
    * <b>Frequency Lookup: </b> Search for a specific word to retrieve its frequency within the text. If the word is not found, a zero value is returned.
    * <b>Change Hash Function: </b> Select a different hash function from the available list.
    * <b>Identifying the Word with Highest Frequency: </b> Find the word with the highest frequency in the text.
    * <b>Exit: </b> Choose this option to gracefully exit the Word Count Wizard.

## Instructions
* Open a terminal and navigate to the src folder within project directory using the cd command.
* Build the project using the provided makefile. Run the following command in the terminal: `make`.
* Once the project is successfully built, run the generated executable using the terminal: `./output`.
* The Word Count Wizard application will launch. Follow the on-screen instructions to interact with the program. 
