#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score2 < score1){
        printf("%s\n", "Player 1 wins!");
    }else if (score2 == score1){
        printf("%s\n", "Tie!");
    }else{
        printf("%s\n", "Player 2 wins!");
    }
}

int compute_score(string word)
{
    int score = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        char letter = word[i];
        if (isupper(letter)) {
            score += POINTS[letter - 'A'];
        } else if (islower(letter)) {
            score += POINTS[letter - 'a'];
        }
    }
    return score;
}