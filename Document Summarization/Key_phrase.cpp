#include "Key_phrase.h"
#include "Global.h"
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
#define sf fscanf
#define pf fprintf
using namespace std;
long unique_phrase[1000];
extern vector<long>cluster[max_key_phrase];
extern long word_count, number_of_clusters, number_of_phrase_words, number_of_sentences_in_output;
extern long total_degree[max_number_of_words];
bool has_taken[max_number_of_words];
extern vector<long>connected_components[max_connection_per_node];
extern long selected_words[max_number_of_words], count_selected;
long cluster_detection[max_key_phrase];
extern map<long, string>map_distinctwords_two;
extern map<string, long>map_distinctwords_one;
extern long all_phrase_words[max_phrase_words];
extern long is_unique[10000];
extern long original_sentences[max_original_sentences];
extern long total_sentences_in_output[max_sentences_in_output];
extern char sentence[max_sentence_number][max_sentence_length];
extern vector<long>word_in_differentsentence[max_sentence_number];
extern long summary_size;
extern FILE *write;
Key_phrase::Key_phrase()
{
    write = fopen("output.txt","w");
    int i, u, v, sz, j, a, yes = 0, cluster_number, k;
    for(i = 0; i < count_selected; i++)
    {
        yes = 0;
        u = selected_words[i];
        sz = connected_components[u].size();
        for(j = 0; j < sz; j++)
        {
            v = connected_components[u][j];
            if(has_taken[v] && total_degree[v] >= 3)
            {
               yes = 1;
               cluster_number = cluster_detection[v];
               break;
            }
        }
        if(has_taken[u] && !yes)
        {
               yes = 1;
               cluster_number = cluster_detection[u];
        }
        if(!yes)
        {
            cluster_detection[u] = number_of_clusters;
            cluster_number  = cluster_detection[u];
            cluster[cluster_number].push_back(u);
            has_taken[u] = 1;
           // cout << map_distinctwords_two[u] << endl;
            number_of_clusters++;
        }
        for(j = 0; j < sz; j++)
        {
            v = connected_components[u][j];
            if(total_degree[v] >= summary_size) //Summary Size
            {
             cluster_detection[v] = cluster_number;
             has_taken[v] = 1;
             cluster[cluster_number].push_back(v);
            }
        }
    }
    for(i = 0; i < number_of_clusters; i++)
    {
        sz = cluster[i].size();
        for(j = 0; j < sz; j++)
        {
           u = cluster[i][j];
           if(!unique_phrase[u])
           {
            unique_phrase[u] = 1;
            all_phrase_words[number_of_phrase_words] = u;
            number_of_phrase_words++;
            //cout << map_distinctwords_two[u] << "  ";
           }
        }
      //  cout<<endl;
    }

    for(i = 0; i < number_of_phrase_words; i++)
    {
        u = all_phrase_words[i];
        sz = word_in_differentsentence[u].size();
        for(j = 0; j < sz; j++)
        {
            v = word_in_differentsentence[u][j];
            if(is_unique[v] == 1)
            {
                total_sentences_in_output[number_of_sentences_in_output] = v;
                number_of_sentences_in_output++;
            }
            is_unique[v]++;
            //original_sentences[number_of_original_sentences] = word_in_differentsentence[u][j];
        }
    }
    sort(total_sentences_in_output, total_sentences_in_output + number_of_sentences_in_output);
    for(i = 0; i < number_of_sentences_in_output; i++)
    {
        u = total_sentences_in_output[i];
        pf(write,"%s\n",sentence[u]);
        cout << sentence[u] << endl;
    }
}
