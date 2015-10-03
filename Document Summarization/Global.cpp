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
using namespace std;

char document[max_doc_size], sentence[max_sentence_number][max_sentence_length];
char subsentences[max_sentence_number][max_subsentence_number][max_subsentence_length];
char total_subsentence[max_subgraph][max_subsentence_length];
char all_words[max_number_of_words][max_word_length];
long all_phrase_words[max_phrase_words];
long number_of_sentences = 0, number_of_distinctwords = 1, count_subgraph = 0, count_node = 0, count_susentence = 0;
long word_count = 0, number_of_clusters = 0;
long number_of_subsentences[max_sentence_number], count_total_subsentence = 0;
long dgre[max_subgraph][max_number_of_words], total_degree[max_number_of_words];
long selected_words[max_number_of_words], count_selected = 0, number_of_phrase_words = 0;
long original_sentences[max_original_sentences];
long total_sentences_in_output[max_sentences_in_output];
long number_of_sentences_in_output = 0, summary_size;
long is_unique[10000];
map<string, int>map_stopwords;
map<string, long>map_wordfrequency;
map<string, long>map_distinctwords_one;
map<long, string>map_distinctwords_two;
map<string, long>map_degree;
vector<long>word_in_differentsentence[max_sentence_number];
vector<long>sub_graph[max_subgraph][max_words_in_a_subsentence];
vector<long>word_in_differentsubsentence[max_subgraph];
vector<long>connected_components[max_connection_per_node];
vector<long>cluster[max_key_phrase];
FILE *write;
