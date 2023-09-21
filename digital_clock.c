#include <stdio.h>
#include <time.h>
#include <windows.h>

int main(){
    int hour_hand;
    int minute_hand;
    int second_hand;
    int delay = 1000; // Delay of 1000 milliseconds
    int iterations; // Number of iterations before stopping the clock
    printf("For how many second do you want the clock to run -> ");
    scanf("%d",&iterations);
    while(1){
        printf("Enter time (HH MM SS)(12 hr format) -> ");
        scanf("%d %d %d",&hour_hand,&minute_hand,&second_hand);
        if (hour_hand > 12 || minute_hand > 59 || second_hand > 59){
            printf("Invalid input\n");
        }
        else{
            break;
        }
    }
    for (int i = 0; i < iterations; i++) {
        second_hand++;
        if (hour_hand > 12){
            hour_hand = 00;
        }
        if (minute_hand > 59){
            minute_hand = 00;
            hour_hand++; 
        }
        if (second_hand > 59){
            second_hand = 00;
            minute_hand++;
        }

        printf("\nClock : ");
        printf("\n %02d : %02d : %02d\n", hour_hand, minute_hand, second_hand); // Prints time
        Sleep(delay); // Delays clock by 1000ms making the clock behave like a real one
        system("cls"); // Clears the screen
    }   

    return 0;
}


