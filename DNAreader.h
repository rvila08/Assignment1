#include <iostream>
#include <fstream>

using namespace std;

class DNAreader{

public:
  DNAreader();
  ~DNAreader();
  void resetVariables();
  int sumLetters(string fileName);
  float meanLetters(string fileName);
  float variance(string fileName, double mean);
  float stdDev(string fileName, float Variance);
  void probNuc();
  void countBigrams(string fileName);
  float gaussian(float mean, float stdDev);
  float printGaussian(float mean, float stdDev);
  bool fileCheck(string fileName);
};
