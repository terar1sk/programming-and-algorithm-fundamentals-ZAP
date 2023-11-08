#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int bank_notes(const int price);
//int euler(const int n);
int find_missing_number(const int n, const int arr[]);
unsigned long sum_squared(const int line);
int array_min(const int input_array[], const int array_size);
int array_max(const int input_array[], const int array_size);
int factorize_count(const int n);
void podium(const int n, int arr[]);

int main() {

    return 0;
}

//First
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    return round((100.0 * stick_length * human_weight) /(human_weight + car_weight))/100.0;
}

//Second
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
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
    while(remain > 0){
        if(remain >= naminal[con]){
            remain -= naminal[con];
            count++;
        }
        else{
            con++;
        }
        if(con == 5){
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
    for(int count = 0; count < n; count++){
        sum_mas += arr[count];
    }

    return sum - sum_mas;
}

//Sixth
unsigned long sum_squared(const int line){
    unsigned long trian[line + 1][line + 1];
    for(int count = 0; count <= line; count++){
        trian[count][0] = trian[count][count] = 1;
        for(int pil = 1; pil < count; pil++){
            trian[count][pil] = trian[count - 1][pil - 1] + trian[count - 1][pil];
        }
    }

    unsigned long sum = 0;
    for(int kef = 0; kef <= line; kef++){
        sum += trian[line][kef] * trian[line][kef];
    }
    return sum;
}

//Seventh
int array_min(const int input_array[], const int array_size){
    if(input_array == NULL || array_size <= 0){
        return -1;
    }

    int min = input_array[0];
    for(int i = 1; i < array_size; i++){
        if(input_array[i] < min){
            min = input_array[i];
        }
    }

    return min;
}

int array_max(const int input_array[], const int array_size){
    if(input_array == NULL || array_size <= 0){
        return -1;
    }

    int max = input_array[0];
    for(int i = 1; i < array_size; i++){
        if(input_array[i] > max){
            max = input_array[i];
        }
    }

    return max;
}

//Eighth

//Ninth
void podium(const int n, int arr[]){
    if(n < 3){
        for(int i = 0; i < 3; i++){
            arr[i] = n;
        }
    }
    else{
        arr[0] = n / 2 - 1;
        arr[2] = n - arr[0];
        arr[1] = arr[0] / 2;
    }
}
