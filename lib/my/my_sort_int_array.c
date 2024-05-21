/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

void insert(int *array2, int nbr, int size, int size_max)
{
    int temp;

    for (int i = 0; i < size_max; i++){
        if (i == size){
            array2[size] = nbr;
        }
        if (nbr < array2[i]){
            temp = array2[i];
            array2[i] = nbr;
            nbr = temp;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int array2[size];

    for (int i = 0; i < size; i++){
        insert(array2, array[i], i, size);
    }
    for (int i = 0; i < size; i++){
        array[i] = array2[i];
    }
}
