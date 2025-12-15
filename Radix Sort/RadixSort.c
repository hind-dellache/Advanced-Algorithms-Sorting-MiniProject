void RadixSort(int T[], int n, int k) {
    // Loop over each digit from least significant to most significant
    for(int i = 0; i < k; i++) {
        SortAux(T, n, i); // sort by digit i
    }
}
