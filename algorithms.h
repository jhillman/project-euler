#include <string.h>
#include <math.h>
#include "list.h"

long long previous_palindrome(long long palindrome) {
    int digits;
    int middle;
    int position;
    int place;
    long long holder;
    int left;
    int right;
    digits = (int)floor(log10((double)palindrome)) + 1;
    middle = (int)floor(digits / 2);
    position = middle;
    place = (int)pow(10, position);
    palindrome = palindrome - (palindrome % place);

    if (palindrome == place) {
        --palindrome;
    } else {
        palindrome -= place;
        holder = palindrome;
        digits = (int)floor(log10((double)palindrome)) + 1;
        position = digits;
        left = (int)pow(10, position);
        right = (int)pow(10, abs(position - digits));

        while (position >= middle && left != right) {
            palindrome += (long long)floor((double)holder / left) * right;
            holder = holder % left;
            --position;
            left = (int)pow(10, position);
            right = (int)pow(10, abs(position - digits + 1));
        }
    }

    return palindrome;
}

struct list *prime_factors(long long number) {
    struct list *factors = list_new();
    long long maximum = number;
    long long possible = 2;

    while (possible * possible <= maximum) {
        if (maximum % possible == 0) {
            if (!list_find(factors, possible)) {
                list_push(factors, possible);
            }

            maximum /= possible;
        } else {
            ++possible;
        }
    }

    if (!list_find(factors, maximum)) {
        list_push(factors, maximum);
    }

    return factors;
}

int is_prime(long long number) {
    int prime = 1;
    long long squareRoot;
    long long i;

    if ((number % 2 == 0 && number != 2) || number == 1) {
        prime = 0;
    } else {
        squareRoot = (long long)sqrt((double)number);

        for (i = 3; prime && i <= squareRoot; i += 2) {
            if (number % i == 0) {
                prime = 0;
            }
        }
    }

    return prime;
}

void sieve_primes(char *sieve, long long size) {
    long long squareRoot = (long long)sqrt((double)size);
    long long i;
    long long j;

    sieve[0] = sieve[1] = 1;

    for (i = 2; i <= squareRoot; i++) {
        if (!sieve[i]) {
            for (j = i * i; j < size; j += i) {
                sieve[j] = 1;
            }
        }
    }
}

long long get_combinations(long long sum, struct list *amounts) {
    long long combinations = 0;
    struct list *newAmounts;
    long long largest;
    long long i;

    if (amounts->length == 1) {
        combinations = (sum % amounts->first->value == 0) ? 1 : 0;
    } else {
        largest = list_pop(amounts);

        for (i = 0; i <= sum / largest; i++) {
            newAmounts = list_copy(amounts);
            combinations += get_combinations(sum - (i * largest), newAmounts);
            list_free(newAmounts);
        }
    }

    return combinations;
}

int partition(int n) {
    static int *cache = 0;
    int freeCache = 0;
    int k;
    int partitionsOne;
    int partitionsTwo;
    int partitions = 0;

    if (!cache) {
        cache = (int *)calloc(n + 1, sizeof(int));
        cache[0] = 1;
        freeCache = 1;
    }

    if (n < 0) {
        partitions = 0;
    } else {
        if (cache[n] > 0) {
            partitions = cache[n];
        } else {
            for (k = 1; k <= n; k++) {
                partitionsOne = partition(n - k * (3 * k - 1) / 2);
                partitionsTwo = partition(n - k * (3 * k + 1) / 2);

                if (k % 2 == 1) {
                    partitions += partitionsOne;
                    partitions += partitionsTwo;
                } else {
                    partitions -= partitionsOne;
                    partitions -= partitionsTwo;
                }
            }

            cache[n] = partitions;
        }
    }

    if (freeCache) {
        free(cache);
        cache = 0;
    }

    return partitions;
}

/* Donald Knuth's "Algorithm L" */
/* The Art of Computer Programming, Volume 4, Fascicle 2: Generating All Tuples and Permutations */

char *reverse_string(char *string) {
    char *start = string;
    char *end = start + strlen(string) - 1;
    char character;

    while (start < end) {
        character = *start;
        *start = *end;
        *end = character;
        ++start;
        --end;
    }

    return string;
}

int next_permutation(char *sequence, int length) {
    int j;
    int m;
    char digit;
    j = length - 2;

    while (j >= 0 && sequence[j] >= sequence[j + 1]) {
        --j;
    }

    if (j < 0) {
        return 0;
    }

    m = length - 1;

    while (sequence[j] >= sequence[m]) {
        --m;
    }

    digit = sequence[j];
    sequence[j] = sequence[m];
    sequence[m] = digit;

    reverse_string(sequence + j + 1);

    return 1;
}

int previous_permutation(char *sequence, int length) {
    int j;
    int m;
    char digit;
    j = length - 2;

    while (j >= 0 && sequence[j] <= sequence[j + 1]) {
        --j;
    }

    if (j < 0) {
        return 0;
    }

    m = length - 1;

    while (sequence[j] <= sequence[m]) {
        --m;
    }

    digit = sequence[j];
    sequence[j] = sequence[m];
    sequence[m] = digit;

    reverse_string(sequence + j + 1);

    return 1;
}

int count_digits(long long number) {
    return (int)floor(log10((double)number)) + 1;
}

int count_digits_for_base(long long number, int base) {
    return (int)floor(log((double)number) / log(base)) + 1;
}

char *integer_to_ascii(long long number, char *buffer, int base) {
    char *ptr = buffer;

    while (number) {
        *ptr = '0' + (char)(number % base);
        ++ptr;
        number /= base;
    }

    *ptr = 0;

    reverse_string(buffer);

    return buffer;
}

long long count_divisors(int number) {
    struct list *factors = prime_factors(number);
    struct node *factor;
    int power;
    long long product;
    int divisors = 1;

    /* divisor function */
    /* http://en.wikipedia.org/wiki/Divisor_function */
    factor = factors->first;

    while (factor) {
        power = 1;
        product = factor->value * factor->value;

        while (number % product == 0) {
            ++power;
            product *= factor->value;
        }

        divisors *= (power + 1);
        factor = factor->next;
    }

    list_free(factors);

    return divisors;
}

/* http://en.wikipedia.org/wiki/Modular_exponentiation */
long long modulus_power(long long base, int exponent, int modulus) {
    long long result = 1;

    do {
        if (exponent & 0x1) {
            result *= base;
            result %= modulus;
        }

        base *= base;
        base %= modulus;
        exponent >>= 1;
    } while (exponent);

    return result;
}

int gcd(int a, int b) {
    int c;

    while (b) {
        c = b;
        b = a % b;
        a = c;
    }

    return a;
}