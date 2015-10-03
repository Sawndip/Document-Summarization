#include <bits/stdc++.h>
#include "SubSentence.h"
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
extern long number_of_sentences, count_total_subsentence;
extern long number_of_subsentences[max_sentence_number];
extern char sentence[max_sentence_number][max_sentence_length];
extern char subsentences[max_sentence_number][max_subsentence_number][max_subsentence_length];
extern char total_subsentence[max_subgraph][max_subsentence_length];
extern map<string, long>map_stopwords;
extern map<string, long>map_wordfrequency;
extern map<string, long>map_distinctwords_one;
extern vector<long>word_in_differentsentence[max_sentence_number];
extern vector<long>word_in_differentsubsentence[max_subgraph];
char temp_sentence[max_sentence_length];
SubSentence::SubSentence()
{
    for(i = 0; i < number_of_sentences; i++)
    {
        count_subsentence = 0;
        strcpy(temp_sentence, sentence[i]);
        pch = strtok (temp_sentence, ".,");
        while(pch != NULL)
        {
          //  cout << pch << endl;
            strcpy(total_subsentence[count_total_subsentence], pch);
            strcpy(subsentences[i][count_subsentence], pch);
            count_total_subsentence++;
            count_subsentence++;
            pch = strtok(NULL, ".,");
        }
        number_of_subsentences[i] = count_subsentence;
    }
}
void SubSentence::WordFrequency()
{
    map<string, long>word_flag;
    word_flag.clear();
    for(i = 0; i < number_of_sentences; i++)
    {
        word_flag.clear();
        strcpy(temp_sentence, sentence[i]);
        pch = strtok (temp_sentence," ,.");
        while(pch != NULL)
        {
            if(map_stopwords[pch] != -1)
            {
             map_wordfrequency[pch]++;
            }
            if(map_stopwords[pch] != -1 && !word_flag[pch])
            {
                //if(strcmp("Karim", pch) == 0) cout << i << endl;
                word_in_differentsentence[map_distinctwords_one[pch]].push_back(i);
            }
            pch = strtok(NULL, " ,.");
        }
    }
}
void SubSentence::WordInSubsentence()
{
    long u;
    for(i = 0; i < count_total_subsentence; i++)
    {
        strcpy(temp_sentence, total_subsentence[i]);
        pch = strtok(temp_sentence, " ,.");
        while(pch != NULL)
        {
         if(map_stopwords[pch] != -1 )
         {
          //if(strcmp("Karim", pch) == 0) cout << i << endl;
          u = map_distinctwords_one[pch];
          word_in_differentsubsentence[u].push_back(i);
         }
         pch = strtok(NULL, " ,.");
        }
    }
}
