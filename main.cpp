/* --------------------------------------------------------
 * prog2RallySongs.cpp
 *    Read political candidate's favorite song lyrics from a file.
 *    Choose random lines and see if the reader can identify the candidate.
 *
 *    This was inspired by the New York Times article:
 *       https://www.nytimes.com/interactive/2019/08/19/us/politics/presidential-campaign-songs-playlists.html
 *    which describes the different songs played at political rallies for
 *    different 2020 presidential candidates.
 *
 * Class: Program #2 for CS 141, Fall 2019
 * Lab: Tuesday 11am,
 * Professor Name: Mr. Dale Reed
 * System: Mac OS X
 * Author: Amaan Hussain
 */

#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>      // For file input
#include <iomanip>     // For setw
#include <cstdlib>     // For exit and abs
#include <ctime>       //For creating the srand to be as random as possible

using namespace std;
//***Aditi: Use camel case for function names
  //***Aditi: The comments should have the function utility and the parameters explained
void DisplayRandomLine(string candidateName){  
    ifstream inputFileStream;  // Declare the input file stream
    
    //Opening the file stream and then printing an error if file cannot be opened.
    inputFileStream.open( candidateName.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << candidateName << "  Exiting..." << endl;
        exit( -1);
    }
    
    // Read the number on the first line of the input file, which indicates how many subsequent
    // lines there are in the file.
    int numberOfLinesInFile = 0;
    inputFileStream >> numberOfLinesInFile;
    int lineNumber = rand()%numberOfLinesInFile;
    int counter = 1;
    
    // Read one line at a time, repeating until we get to the designated line.  If the designated
    // line is blank or is a comment line starting with '#', then skip it and go on to the next.
    string line;
    while( getline( inputFileStream, line) ) {
        if(counter == lineNumber){
          if ( (line.length()==0) || (line.at(0) == '#') || (line.at(0)== ' ')){
              lineNumber ++;
          } else {
            cout << line << endl;
          }
        }//end of if counter == lineNumber
        counter ++;
    }//end while( getLine...
    inputFileStream.close();    // Close the input file.
}


//***Aditi: use meaningful variable names
void CalculatePercentage(double x, double y){
    cout << "You got " << x << " out of " << y << "," << " which is " << (x/y)*100 
         << "%" << endl;
    
}
                   

//-------------------------------------------------------------------------------------------------
int main() {
	
	// Here is some sample code to open a file, read the number on the first line, and print it.
	ifstream inputFileStream;  // Declare the input file stream
    int userInput; 
    int linesToDisplay = 0;
    int quizAnswer;
    double questionCounter = 0.0;
    double answerCounter = 0.0;
    
    // Open input file and verify that file was found
    string candidateName = "Trump.txt";
    inputFileStream.open( candidateName.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << candidateName << "  Exiting..." << endl;
        exit( -1);
    }
    
    string candidateName1 = "Warren.txt";
    inputFileStream.open( candidateName1.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << candidateName1 << "  Exiting..." << endl;
        exit( -1);
    }

    // Read the number on the first line of the input file, which indicates how many subsequent
    // lines there are in the file.
    int numberOfLinesInFile = 0;
    
    // Initialize the random number generator
    srand(1);    

	// Display which program this is and display menu options to select program output to be displayed
	// creating a do while loop sp that is keeps displaying menu options until program is quit
  do{
         cout << endl << "----  Program 2: Rally Songs  ----          \n"
              << "Select from the following:                 \n"
              << "   1. Set number of lines to display       \n"
              << "   2. Get random lines from Trump.txt      \n"
              << "   3. Get random lines from Warren.txt     \n"
              << "   4. Rally song quiz                      \n"
              << "   5. Exit the program                     \n"
              << "Your choice --> ";
         
         cin >> userInput;
         cout << endl << endl;
         string line;
    
    //if statement to allow user to modify how many lines to display
    if (userInput == 1){
        cout << "Enter the number of lines you want to display -> ";
        cin >> linesToDisplay;      
    }
        
    //if statement that allows user to display lines from the Trump File
    if (userInput == 2){
       int counter1 = 0;
        if (linesToDisplay == 0){
            do {
                DisplayRandomLine("Trump.txt");
                counter1++;
            }while(counter1 < 3);
        }// end of if linesToDisplay == null
        else{
            for(int f = 1; f <= linesToDisplay; f++){
                DisplayRandomLine("Trump.txt");
            }// end of for loop
        }// end of else statement 
        
    }// end of else if userinput ==2
    
    //if statement to allow user to display lines from Warren File  
    if (userInput == 3){
         int counter2 = 0;
        if (linesToDisplay == 0){
            do {
                DisplayRandomLine("Warren.txt");
                counter2++;
            }while(counter2 < 3);
        }// end of if linesToDisplay == null
        else{
            for(int g = 1; g <= linesToDisplay; g++){
                DisplayRandomLine("Warren.txt");
            }// end of for loop
        }// end of else statement
    } //end of else if userinput == 3
    
    //if statement to allow user to take a quiz and guess rally songs from the candidates
    if (userInput == 4){
        questionCounter++;
        int randCandidate = rand () % 2 + 1; //sets candidate to be randomly picked
        if (randCandidate == 1){
             int counter1 = 0;
        if (linesToDisplay == 0){
            do {
                DisplayRandomLine("Trump.txt");
                counter1++;
            }while(counter1 < 3);
        }// end of if linesToDisplay == null
        else{
            for(int f = 1; f <= linesToDisplay; f++){
                DisplayRandomLine("Trump.txt");
            }// end of for loop
        }// end of else statement 
        
        }
        if (randCandidate == 2){
            int counter2 = 0;
        if (linesToDisplay == 0){
            do {
                DisplayRandomLine("Warren.txt");
                counter2++;
            }while(counter2 < 3);
        }// end of if linesToDisplay == null
        else{
            for(int g = 1; g <= linesToDisplay; g++){
                DisplayRandomLine("Warren.txt");
            }// end of for loop
        }// end of else statement
        }//end of if randCandidate == 2
        cout << endl << "Enter 1 for Trump, 2 for Warren: ";
        cin >> quizAnswer;
        cout << endl;
         
        if (quizAnswer == randCandidate){
            answerCounter++;
            cout << "Correct! ";
            CalculatePercentage(answerCounter, questionCounter);
        }
        else{
            cout << "Wrong! ";
            CalculatePercentage(answerCounter, questionCounter);
        }
       
    }// end of if userInput == 4
   
  }while (userInput !=5);//end of do-while loop
    
    //if user is exiting the program without playing the quiz
    if((userInput == 5) && (questionCounter == 0)){
        cout << "You got 0 out of 0, which is 0%";
        cout << endl << endl;
    }
    else{
        CalculatePercentage(answerCounter, questionCounter);
    }
    
    
    return 0;
}//end main()
