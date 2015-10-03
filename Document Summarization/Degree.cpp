#include "Degree.h"
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
using namespace std;
extern char all_words[max_number_of_words][max_word_length];
extern vector<long>word_in_differentsubsentence[max_subgraph];
extern map<string, long>map_distinctwords_one;
extern map<long, string>map_distinctwords_two;
extern long word_count, total_degree[max_number_of_words], summary_size;
extern long dgre[max_subgraph][max_number_of_words];
extern long selected_words[max_number_of_words], count_selected;
Degree::Degree()
{
    long i, u, v, j, sz;
   // cout << word_count << endl;
    for(i = 0; i < word_count; i++)
    {
        u = map_distinctwords_one[all_words[i]];
        sz = word_in_differentsubsentence[u].size();
        for(j = 0; j < sz; j++)
        {
            v = word_in_differentsubsentence[u][j];
            total_degree[u] += dgre[v][u];
        }
    }
    for(i = 0; i < word_count; i++)
    {
        u = map_distinctwords_one[all_words[i]];
        if(total_degree[u] >= summary_size) //Summary Size
        {
            selected_words[count_selected] = u;
            count_selected++;
           // cout << all_words[i] << "   " <<  total_degree[u] << endl;
        }

    }
}
