#include "headers.hpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  if(argc!=2) cout << "error: number of arguments\n";
  std::ifstream ist(argv[argc-1]);
  vector<int> arr(37);
  vector<vector<int>> data;
  while(ist.good()) {
    vector<int> arr(37);
    for(auto& i:arr) {
      ist >> i;
    }
    data.push_back(arr);
  }
  data.pop_back();
  std::ifstream istm(argv[argc-1]);
  int number ;
  vector<int> numbers;
  while (istm>>number) {
    numbers.push_back(number);
  }
  cout << "max: " << *boost::max_element(numbers) << endl;
  cout << "input number of lines = " << data.size() << endl;

  decltype(data) data16;
  for(auto i:data) {
    if(i[36]==1) data16.push_back(i);
    if(i[36]==6) {
      data16.push_back(i);
      data16.back()[36]=0;
    }
  }
  cout << "output number of lines = " << data16.size() << endl;
  std::ofstream ofs("out.txt");
  for(auto i: data16) {
    for(auto j:i) ofs << j<< " ";
    ofs << endl;
  }
  return 0;
}
