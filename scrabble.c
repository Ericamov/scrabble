#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_player_score(string word);
int get_letter_points(char letter);

int main(void)
{
    // Prompt for two words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculate each player's score
    int player1_score = calculate_player_score(player1);
    int player2_score = calculate_player_score(player2);

    // If the scores are the same, print "Tie!"
    if (player1_score == player2_score)
    {
        printf("Tie!\n");
    }
    // Otherwise, identify the winner and print it
    else
    {
        string winner = player1_score > player2_score ? "Player 1" : "Player 2";
        printf("%s wins!\n", winner);
    }
}

// Calculate the score of a given word
int calculate_player_score(string word)
{
    int player_score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Convert each letter to uppercase and add points
        word[i] = toupper(word[i]);
        player_score += get_letter_points(word[i]);
    }
    return player_score;
}

// Return the points corresponding to a given letter
int get_letter_points(char c)
{
    const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    if (isalpha(c))
    {
        int index = c - 'A';
        return POINTS[index];
    }
    // If it's not a letter return 0 points
    return 0;
}
