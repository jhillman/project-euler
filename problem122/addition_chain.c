/* Problem 122 = 1582 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include "../list.h"

struct tree_node
{
    int value;
    int layer;
    struct tree_node *parent;
    struct list *children;
    struct node *current;
};

int tree_contains_child( struct tree_node *tree_node, int value )
{
    struct node *childNode;
    int contains = 0;

    if ( tree_node->children )
    {
        childNode = tree_node->children->first;

        while ( !contains && childNode )
        {
            contains = ( ( (struct tree_node *)(int)childNode->value )->value == value );
            childNode = childNode->next;
        }
    }

    return contains;
}

void tree_add_child( struct tree_node *tree_node, int value, struct tree_node *parent, int layer )
{
    struct tree_node *child = (struct tree_node *)calloc( 1, sizeof( struct tree_node ) );
    child->value = value;
    child->layer = layer;
    child->parent = parent;

    if ( !tree_node->children )
    {
        tree_node->children = list_new();
    }

    list_push( tree_node->children, (int)child );

    tree_node->current = tree_node->children->last;
}

struct tree_node *tree_first_child( struct tree_node *tree_node )
{
    struct tree_node *first = (struct tree_node *)(int)tree_node->children->first->value;

    tree_node->current = tree_node->children->first;

    return first;
}

struct tree_node *tree_next_child( struct tree_node *tree_node )
{
    struct tree_node *next = 0;

    if ( tree_node->parent )
    {
        tree_node->parent->current = tree_node->parent->current->next;

        if ( tree_node->parent->current )
        {
            next = (struct tree_node *)(int)tree_node->parent->current->value;
        }
    }

    return next;
}

void tree_free( struct tree_node *tree_node )
{
    struct node *childNode;

    if ( tree_node->children )
    {
        childNode = tree_node->children->first;

        while ( childNode )
        {
            tree_free( (struct tree_node *)(int)childNode->value );

            free( (struct tree_node *)(int)childNode->value );

            childNode = childNode->next;
        }
    }

    list_free( tree_node->children );
}

int get_minimum_chain_length( int number )
{
    int minimum = 0;
    int ones = 0;
    double logn = log( number ) / log( 2 );

    while ( number )
    {
        if ( number & 1 )
        {
            ++ones;
        }

        number >>= 1;
    }

    minimum = (int)( logn + ( log( ones ) / log( 2 ) ) - 2.13 );

    return minimum;
}

int get_maximum_chain_length( int number )
{
    int maximum = number;
    int ones = 0;
    double logn = log( number ) / log( 2 );

    while ( number )
    {
        if ( number & 1 )
        {
            ++ones;
        }

        number >>= 1;
    }

    maximum = (int)logn + ones - 1;

    return maximum;
}

int get_minimum( int layer, int number, int maximumChainLength )
{
    int value = number;
    int length = maximumChainLength;

    if ( length < layer )
    {
        value = 0;
    }
    else
    {
        while ( length > layer )
        {
            value = (int)( ( value + 1 ) / 2 );
            --length;
        }
    }

    return value;
}

int get_minimal_addition_chain( int number )
{
    /* http://en.wikipedia.org/wiki/Addition_chain */
    /* http://www.few.vu.nl/~skn410/bp/AdditionChains.pdf */

    struct tree_node *tree = (struct tree_node *)calloc( 1, sizeof( struct tree_node ) );
    struct tree_node *current = tree;
    struct tree_node *one = tree;
    struct tree_node *two = tree;
    struct tree_node *final = 0;
    int currentLayer = 1;
    int found = 0;
    int nodeAdded;
    int numberAdded = 0;
    int value;
    int minimumChainLength = get_minimum_chain_length( number ) + 1;
    int maximumChainLength = get_maximum_chain_length( number );
    int a;
    int b;
    int c;
    int d;
    int minimum;
    int minimal;

    tree->value = 1;
    tree->layer = 0;

    while ( !found && current )
    {
        while ( !numberAdded && current )
        {
            nodeAdded = 0;
            one = two = 0;

            for ( a = currentLayer; a >= 0; a-- )
            {
                one = current;

                for ( b = a; b > 1; b-- )
                {
                    one = one->parent;
                }

                for ( d = a; d >= 0; d-- )
                {
                    two = current;

                    for ( c = d; c > 1; c-- )
                    {
                        two = two->parent;
                    }

                    value = one->value + two->value;
                    
                    minimum = get_minimum( currentLayer, number, maximumChainLength );

                    if ( value <= number && value > current->value && !tree_contains_child( current, value ) )
                    {
                        if ( minimum <= value )
                        {
                            tree_add_child( current, value, current, currentLayer );

                            if ( value == number )
                            {
                                numberAdded = 1;
                            }

                            nodeAdded = 1;
                        }
                    }
                }
            }
            
            if ( nodeAdded )
            {
                current = tree_first_child( current );
                
                ++currentLayer;

                if ( current->layer > maximumChainLength )
                {
                    do
                    {
                        current = current->parent;

                        --currentLayer;
                    }
                    while ( current->parent && current == (struct tree_node *)(int)current->parent->children->last->value );

                    if ( current->parent )
                    {
                        current = tree_next_child( current );
                    }
                    else
                    {
                        current = 0;
                    }
                }
            }
            else
            {
                if ( current->parent && current == (struct tree_node *)(int)current->parent->children->last->value )
                {
                    do
                    {
                        current = current->parent;

                        --currentLayer;
                    }
                    while ( current->parent && current == (struct tree_node *)(int)current->parent->children->last->value );

                    if ( current->parent )
                    {
                        current = tree_next_child( current );
                    }
                    else
                    {
                        current = 0;
                    }
                }
                else
                {
                    current = tree_next_child( current );
                }
            }
        }

        if ( numberAdded )
        {
            maximumChainLength = current->layer;
            final = current;

            numberAdded = 0;

            if ( maximumChainLength == minimumChainLength )
            {
                found = 1;
            }

            do
            {
                current = current->parent;

                --currentLayer;
            }
            while ( current->parent && current == (struct tree_node *)(int)current->parent->children->last->value );

            if ( current->parent )
            {
                current = tree_next_child( current );
            }
            else
            {
                current = 0;
            }
        }
    }

    minimal = final->layer;

    tree_free( tree );

    return minimal;
}

int main()
{
    int number;
    int chain;
    int answer = 0;

    for ( number = 2; number <= 200; number++ )
    {
        chain = get_minimal_addition_chain( number );
        
        printf( "%d\n", chain );
        
        answer += chain;
    }
    
    printf( "%d", answer );

    return 0;
}
