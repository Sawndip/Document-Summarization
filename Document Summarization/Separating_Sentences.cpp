#include <bits/stdc++.h>
#include "Separating_Sentences.h"
#define sf fscanf
#define pf fprintf
#define max_doc_size 100000
#define max_sentence_number 100
#define max_sentence_length 200
#define max_subsentence_number 400
#define max_subsentence_length 200
#define max_words_in_a_subsentence 200
#define max_subgraph 500
#define max_number_of_words 10000
#define max_word_length 50
#define max_key_phrase 50
#define max_connection_per_node 100
using namespace std;
extern map<string, long>MapStopWords;
extern char document[max_doc_size], sentence[max_sentence_number][max_sentence_length];
extern long number_of_sentences;
extern FILE *write;
Separating_Sentences::Separating_Sentences()
{
  char temp_document[max_doc_size];
//  write = fopen("output.txt","w");
  strcpy(temp_document, document);
  pch = strtok (temp_document,".!?");
  while (pch != NULL)
  {
     strcpy(sentence[number_of_sentences], pch);
     len = strlen(pch);
     sentence[number_of_sentences][len] = '.', sentence[number_of_sentences][len + 1] = NULL;
    // cout << sentence[number_of_sentences] << endl;
     number_of_sentences++;
     pch = strtok (NULL, ".!?");
  }

}

