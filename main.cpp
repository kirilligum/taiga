#include "headers.hpp"
#include "read_to_dataframe.hpp"

using namespace std;

int split_score(const vector<int>& v) {
  size_t i=0;
  size_t j=v.size()-1;
  int maxl = numeric_limits<int>::lowest();
  int maxr = numeric_limits<int>::lowest();
  while(i<j){
    if(v[i]>maxl) maxl = v[i];
    if(v[j]>maxr) maxr = v[j];
    ++i;
    --j;
  }
  auto split_position = v[i];
  return maxl-split_position+maxr+split_position;
}

size_t calc_split_feature(const vector<vector<int>>& data) {
  size_t split_feature;
  int split_feature_score= numeric_limits<int>::lowest();
  for (size_t i = 0; i < data.size(); ++i) {
    auto tmpf = split_score(data[i]);
    cout << tmpf << "  " ;
    if(tmpf>split_feature_score) {
      split_feature_score=tmpf;
      split_feature = i;
    }
  }
  cout << endl;
  return split_feature;
}

int main() {
  auto train = read_to_dataframe("train.txt");
  cout << "train number of cols = " << train.first.size() << " and number of rows = " << train.first.front().size()<< "; and target size = " << train.second.size() << endl;
  auto test = read_to_dataframe("test.txt");
  cout << "test number of cols = " << test.first.size() << " and number of rows = " << test.first.front().size()<< "; and target size = " << test.second.size() << endl;

  auto split_feature = calc_split_feature(train.first);
  cout << "split_feature = " << split_feature << endl;
  return 0;
}
