#include <stdio.h>
void towers(int disc, char frompeg, char topeg, char auxpeg){
    if (disc== 1){
        printf("\nMove disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }
    towers(disc - 1, frompeg, auxpeg, topeg);
    printf("\nMove disk %d from peg %c to peg %c",disc, frompeg, topeg);
    towers(disc - 1, auxpeg, topeg, frompeg);
}
int main(){
    int disc;
    printf("Enter the number of disks\n");
    scanf("%d", &disc);
    printf("The sequence of moving discs is as follows :\n");
    towers(disc, 'A', 'C', 'B');
    return 0;
}