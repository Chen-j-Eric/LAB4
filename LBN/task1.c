#include <stdio.h>
#include <stdbool.h>

const int TD2 = 8; // Touchdown + 2-point conversion
const int TD1 = 7; // Touchdown + 1-point extra point
const int TD  = 6; // Touchdown (no extra point / missed)
const int FG  = 3; // Field Goal
const int SF  = 2; // Safety

int main() {
    int score;

    while (true) {
        printf("Enter score (1 to quit): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
            continue;
        }

        if (score == 1) {
            break; // quit signal
        }

        if (score < 0) {
            printf("Invalid input. Score cannot be negative.\n");
            continue;
        }

        printf("Combinations for score %d:\n", score);

        bool found = false;

        for (int td2 = 0; td2 <= score / TD2; td2++) {
            for (int td1 = 0; td1 <= score / TD1; td1++) {
                for (int td = 0; td <= score / TD; td++) {
                    for (int fg = 0; fg <= score / FG; fg++) {
                        for (int sf = 0; sf <= score / SF; sf++) {

                            int total = (td2 * TD2)
                                      + (td1 * TD1)
                                      + (td * TD)
                                      + (fg * FG)
                                      + (sf * SF);

                            if (total == score) {
                                printf("%d TD+2pt, %d TD+1pt, %d TD, %d FG, %d Safety\n",
                                       td2, td1, td, fg, sf);
                                found = true;
                            }
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No valid combination exists for this score.\n");
        }

        printf("\n");
    }

    return 0;
}
