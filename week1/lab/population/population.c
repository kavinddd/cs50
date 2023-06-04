#include <cs50.h>
#include <stdio.h>
int get_size(string text);
int cal_n_year_to_reach(int start_year, int end_year);
int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_size("Start");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_size("End");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int n_year = cal_n_year_to_reach(start_size, end_size);
    // TODO: Print number of years
    printf("Years: %i\n", n_year);
}

int get_size(string text)
{
    int size = get_float("%s size: ", text);
    return size;
}

int cal_n_year_to_reach(int start_size, int end_size)
{
    int n_year = 0;
    int new_population;
    int lost_population;
    while (start_size < end_size)
    {
        new_population = start_size / 3;
        lost_population = start_size / 4;
        start_size = start_size + new_population - lost_population;
        n_year++;
    }
    return n_year;
}