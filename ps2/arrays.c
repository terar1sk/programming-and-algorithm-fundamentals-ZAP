#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int bank_notes(const int price);
//int euler(const int n);
int find_missing_number(const int n, const int arr[]);
unsigned long sum_squared(const int line);

int main() {

/*
    printf("%d\n", euler(6));
    // prints: 2
    printf("%d\n", euler(12));
    // prints: 4
*/


    return 0;
}

//First
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return round((100.0 * stick_length * human_weight) /(human_weight + car_weight))/100.0;
}

//Second
float unit_price(const float pack_price, const int rolls_count, const int pieces_count) {
    int total = rolls_count * pieces_count;
    float price = pack_price / total * 100;
    price = roundf(price * 100) / 100;
    return price;
}

//Third
int bank_notes(const int price){
    int naminal[] = {200, 100, 50, 20, 10};
    int count = 0;
    int remain = price;

    int con = 0;
    while (remain > 0) {
    if (remain >= naminal[con]) {
        remain -= naminal[con];
        count++;
    } else {
        con++;
    }
    if (con == 5) {
        return -1;
    }
    }
    return count;
}

//Fourth
//int euler(const int n){}

//Fifth
int find_missing_number(const int n, const int arr[]){
    int sum = (n * (n + 1))/2;

    int sum_mas = 0;
    for (int count = 0; count < n; count++){
        sum_mas += arr[count];
    }

    return sum - sum_mas;
}

//Sixth
unsigned long sum_squared(const int line) {
    unsigned long trian[line + 1][line + 1];
    for (int count = 0; count <= line; count++){
        trian[count][0] = trian[count][count] = 1;
        for (int pil = 1; pil < count; pil++) {
            trian[count][pil] = trian[count - 1][pil - 1] + trian[count - 1][pil];
        }
    }

    unsigned long sum = 0;
    for (int kef = 0; kef <= line; kef++) {
        sum += trian[line][kef] * trian[line][kef];
    }
    return sum;
}

