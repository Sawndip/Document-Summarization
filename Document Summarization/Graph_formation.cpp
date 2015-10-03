#include "Graph_formation.h"
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
extern map<string, long>map_distinctwords_one;
extern map<string, long>map_stopwords;
extern long number_of_subsentences[max_sentence_number], number_of_sentences, count_subgraph, count_node;
extern char sentence[max_sentence_number][max_sentence_length];
extern char subsentences[max_sentence_number][max_subsentence_number][max_subsentence_length];
extern vector<long>sub_graph[max_subgraph][max_words_in_a_subsentence];
extern long dgre[max_subgraph][max_number_of_words];
extern vector<long>connected_components[max_connection_per_node];
Graph_formation::Graph_formation()
{
    char temp_subsentence[max_subsentence_length];
    for(i = 0; i < number_of_sentences; i++)
    {
        for(j = 0; j < number_of_subsentences[i]; j++)
        {
            count_node = 0;
            strcpy(temp_subsentence, subsentences[i][j]);
        //    cout << temp_subsentence << endl;
            pch = strtok(temp_subsentence, " ,.");
            while(pch != NULL)
            {
                if(map_stopwords[pch] != -1)
                {
                strcpy(present_node, pch);
                u = map_distinctwords_one[prev_node];
                v = map_distinctwords_one[present_node];
                if(count_node)
                {
                connected_components[u].push_back(v);
                connected_components[v].push_back(u);
                sub_graph[count_subgraph][u].push_back(v);
                dgre[count_subgraph][u]++;
                dgre[count_subgraph][v]++;
                }
                count_node++;
                if(pch != NULL && map_stopwords[pch] != -1)
                {
                    strcpy(prev_node, pch);
                }
                }
                pch = strtok(NULL, " ,.");
            }
            count_subgraph++;
        }
    }
}

