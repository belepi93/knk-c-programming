#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int departure_arr[8] = {
        8 * 60,
        9 * 60 + 43,
        11 * 60 + 19,
        12 * 60 + 47,
        14 * 60,
        15 * 60 + 45,
        19 * 60,
        21 * 60 + 45
    };
    
    int arrival_arr[8] = {
        10 * 60 + 16,
        11 * 60 + 52,
        13 * 60 + 31,
        15 * 60,
        16 * 60 + 8,
        17 * 60 + 55,
        21 * 60 + 20,
        23 * 60 + 58
    };
    
    int i, closest_idx, closest,
        input_hour, input_minute, input_time,
        out_a_hour, out_a_minute,
        out_d_hour, out_d_minute;
        
    char out_a_ampm, out_d_ampm;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &input_hour, &input_minute);
    
    input_time = input_hour * 60 + input_minute * 1;
    
    closest = 24 * 60;
    for (i = 0; i < 8; i++) {
        if (abs(input_time - departure_arr[i]) < closest) {
            closest = abs(input_time - departure_arr[i]);
            closest_idx = i;
        }
    }
    
    out_d_hour = departure_arr[closest_idx] / 60;
    out_d_minute = departure_arr[closest_idx] % 60;
    out_d_ampm = out_d_hour >= 12 ? 'p' : 'a';
    out_a_hour = arrival_arr[closest_idx] / 60;
    out_a_minute = arrival_arr[closest_idx] % 60;
    out_a_ampm = out_a_hour >= 12 ? 'p' : 'a';
    
    if (out_d_hour >= 13)
        out_d_hour -= 12;
    if (out_a_hour >= 13)
        out_a_hour -= 12;
    
    printf("Closest departure time is %2d:%.2d %c.m., arriving at %2d:%.2d %c.m.\n",
           out_d_hour, out_d_minute, out_d_ampm,
           out_a_hour, out_a_minute, out_a_ampm);
    
    return 0;
}
