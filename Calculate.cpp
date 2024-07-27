#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInput(const string &input) 
{
    vector<int> numbers;
    istringstream stream(input);
    int number;
    while (stream >> number) 
    {
        numbers.push_back(number);
    }
    return numbers;
}
int main() 
{
  string White, Black;
  cout << "Enter White value: ";
  getline(cin, White);
  cout << "Enter Black value: ";
  getline(cin, Black);

  vector<int> numbers1 = parseInput(White);
  vector<int> numbers2 = parseInput(Black);

  vector<int> result;

  for (size_t i = 0; i < numbers1.size() && i < numbers2.size(); ++i) 
  {
      result.push_back((numbers1[i] + numbers2[i]) /2 );
  }

  cout << "Average value:\n";
  for (int sum : result) 
  {
    cout << sum << endl;
  }
  cout << endl;

  return 0;
}