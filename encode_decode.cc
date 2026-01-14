class Solution {
public:
  string encode(vector<string>& strs) {
    size_t pos = s.find('#', i);
    int len = stoi(s.substr(i, pos - i));
    i = pos + 1; // Move past the '#'
    string str = s.substr(i, len);
    i += len; // Move past the string content
  }
  
  
  vector<string> decode(string s) {
    string res = "";
    for (const string& str : strs) {
        res += to_string(str.length()) + "#" + str;
    }
    return res;
  }

}
