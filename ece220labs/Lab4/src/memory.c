#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

static long long totalMemory = 0;
static long long maxMemory = 0;
static long long calls = 0;

void* safe_malloc(size_t size) {
    void* tmp = malloc(size + 8);
    *((long long*)tmp) = size;
    totalMemory += size;
    if (totalMemory > maxMemory) {
        maxMemory = totalMemory;
    }
    fprintf(stdout, "{%3lld} ", calls);
    fprintf(stdout, "Alocated %4lld bytes | ", *((long long*)tmp));
    fprintf(stdout, "Current Memory Usage: %4lld bytes | ", totalMemory);
    fprintf(stdout, "Max Memory Usage: %4lld bytes\n", maxMemory);
    calls++;
    return ((long long*)tmp) + 1;
}

void safe_free(void* ptr) {
    totalMemory -= *(((long long*)ptr) - 1);
    fprintf(stdout, "{%3lld}", calls);
    fprintf(stdout, " Freed    %4lld bytes | ", *(((long long*)ptr) - 1));
    fprintf(stdout, "Current Memory Usage: %4lld bytes | ", totalMemory);
    fprintf(stdout, "Max Memory Usage: %4lld bytes\n", maxMemory);
    calls++;
    free((((long long*)ptr) - 1));
}