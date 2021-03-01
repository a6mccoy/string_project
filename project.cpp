#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void toLower(string &str) {  // sets the string to lowercase
  string phrase = str;
  str = "";
  for (int i = 0; i < static_cast<int>(phrase.length()); i++) {
    str += tolower(phrase[i]);
  }
}

bool Contains(string str, string pattern) {
  for (int i = 0; i < static_cast<int>(str.length());
       i++) {  // loops through string checking if letter is equal to f, '%' or
               // '*'
    if ((str[i] == pattern[0]) || (pattern[0] == '%') ||
        (pattern[0] == '#')) {  // when this is true its loops through the
                                // letters of each checking equality
      int str_j = i;
      for (int j = 0; j < static_cast<int>(pattern.length()); j++) {
        bool num_case =
            ((pattern[j] == '#') && (str[str_j] - '0' < 10) &&
             (str[str_j] - '0' >
              -1));  // true if pattern[] is # && string[] is less than 10
        bool no_matches =
            ((str[str_j] != pattern[j]) && (pattern[j] != '%') &&
             (!num_case));  // true if pattern[]!=string[],pattern[]!=%,and
                            // num_case
        if ((j == static_cast<int>(pattern.length()) - 1) && (!no_matches)) {
          return true;
        } else if (no_matches) {
          break;
        }
        str_j++;
      }
    }
  }
  return false;
}

bool ImprovedContains(string str, string pattern, const bool *case_inSens) {
  if (*case_inSens) {
    toLower(str);
    toLower(pattern);
  }
  return Contains(str, pattern);
}

int Matches(string str, string pattern) {
  int count = 0;
  for (int i = 0; i < static_cast<int>(str.length());
       i++) {  // loops through string checking if letter is equal to f, '%' or
               // '*'
    if ((str[i] == pattern[0]) || (pattern[0] == '%') ||
        (pattern[0] == '#')) {  // when this is true its loops through the
                                // letters of each checking equality
      int str_j = i;
      for (int j = 0; j < static_cast<int>(pattern.length()); j++) {
        bool num_case = ((pattern[j] == '#') && (str[str_j] - '0' < 10) &&
                         (str[str_j] - '0' > -1));
        bool no_matches =
            ((str[str_j] != pattern[j]) && (pattern[j] != '%') && (!num_case));
        if ((j == static_cast<int>(pattern.length()) - 1) && (!no_matches)) {
          count++;
        }  // when the word is found count is incremented
        else if (no_matches) {
          break;
        }
        str_j++;
      }
    }
  }
  return count;
}

int ImprovedMatches(string str, string pattern, const bool *case_inSens) {
  if (*case_inSens) {
    toLower(str);
    toLower(pattern);
  }
  return Matches(str, pattern);
}

int FindFirstOf(string str, string pattern) {
  for (int i = 0; i < static_cast<int>(str.length());
       i++) {  // loops through string checking if letter is equal to f, '%' or
               // '*'
    if ((str[i] == pattern[0]) || (pattern[0] == '%') ||
        (pattern[0] == '#')) {  // when this is true its loops through the
                                // letters of each checking equality
      int str_j = i;
      int index = i;  // when the first letter is found index is set to its
                      // index
      for (int j = 0; j < static_cast<int>(pattern.length()); j++) {
        bool num_case = ((pattern[j] == '#') && (str[str_j] - '0' < 10) &&
                         (str[str_j] - '0' > -1));
        bool no_matches =
            ((str[str_j] != pattern[j]) && (pattern[j] != '%') && (!num_case));
        if ((j == static_cast<int>(pattern.length()) - 1) && (!no_matches)) {
          return index;
        }  // if it is true it returns the index
        else if (no_matches) {
          break;
        }
        str_j++;
      }
    }
  }
  return -1;  // if it gets to this point the pattern has not been found
}

int ImprovedFindFirstOf(string str, string pattern, const bool *case_inSens) {
  if (*case_inSens) {
    toLower(str);
    toLower(pattern);
  }
  return FindFirstOf(str, pattern);
}

int NumberOfDifferences(string str1, string str2) {
  int length =
      ((str1.length() < str2.length()) * str1.length()) +
      ((str2.length() < str1.length()) * str2.length()) +
      ((str1.length() == str2.length()) *
       str1.length());  // sets the length to whichever length is shorter
  int count =
      ((str1.length() < str2.length()) * (str2.length() - str1.length())) +
      ((str2.length() < str1.length()) *
       (str1.length() - str2.length()));  // count is long str - short str
  for (int i = 0; i < length; i++) {
    if (str1[i] != str2[i]) {
      count++;
    }
  }
  return count;
}

int ImprovedNumberOfDifferences(string str1, string str2, bool case_inSens) {
  if (case_inSens) {
    toLower(str1);
    toLower(str2);
  }
  return NumberOfDifferences(str1, str2);
}

void ImprovedReplace(string &str, string pattern, string replacement,
                     const bool *case_inSens) {
  int length = pattern.length();
  int start = ImprovedFindFirstOf(str, pattern, case_inSens);
  if (start != -1) {
    str.replace(start, length, replacement);
  }
}

int main(){
    const std::string text_1{"My dog is named Mal."};
    const std::string pattern_1{"named"};
    const std::string pattern_5{"mal"};
    const bool is_case_insensitive = false; 
    cout<<ImprovedContains(text_1, pattern_5, &is_case_insensitive)<<endl;
}






