#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function prototypes
void menu();
void print_characters_vertically(const char *text);
void reverse_text(const char *text);
void replace_a_with_A(const char *text);
void split_words(const char *text);
void remove_spaces(const char *text);
void count_vowels(const char *text);
void typing_speed();

int main() {
    char choice;
    char text[1000];

    while (1) {
        menu();
        printf("Enter your choice (0-7): ");
        scanf(" %c", &choice);
        getchar(); // Clear the newline character from the input buffer

        if (choice == '0') {
            printf("Exiting the program...\n");
            break;
        }

        switch (choice) {
            case '1':
                printf("Enter the text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove the newline character
                print_characters_vertically(text);
                break;
            case '2':
                printf("Enter the text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                reverse_text(text);
                break;
            case '3':
                printf("Enter the text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                replace_a_with_A(text);
                break;
            case '4':
                printf("Enter the text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                split_words(text);
                break;
            case '5':
                printf("Enter the text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                remove_spaces(text);
                break;
            case '6':
                printf("Enter the text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                count_vowels(text);
                break;
            case '7':
                typing_speed();
                break;
            default:
                printf("Invalid choice! Please enter a value between 0-7.\n");
        }
    }

    return 0;
}

// Display the menu
void menu() {
    printf("\nConsole Menu\n");
    printf("1. Print characters vertically\n");
    printf("2. Reverse text\n");
    printf("3. Replace 'a' with 'A'\n");
    printf("4. Split words\n");
    printf("5. Remove spaces\n");
    printf("6. Count vowels\n");
    printf("7. Typing speed\n");
    printf("0. Exit\n");
}

// 1. Print each character of the text vertically
void print_characters_vertically(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c\n", text[i]);
    }
}

// 2. Reverse the text and reverse each word
void reverse_text(const char *text) {
    int length = strlen(text);
    char reversed[length + 1];
    char word_reversed[length + 1];
    int j = 0;

    // Reverse the entire text
    for (int i = length - 1; i >= 0; i--) {
        reversed[j++] = text[i];
    }
    reversed[j] = '\0';
    printf("Original text: %s\n", text);
    printf("Reversed text: %s\n", reversed);

    // Reverse each word
    printf("Word-by-word reversed text: ");
    const char *word_start = text;
    while (*word_start) {
        const char *word_end = word_start;
        while (*word_end && *word_end != ' ') {
            word_end++;
        }
        for (const char *p = word_end - 1; p >= word_start; p--) {
            printf("%c", *p);
        }
        if (*word_end) {
            printf(" ");
        }
        word_start = word_end + 1;
    }
    printf("\n");
}

// 3. Replace all 'a' with 'A'
void replace_a_with_A(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'a') {
            putchar('A');
        } else {
            putchar(text[i]);
        }
    }
    printf("\n");
}

// 4. Split the text into words
void split_words(const char *text) {
    char temp[1000];
    strcpy(temp, text);
    char *word = strtok(temp, " ");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
}

// 5. Remove all spaces from the text
void remove_spaces(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            putchar(text[i]);
        }
    }
    printf("\n");
}

// 6. Count the number of vowels in the text
void count_vowels(const char *text) {
    const char *vowels = "aeiouAEIOU";
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (strchr(vowels, text[i])) {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);
}

// 7. Measure typing speed
void typing_speed() {
    char input[1000];
    printf("Please type: ");
    clock_t start_time = clock();
    fgets(input, sizeof(input), stdin);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int char_count = strlen(input) - 1; // Exclude the newline character
    double chars_per_second = char_count / elapsed_time;

    printf("Your typing time: %.2f seconds\n", elapsed_time);
    printf("Characters per second: %.2f\n", chars_per_second);
}