/* Problem 97 = 8739992577 */

#include <stdio.h>
#include "../list_math.h"

int main()
{
    int answer = 0;
    struct list *prime = 0;
    char *primeString;
    
    list_power( 2, 7830457, &prime );
    list_multiply_number( prime, 28433 );
    list_add_number( prime, 1 );

    primeString = list_to_string( prime );
    
    printf( "%s\n", primeString );

    printf( "%s\n", primeString + ( strlen( primeString ) - 10 ) );

    list_free( prime );

    return 0;
}
