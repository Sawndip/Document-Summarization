#ifndef MAPPING_STOPWORDS_H
#define MAPPING_STOPWORDS_H


class Mapping_Stopwords
{
    public:
        Mapping_Stopwords();
        long len;
        char stopwords[10000], *pch;
        FILE *read2;
};

#endif // MAPPING_STOPWORDS_H
