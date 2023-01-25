#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int solve(const int n, const int *arr){
    int longest = 1;

    // gasieniczka, ktora oznacza badany przedzial
    int front = n - 1;
    int back = n - 1;
    while(front > 0){
        // rozszerzaj przedzial w lewo poki to mozliwe
        if(arr[front - 1] != 0 && arr[back] % arr[front - 1] == 0){
            front--;
            longest = MAX(back - front + 1, longest);
        }
        else{
            // jesli przedzial ma 1 element i nie da sie go rozszerzyc to przesun cala gasieniczke
            if(front == back){
                front--;
                back--;
            } else {
                // przedzial nie jest 1 elementowy, wiec moze istnieje element,
                // ktory posiada wszystkie dzielniki elementu arr[back] i dodatkowe, ktore
                // pozwala dalej rozszerzac nasz przedzial
                int initial_back = back;
                back--;
                if(arr[initial_back] != 0){
                    while(arr[back] % arr[initial_back] != 0 && front < back)
                        back--;
                }
            }
        }
    }
    return longest;
}

int main(){
    int n = 0;
    scanf("%d", &n);

    int *arr = malloc((unsigned)n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", solve(n, arr));
    free(arr);

}
