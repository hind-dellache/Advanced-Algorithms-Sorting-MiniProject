// Returns the digit i of an integer x
int key(int x, int i) {
    int divisor = 1;
    for(int j = 0; j < i; j++) {
        divisor *= 10;
    }
    return (x / divisor) % 10;
}
