#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <cctype> // for isalpha
using namespace std;

unordered_map<std::string, int> exclMap;

std::unordered_map<int,int>vowels;

bool isNice2(string str)
{
  bool ok = false;
  int n = str.length();
  for(int i=0;i<n-2;i++)
    {
      if(str[i] == str[i+2])
	{
	  ok = true;
	  break;
	}
    }
  if(!ok)return false;
  ok = false;
  for(int i=0;i<n-3;i++)
    {
      for(int j=i+2;j<n-1;j++)
	{
	  if(str.substr(i,2) == str.substr(j,2))
	    {
	      ok = true;
	      break;
	    }
	}
      if(ok)
	{
	  break;
	}
    }
  if(!ok)return false;
  return true;
}

bool isNice(string str)
{
  
  int n = str.length();
  string sstr;
  for(int i=0; i<n-1;i++)
    {
      sstr = str.substr(i,2);
      

	if(exclMap.find(sstr)!=exclMap.end())
	  {
	    return false;
	  }
    }

  int cntVowel = 0;
  for(int i=0;i<n;i++)
    {
      if(vowels[int(str[i]-'a')] == 1)
	{
	  cntVowel++;
	}
    }
  if(cntVowel < 3)
    {
      return false;
    }

  bool ok = false;
  for(int i=0;i<n-1;i++)
    {
      if(str[i] == str[i+1])
	{
	  ok = true;
	  break;
	}
    }
  
  return ok;
}

bool alphaString(string str)
{
  for(char &ch:str)
    {
      if(!isalpha(ch))
	{
	  return false;
	}
    }
  return true;
}
   
  
      
int main()
{
exclMap["ab"] = 1;
exclMap["cd"] = 1;
exclMap["pq"] = 1;
exclMap["xy"] = 1;

vowels[0] = 1; // a
vowels[4] = 1; // e
vowels[8] = 1; // i
vowels[14] = 1; // o
vowels[20] = 1; // u


  string fn = "day5-ip.txt";
  ifstream ifs(fn);

  if(!ifs.is_open())
    {
      printf("err opening ip file\n");
      return 0;
    }
  int cnt = 0;
  string curline;
  int hell = 0;
  while(getline(ifs, curline))
    {
      //  cout<<"debug: "<<curline<<"\n";
      // hell++;
      // if(hell == 5)
      // 	{
      // 	  break;
      // 	}
      // transform(curline.begin(), curline.end(), curline.begin(), ::tolower);
      if(isNice2(curline))
	{
	  cnt++;
	}
      // if(!alphaString(curline))
      // 	{
      // 	  cout<<"Hurray\n";
      // 	  break;
      // 	}
    }
  ifs.close();
  cout<<"ans: "<<cnt<<"\n";
  return 0;
}
      
       
   
