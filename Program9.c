#include<stdio.h>

int main() {
    int w, i, f, frames[50];
    printf("Enter the window size.\n");
    scanf("%d", &w);
    printf("Enter the number of frames to transmit.\n");
    scanf("%d", &f);
    printf("Enter %d frames.\n", f);
    for(i = 1; i <= f; i++)
        scanf("%d", &frames[i]);
    printf("With sliding window protocol, the frames will be sent in the following manner (assuming no corruption of frames).\n");
    printf("After sending %d frames at each stage, sender waits for acknowlegement sent by the receiver.\n", w);
    for(i = 1; i <= f; i++){
        if(i%w == 0) {
            printf("%d\n", frames[i]);
            printf("Acknowledgement of above frames sent is received by the sender.\n");
        }
        else 
            printf("%d\n", frames[i]);
    }
    if(f%w != 0)
        printf("Acknowledgement of above frames send is received by sender.\n");
    return 0;
}