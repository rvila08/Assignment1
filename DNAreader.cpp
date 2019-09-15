//Assignment1

#include "DNAreader.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int lineCount = 0;
int letterCount = 0;
ifstream fileStream;
ofstream outputstream;


int sumA = 0, sumC = 0, sumT = 0, sumG = 0;

int sumAA = 0, sumAT = 0, sumAC = 0, sumAG = 0;

int sumCA = 0, sumCC = 0, sumCG = 0, sumCT = 0;

int sumGA = 0, sumGC = 0, sumGG = 0, sumGT = 0;

int sumTT = 0, sumTA = 0, sumTC = 0, sumTG = 0;

float probA = 0, probC = 0, probT = 0, probG = 0;

float probAA = 0, probAC = 0, probAT = 0, probAG = 0;

float probCC = 0, probCA = 0, probCT = 0, probCG = 0;

float probTA = 0, probTC = 0, probTT = 0, probTG = 0;

float probGA = 0, probGC = 0, probGT = 0, probGG = 0;


int sumLetters(string fileName){
  string line;
  fileStream.open(fileName);

    if(fileStream.is_open()){            //read file using fileStream
      while(getline(fileStream, line)){
        lineCount++;
          for (int i = 0; i < line.length();++i){
            char letter = tolower(line[i]);           //iterate through each letter in line
            if(letter == 'a')
              sumA += 1;
            else if(letter == 'c')
              sumC += 1;
            else if(letter == 't')
              sumT += 1;
            else if(letter == 'g')
              sumG += 1;
          }
          letterCount = sumA + sumC + sumT + sumG;        //add up all the seperate letter counts to get total
        }
      }

    fileStream.close();
    return letterCount;
}

float meanLetters(string fileName){
  return letterCount/lineCount;
}

float variance(string fileName, double mean){
  string line;
  float diffSum = 0;
  float variance = 0;
  fileStream.open(fileName);

  while(getline(fileStream, line)){
      diffSum += pow((float)line.length() - mean, 2);
  }

  variance = diffSum / (lineCount - 1);
  fileStream.close();

  return variance;
}

float stdDev(string fileName, float Variance){          // call variance in main method
    float stdDev = sqrt(Variance);

    return stdDev;
}

void probNuc(){
  float probA = (float)sumA/(float)letterCount;               //probability of nucleotides
  float probC = (float)sumC/(float)letterCount;
  float probT = (float)sumT/(float)letterCount;
  float probG = (float)sumG/(float)letterCount;
  outputstream << "Prob of A nucleotide is: " << probA*100 << endl;
  outputstream << "Prob of C nucleotide is: " << probC*100 << endl;
  outputstream << "Prob of T nucleotide is: " << probT*100 << endl;
  outputstream << "Prob of G nucleotide is: " << probG*100 << endl;

}

