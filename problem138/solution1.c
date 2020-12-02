/* Problem 138 */

#include <stdio.h>
#include "../list_math.h"

int main()
{
    struct list *base = list_from_number( 16 );
    struct list *height;
    struct list *half_base = list_from_number( 8 );
    struct list *half_base_squared = 0;
    struct list *height_squared = 0;
    struct list *sum;
    int square;
    struct list *legs = 0;
    int  count = 0;
    struct list* answer = list_from_number( 0 );
    
    while ( count < 12 )
    {
        height = list_copy( base );
        list_subtract_number( height, 1 );
        
        list_multiply_list( half_base, half_base, &half_base_squared );
        list_multiply_list( height, height, &height_squared );

        sum = list_copy( half_base_squared );
        list_add_list( sum, height_squared );

        square = list_sqrt( sum, &legs );
        
        if ( square )
        {
            list_add_list( answer, legs );
            
            ++count;
            
            printf( "base: " );
            list_print( base );
            printf( "height: " );
            list_print( height );
            printf( "legs: " );
            list_print( legs );
        }
        
        list_free( half_base_squared );
        half_base_squared = 0;
        list_free( height_squared );
        height_squared = 0;
        list_free( sum );
        list_free( legs );
        legs = 0;
        
        list_add_number( height, 2 );
        
        list_multiply_list( half_base, half_base, &half_base_squared );
        list_multiply_list( height, height, &height_squared );
        
        sum = list_copy( half_base_squared );
        list_add_list( sum, height_squared );
        
        square = list_sqrt( sum, &legs );
        
        if ( square )
        {
            list_add_list( answer, legs );
            
            ++count;
            
            printf( "base: " );
            list_print( base );
            printf( "height: " );
            list_print( height );
            printf( "legs: " );
            list_print( legs );
        }
        
        list_free( half_base_squared );
        half_base_squared = 0;
        list_free( height_squared );
        height_squared = 0;
        list_free( sum );
        list_free( legs );
        legs = 0;
        
        list_add_number( base, 2 );
        list_add_number( half_base, 1 );
    }
    
    list_free( base );
    list_free( half_base );

    list_print( answer );
    
    list_free( answer );

    return 0;
}

/*
base: 16, height: 15, legs: 17.000000
base: 272, height: 273, legs: 305.000000
base: 4896, height: 4895, legs: 5473.000000
base: 87840, height: 87841, legs: 98209.000000
base: 1576240, height: 1576239, legs: 1762289.000000
base: 28284464, height: 28284465, legs: 31622993.000000
base: 91530450, height: 91530451, legs: 102334155.000000
base: 154776436, height: 154776437, legs: 173045317.000000
base: 176383846, height: 176383845, legs: 197203134.000000
base: 218022422, height: 218022423, legs: 243756479.000000
base: 239629832, height: 239629831, legs: 267914296.000000
base: 281268408, height: 281268409, legs: 314467641.000000
1332210308
*/
