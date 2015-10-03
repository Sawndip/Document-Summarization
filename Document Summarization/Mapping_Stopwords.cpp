#include <bits/stdc++.h>
#include "Mapping_Stopwords.h"
#define sf fscanf
#define pf fprintf
using namespace std;
extern map<string, long>map_stopwords;
Mapping_Stopwords::Mapping_Stopwords()
{
    read2 = fopen("English stop words.txt","r");
    sf(read2, "%s", stopwords);
    //cout << stopwords << endl;
    pch = strtok (stopwords,",");
  while (pch != NULL)
  {
     // cout << pch << endl;
      map_stopwords[pch] = -1;
      pch = strtok (NULL,",");
  }
}
