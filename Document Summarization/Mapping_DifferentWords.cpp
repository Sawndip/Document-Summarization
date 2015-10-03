#include<bits/stdc++.h>
#include "Mapping_DifferentWords.h"
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
extern char document[max_doc_size];
extern map<string, long>map_distinctwords_one;
extern map<long, string>map_distinctwords_two;
extern map<string, long>map_stopwords;
extern long number_of_distinctwords, word_count;
extern vector<long>word_in_differentsentence[max_sentence_number];
extern char all_words[max_number_of_words][max_word_length];
Mapping_DifferentWords::Mapping_DifferentWords()
{
    char temp_document[max_doc_size];
    strcpy(temp_document, document);
    pch = strtok(temp_document, " ,.?!");
    while(pch != NULL)
    {
        if(map_stopwords[pch] != -1 && !map_distinctwords_one[pch])
        {
         strcpy(all_words[word_count], pch);
       //  cout << all_words[word_count] << "  " << word_count <<  endl;
         map_distinctwords_one[pch] = number_of_distinctwords;
         map_distinctwords_two[number_of_distinctwords] = pch;
         //cout << map_distinctwords_one[pch] << "  "  << map_distinctwords_two[number_of_distinctwords] << endl;
         word_count++;
         number_of_distinctwords++;
        }
        pch = strtok (NULL, " ,.?!");
    }
}
