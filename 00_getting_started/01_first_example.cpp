#include <iostream>
#include <seqan/file.h>
#include <seqan/sequence.h>

using namespace seqan;

int computeLocalScore(String<char> const & subText, String<char> const & pattern)
{
    int localScore = 0;
    for (unsigned i = 0; i < length(pattern); ++i)
        if (subText[i] == pattern[i])
            ++localScore;
    
    return localScore;
}


String<int> computeScore(String<char> const & text, String<char> const & pattern)
{
    String<int> score;
    resize(score, length(text) - length(pattern) + 1);
    
    for (unsigned i = 0; i < length(score); ++i){
        score[i] = computeLocalScore(infix(text, i, i + length(pattern)), pattern);
    }
    
    return score;
}



void print(String<int> const & score)
{
    for (unsigned i = 0; i < length(score); ++i)
        std::cout << score[i] << " ";
    std::cout << std::endl;
    
}

int main()
{
    // Initialize
    String<char> text = "This is an awesome tutorial to get to know SeqAn!";
    String<char> pattern = "tutorial";
    
    // Compute
    String<int> score = computeScore(text, pattern);
    
    
    // Print the results
    printScore(score);
    
    return 0;
}
