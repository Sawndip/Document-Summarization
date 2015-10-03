#include <bits/stdc++.h>
#include "Hello.h"
#include "Final_Output.h"
#include "Key_phrase.h"
#include "Degree.h"
#include "Mapping_DifferentWords.h"
#include "Mapping_Stopwords.h"
#include "Separating_Sentences.h"
#include "Global.h"
#include "SubSentence.h"
#include "Graph_formation.h"
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
#define max_input_length 1000000
using namespace std;
char input_document[max_input_length];
extern FILE *write;
extern char document[max_doc_size];
extern long summary_size;
int main()
{
FILE *read1, *read2, *read3;
read1 = fopen("input.txt","r");
read2 = fopen("English stop words.txt","r");
read3 = fopen("Summary Size.txt","r");
//write = fopen("output.txt","w");
long total_length = 0, number_of_line = 0, i, len;

/***** Taking Inputs *******/
sf(read3, "%ld", &summary_size);
while(sf(read1, "%s", input_document) != EOF)
{
    if(number_of_line)
    {
        document[total_length] = ' ', total_length++;
    }
    len = strlen(input_document);
    for(i = 0; i < len; i++)
    {
        document[total_length] = input_document[i], total_length++;
    }
    number_of_line++;
}
    document[total_length] = NULL;
 //  cout << document << endl;


    /****** Mapping Stopwords ******/

    Mapping_Stopwords ob_stopwords;

    /***** Separating Sentences ******/

    Separating_Sentences ob_SeperatingSentence;


    /****** Mapping Distinct Words ******/
    Mapping_DifferentWords ob_distinctwords;


    /***** Separating Subsentences and Counting word frequency ******/
    SubSentence ob_subsentence;
    ob_subsentence.WordFrequency();
    ob_subsentence.WordInSubsentence();

    /********Graph Formation**********/
    Graph_formation ob_subgraph;

    /******** Determining in-degree and out-degree *********/

    Degree ob_degree;

    /**********Key Phrase *********/
    Key_phrase ob_keyphrase;
    /********Output*********/
//    Final_Output ob_output;

    /*** Closing File ***/
    fclose(read1), fclose(write), fclose(read2);
    fclose(read3);
    return 0;
}