void countBigrams(string fileName){
  string line;
  fileStream.open(fileName);
  int totalBigram = 0;
  while(getline(fileStream, line)){
      for(int i = 0; i<line.length(); i+=2){ //i+=2 to skip a character - not count same nucleotide twice
        char nuc1 = tolower(line[i]);      //make all characters lowercase
        char nuc2 = tolower(line[i+1]);

        if(nuc1 == 'a' && nuc2 == 'a'){   //count bigram if both conditions true
            sumAA++;
            totalBigram++;
        }
        else if(nuc1 == 'a' && nuc2 == 'c'){
            sumAC++;
            totalBigram++;
        }
        else if(nuc1 == 'a' && nuc2 == 't'){
            sumAT++;
            totalBigram++;
        }
        else if(nuc1 == 'a' && nuc2 == 'g'){
            sumAG++;
            totalBigram++;
        }
        else if(nuc1 == 'c' && nuc2 == 'c'){
            sumCC++;
            totalBigram++;
        }
        else if(nuc1 == 'c' && nuc2 == 'a'){
            sumCA++;
            totalBigram++;
        }
        else if(nuc1 == 'c' && nuc2 == 't'){
            sumCT++;
            totalBigram++;
        }
        else if(nuc1 == 'c' && nuc2 == 'g'){
            sumCG++;
            totalBigram++;
        }
        else if(nuc1 == 'g' && nuc2 == 'g'){
            sumGG++;
            totalBigram++;
        }
        else if(nuc1 == 'g' && nuc2 == 'a'){
            sumGA++;
            totalBigram++;
        }
        else if(nuc1 == 'g' && nuc2 == 'c'){
            sumGC++;
            totalBigram++;
        }
        else if(nuc1 == 'g' && nuc2 == 't'){
            sumGT++;
            totalBigram++;
        }
        else if(nuc1 == 't' && nuc2 == 't'){
            sumTT++;
            totalBigram++;
        }
        else if(nuc1 == 't' && nuc2 == 'a'){
            sumTA++;
            totalBigram++;
        }
        else if(nuc1 == 't' && nuc2 == 'c'){
            sumTC++;
            totalBigram++;
        }
        else if(nuc1 == 't' && nuc2 == 'g'){
            sumTG++;
            totalBigram++;
        }
      }
    fileStream.close();
  }

probAT = ((float)sumAT/(float)totalBigram)*100;
probAC = ((float)sumAC/(float)totalBigram)*100;
probAA = ((float)sumAA/(float)totalBigram)*100;
probAG = ((float)sumAG/(float)totalBigram)*100;

probTT = ((float)sumTT/(float)totalBigram)*100;
probTC = ((float)sumTC/(float)totalBigram)*100;
probTA = ((float)sumTA/(float)totalBigram)*100;
probTG = ((float)sumTG/(float)totalBigram)*100;

probCT = ((float)sumCT/(float)totalBigram)*100;
probCA = ((float)sumCA/(float)totalBigram)*100;
probCC = ((float)sumCC/(float)totalBigram)*100;
probCG = ((float)sumCG/(float)totalBigram)*100;

probGG = ((float)sumGG/(float)totalBigram)*100;
probGC = ((float)sumGC/(float)totalBigram)*100;
probGT = ((float)sumGT/(float)totalBigram)*100;
probGA = ((float)sumGA/(float)totalBigram)*100;

outputstream<< "The probability of AT is: " << probAT << endl;
outputstream<< "The probability of AC is: " << probAC << endl;
outputstream<< "The probability of AG is: " << probAG << endl;
outputstream<< "The probability of AA is: " << probAA << endl;

outputstream<< "The probability of TT is: " << probTT << endl;
outputstream<< "The probability of TA is: " << probTA << endl;
outputstream<< "The probability of TG is: " << probTG << endl;
outputstream<< "The probability of TC is: " << probTC << endl;

outputstream<< "The probability of GT is: " << probGT << endl;
outputstream<< "The probability of GG is: " << probGG << endl;
outputstream<< "The probability of GC is: " << probGC << endl;
outputstream<< "The probability of GA is: " << probGA << endl;

outputstream<< "The probability of CC is: " << probCC << endl;
outputstream<< "The probability of CT is: " << probCT << endl;
outputstream<< "The probability of CG is: " << probCG << endl;
outputstream<< "The probability of CA is: " << probCA << endl;
}

float gaussian(float mean, float stdDev){
  float randA = (float)rand()/(float)RAND_MAX;
  float randB = (float)rand()/(float)RAND_MAX;

  float C = sqrt((-2)*log(randA)) * cos(2*(M_PI)*randB); //use equation on blackboard
  float D = stdDev * C +mean;

  return D;
}

float printGaussian(float mean, float stdDev){
  for(int i = 0; i<1000;++i){
    float gausDistribution = gaussian(mean, stdDev);

    int nucA = ((float)sumA / letterCount) * gausDistribution;
    int nucC = ((float)sumC / letterCount) * gausDistribution;
    int nucT = ((float)sumT / letterCount) * gausDistribution;
    int nucG = ((float)sumG / letterCount) * gausDistribution;
    string generatedString = "";

    for(int j=0; j < nucA; ++j){
      generatedString += 'a';
    }
    for(int j=0; j < nucC; ++j){
      generatedString += 'c';
    }
    for(int j=0; j < nucT; ++j){
      generatedString += 't';
    }
    for(int j=0; j < nucG; ++j){
      generatedString += 'g';       // appending nucleotides into a string
    }

    outputstream << generatedString << endl; //output string into .out file
  }
}

bool fileCheck(string fileName){
    fileStream.open(fileName);
    bool doesFileExist = fileStream.is_open();     //check if a file stream is currently open
    fileStream.close();
    return doesFileExist;         // will return false if a file stream isnt open
}

void resetVariables(){
  lineCount = 0;
  letterCount = 0;
  sumA = 0; 
  sumC = 0;
  sumT = 0;
  sumG = 0;

  sumAA = 0;
  sumAT = 0;
  sumAC = 0;
  sumAG = 0;

  sumCA = 0;
  sumCC = 0;
  sumCG = 0;
  sumCT = 0;

  sumGA = 0;
  sumGC = 0;
  sumGG = 0;
  sumGT = 0;

  sumTT = 0;
  sumTA = 0;
  sumTC = 0;
  sumTG = 0;

  probA = 0;
  probC = 0;
  probT = 0;
  probG = 0;

  probAA = 0;
  probAC = 0;
  probAT = 0;
  probAG = 0;

  probCC = 0;
  probCA = 0;
  probCT = 0;
  probCG = 0;

  probTA = 0;
  probTC = 0;
  probTT = 0;
  probTG = 0;

  probGA = 0;
  probGC = 0;
  probGT = 0;
  probGG = 0;

}
