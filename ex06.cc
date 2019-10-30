/*
ex06.cc
概要：文章を標準入力ストリームから単語ごとに読み， その単語がはじめて単語であれば vectorに加え出現
Author：Hiroki Yaginuma
Date：2019-10-27
*/

#include<list>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cctype>
#include<vector>
using namespace std;


struct WordCount{
  string Word;
  int Count;
  bool operator<(const WordCount &another) const
  {
    return Word < another.Word;
  };
};


bool checkalpha(WordCount);
bool compare(string);

int main(){
  string s;
  vector<WordCount> words;
  while(cin >> s){

    
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    //s.erase(remove(s.begin(), s.end(), '.'), s.end());
    //s.erase(remove(s.begin(), s.end(), ','), s.end());
      s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    //s.erase(remove(s.begin(), s.end(), '\''), s.end());
      s.erase(remove(s.begin(), s.end(), '('), s.end());
      s.erase(remove(s.begin(), s.end(), ')'), s.end());
      if(s.back()=='.' || s.back()==',' || s.back()=='?' || s.back()=='!' || s.back()==':') s.pop_back();
	

    
    int isFound = 0;
    vector<WordCount>::iterator iter = words.begin();

    
    while(iter != words.end()){
      if((*iter).Word == s){
        isFound = 1;
        ++(*iter).Count;
        break;
      }
      ++iter;
    }

    
    if(isFound == 0){
    
      
      WordCount S;
      S.Word = s;
      S.Count = 1;

     
      words.push_back(S);
    }
  }
  
  /*このへんにURLだけとりだす処理*/
  
  stable_partition(words.begin(),words.end(),checkalpha);

  //このへんに出現頻度順にして平均だすやつ

  
  vector<WordCount>::iterator ite = words.begin();
  while(ite != words.end()){
    cout << ite->Word << " " << ite->Count << endl;
    ite ++;
  }
  return 0;
}

bool checkalpha(WordCount x){

  string::iterator iter;
  iter=find_if(x.Word.begin(),x.Word.end(),compare);

  if(iter==x.Word.end()) return 1;

  else return -1;
}


bool compare(char c){
  return (!isalpha(c));
}
