#include "read_to_dataframe.hpp"
#include "headers.hpp"

using namespace std;

pair<vector<vector<int>>,vector<int>> read_to_dataframe(const std::string& filename) {
  std::ifstream ist(filename);
  vector<int> arr(37);
  vector<vector<int>> ifs_data;
  while(ist.good()) {
    vector<int> arr(37);
    for(auto& i:arr) ist >> i;
    ifs_data.push_back(arr);
  }
  ifs_data.pop_back();
  //cout << "input number of lines = " << ifs_data.size() << " with " << ifs_data.front().size()<< endl;
  vector<vector<int>> data(ifs_data.front().size(),vector<int>(ifs_data.size()));
  vector<int> target(ifs_data.size());
  for (size_t i = 0; i < ifs_data.size(); ++i) {
    for (size_t j = 0; j < ifs_data.front().size(); ++j) {
      if(j==ifs_data.front().size()-1) target[i] = ifs_data[i][j];
      else data[j][i] = ifs_data[i][j];
    }
  }
  //cout << "data number of cols = " << data.size() << " with " << data.front().size()<< endl;
  return make_pair(data,target);
}
