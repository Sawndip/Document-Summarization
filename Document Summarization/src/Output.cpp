#include "Output.h"
#include <bits/stdc++.h>
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
#define max_phrase_words 100
#define max_original_sentences 200
#define max_sentences_in_output 200
using namespace std;
extern map<long, string>map_distinctwords_two;
extern map<string, long>map_distinctwords_one;
extern long all_phrase_words[max_phrase_words];
extern long number_of_phrase_words, number_of_sentences_in_output;
extern vector<long>word_in_differentsentence[max_sentence_number];
extern long original_sentences[max_original_sentences];
extern long total_sentences_in_output[max_sentences_in_output];
extern char sentence[max_sentence_number][max_sentence_length];
bool is_unique[1000];
Output::Output()
{
    long u, v, i, j, k, sz;
    for(i = 0; i < number_of_phrase_words; i++)
    {
        u = all_phrase_words[i];
        sz = word_in_differentsentence[u].size();
        for(j = 0; j < sz; j++)
        {
            v = word_in_differentsentence[u][j];
            if(is_unique[v])
            {
                total_sentences_in_output[number_of_sentences_in_output] = v;
                number_of_sentences_in_output++;
            }
            is_unique[v] = 1;
            //original_sentences[number_of_original_sentences] = word_in_differentsentence[u][j];
        }
    }
    sort(total_sentences_in_output, total_sentences_in_output + number_of_sentences_in_output);
    for(i = 0; i < number_of_sentences_in_output; i++)
    {
        u = total_sentences_in_output[i];
        cout << sentence[u] << endl;
    }
}
