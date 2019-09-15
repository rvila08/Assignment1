#include <iostream>
#include "DNAreader.cpp"

using namespace std;


int main(int argc, char** argv) {
  outputstream.open("rickyvila.out");
  string fileName;

  bool restart = true;

  if(argc==2){
    fileName = argv[1];         //2nd command line argument is input for file name
  }
  else{
    "Please enter with format: ./a.out 'file name'";
    restart = false;    //if format is wrong, exit program
  }

  while(restart){

    sumA = 0;
    sumC = 0;
    sumG = 0;
    sumT = 0;
    lineCount = 0;
    letterCount = 0;

    if(fileCheck(fileName)!=true){
      cout << "File does not exist. Exiting program. ";
      break;       //check file at beggining of every loop to ensure it exists
    }

    int sum = sumLetters(fileName);
    float mean = meanLetters(fileName);
    float var = variance(fileName, mean);  //made variables to input into functions

    sumA = 0;
    sumC = 0;
    sumG = 0;
    sumT = 0;
    lineCount = 0;
    letterCount = 0;

    outputstream << "Ricky Vila" << endl;
    outputstream << "ID: 2320586" << endl;
    outputstream << "Section 3" << endl;
    outputstream << "The file name is: " << fileName << endl;
    outputstream << "The sum is: " << sumLetters(fileName) << endl;
    outputstream << "The mean is: " << meanLetters(fileName) << endl;
    outputstream << "The variance is: " << variance(fileName, mean) << endl;
    outputstream << "The standard deviation is: " << stdDev(fileName, var) << endl;
    probNuc();
    countBigrams(fileName);
    gaussian(mean, sqrt(var));
    printGaussian(mean, sqrt(var));

    string userInput;       //user input to determine whether to restart loop 
    cout << "Do you want to process another list? (yes/no) ";
    cin >> userInput;

    if(userInput == "yes"|| userInput == "y"){
        cout << "Enter new file name: ";
        cin >> fileName;
         continue;
    }
    else if(userInput == "no"|| userInput == "n"){
        cout << "Exiting program. " << endl;
        break;
    }
    else if(userInput!= "yes"|| userInput!= "no"){
      cout<<"User input unrecognized. Exiting program."<< endl;
      break;
    }
  }

  return 0;
}
