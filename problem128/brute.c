/* Problem 128 = 14516824220 */

#include <stdio.h>
#include <stdlib.h>
#include "../list.h"
#include "../algorithms.h"

struct tile
{
    long long number;
    struct tile *neighbors[6];
    int ring;
    int pd;
};

void set_neighbors( struct tile *tile, int index )
{
    int first;
    int second;

    /*
    0 = 1[5], 5[1]
    1 = 0[2], 2[0]
    2 = 1[3], 3[1]
    3 = 2[4], 4[2]
    4 = 3[5], 5[3]
    5 = 0[4], 4[0]
    */
    if ( index == 0 )
    {
        first = 5;
        second = 1;
    }
    else if ( index == 5 )
    {
        first = 4;
        second = 0;
    }
    else
    {
        first = index - 1;
        second = index + 1;
    }

    if ( tile->neighbors[first] )
    {
        if ( tile->neighbors[first]->neighbors[second] && tile->neighbors[first]->neighbors[second] != tile->neighbors[index] )
        {
            free( tile->neighbors[first]->neighbors[second] );
        }

        tile->neighbors[first]->neighbors[second] = tile->neighbors[index];
    }

    if ( tile->neighbors[second] )
    {
        if ( tile->neighbors[second]->neighbors[first] && tile->neighbors[second]->neighbors[first] != tile->neighbors[index] )
        {
            free( tile->neighbors[second]->neighbors[first] );
        }

        tile->neighbors[second]->neighbors[first] = tile->neighbors[index];
    }
}

int tile_neighbor( struct tile *tile, struct tile *possibleNeighbor )
{
    int neighbor = 0;
    int i;

    for ( i = 0; !neighbor && i < 6; i++ )
    {
        neighbor = ( tile->neighbors[i] == possibleNeighbor );
    }

    return neighbor;
}

void generate_pd( struct tile *tile )
{
    long long difference;
    int i;

    for ( i = 0; i < 6; i++ )
    {
        if ( tile->neighbors[i]->number )
        {
            difference = (long long)abs( (double)( tile->neighbors[i]->number - tile->number ) );
            tile->pd += is_prime( difference );
        }
        else
        {
            tile->pd = 0;
            break;
        }
    }
}

int main()
{
    struct tile *current;
    struct tile *top;
    struct list *tiles = list_new();
    struct node *currentNode;
    struct node *pdNode;
    struct node *freeNode;
    int pd3Count = 0;
    int i;
    int j;
    int topTile;
    long long number = 1;
    struct node *topNode;
    int ring = 0;
    long long answer = 0;

    current = (struct tile *)calloc( 1, sizeof( struct tile ) );
    list_push( tiles, (long long)current );

    current->number = number++;

    for ( j = 0; j < 6; j++ )
    {
        current->neighbors[j] = (struct tile *)calloc( 1, sizeof( struct tile ) );

        current->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] = current;
    }            

    freeNode = pdNode = currentNode = tiles->first;
    current = (struct tile *)currentNode->value;
    top = current;
    topTile = 1;
    topNode = 0;
    ++ring;

    while ( !answer )
    {
        for ( i = ( topNode && current->number == ( (struct tile *)topNode->value )->number ? 1 : 0 ); i < 6; i++ )
        {
            if ( !current->neighbors[i]->number )
            {
                if ( i < ( topTile ? 5 : 6 ) )
                {
                    for ( j = 0; j < 6; j++ )
                    {
                        if ( !current->neighbors[i]->neighbors[j] )
                        {
                            current->neighbors[i]->neighbors[j] = (struct tile *)calloc( 1, sizeof( struct tile ) );
                        }

                        if ( current->neighbors[i]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] && current->neighbors[i]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] != current->neighbors[i] )
                        {
                            free( current->neighbors[i]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] );
                        }

                        current->neighbors[i]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] = current->neighbors[i];
                    }            

                    if ( !topNode || ( (struct tile *)topNode->value )->number == 7 || !tile_neighbor( (struct tile *)currentNode->next->value, current->neighbors[i] ) )
                    {
                        current->neighbors[i]->number = number++;
                        current->neighbors[i]->ring = ring;

                        list_push( tiles, (long long)current->neighbors[i] );
                    }
                }
            }
                
            /*
            0 = 3
            1 = 4
            2 = 5
            3 = 0
            4 = 1
            5 = 2
            */
            if ( current->neighbors[i]->neighbors[i >= 3 ? i - 3 : i + 3] && current->neighbors[i]->neighbors[i >= 3 ? i - 3 : i + 3] != current )
            {
                free( current->neighbors[i]->neighbors[i >= 3 ? i - 3 : i + 3] );
            }

            current->neighbors[i]->neighbors[i >= 3 ? i - 3 : i + 3] = current;

            set_neighbors( current, i );
        }

        topTile = 0;
        currentNode = currentNode->next;
        current = (struct tile *)currentNode->value;

        if ( !topNode || current->number > ( (struct tile *)topNode->value )->number )
        {
            top->neighbors[5]->number = number++;
            top->neighbors[5]->ring = ring;

            for ( j = 0; j < 6; j++ )
            {
                if ( !top->neighbors[5]->neighbors[j] )
                {
                    top->neighbors[5]->neighbors[j] = (struct tile *)calloc( 1, sizeof( struct tile ) );
                }

                if ( top->neighbors[5]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] && top->neighbors[5]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] != top->neighbors[5] )
                {
                    free( top->neighbors[5]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] );
                }

                top->neighbors[5]->neighbors[j]->neighbors[j >= 3 ? j - 3 : j + 3] = top->neighbors[5];
            }            

            list_push( tiles, (long long)top->neighbors[5] );
            
            while ( topNode )
            {   
                for ( j = 0; j < 6; j++ )
                {
                    if ( ( (struct tile *)topNode->value )->neighbors[j] )
                    {
                        set_neighbors( ( (struct tile *)topNode->value )->neighbors[j], j );
                    }
                }

                topNode = topNode->next;
            }
            
            top = current;
            topNode = tiles->last;
            topTile = 1;
            ++ring;

            while ( ( (struct tile *)pdNode->value )->ring < ring - 1 )
            {
                generate_pd( (struct tile *)pdNode->value );

                if ( ( (struct tile *)pdNode->value )->pd == 3 )
                {
                    if ( ++pd3Count == 2000 )
                    {
                        answer = ( (struct tile *)pdNode->value )->number;
                    }

                    /* printf( "%d: %lld\n", pd3Count, ( (struct tile *)pdNode->value )->number ); */
                }

                pdNode = pdNode->next;
            }

            while ( ( (struct tile *)tiles->first->value )->ring < ring - 3 )
            {
                free( (struct tile *)list_pop_front( tiles ) );
            }
        }
    }

    currentNode = tiles->first;

    while ( currentNode )
    {   
        for ( j = 0; j < 6; j++ )
        {
            if ( !( (struct tile *)currentNode->value )->neighbors[j]->number && 
                 currentNode != tiles->last && 
                 !tile_neighbor( ( (struct tile *)currentNode->previous->value ), ( (struct tile *)currentNode->value )->neighbors[j] ) &&
                 !tile_neighbor( ( (struct tile *)currentNode->next->value ), ( (struct tile *)currentNode->value )->neighbors[j] ) )
            {
                free( ( (struct tile *)currentNode->value )->neighbors[j] );
            }
        }

        currentNode = currentNode->next;
    }

    currentNode = tiles->first;

    while ( currentNode )
    {   
        free( (struct tile *)currentNode->value );

        currentNode = currentNode->next;
    }

    list_free( tiles );
    
    printf( "%lld", answer );

    return 0;
}
