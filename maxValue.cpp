// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: May 22, 2025
// Program that generates a random list of random numbers.
// It then displays the biggest value the in the list. [using a function]

#include <cstdio>
#include <iostream>
#include <random>
#include <array>

// Function that returns the biggest value in an array of integers
template <size_t N>
int FindMaxValue(std::array<int, N> targetList) {
    // Initialize a variable to hold the biggest number
    int currentHighestValue = targetList[0];
    // Loop through every position in the array
    for (int index = 0; index < targetList.size(); index++) {
        // Check if the number is bigger than the current highest value
        if (targetList[index] > currentHighestValue) {
            // If so, the number becomes the new current highest value
            currentHighestValue = targetList[index];
        }
    }
    // Return the value that survived
    return currentHighestValue;
}

int main() {
    // DECLARE CONSTANTS
    const int MAX_ARRAY_SIZE = 10;
    const int MIN_NUM = 0;
    const int MAX_NUM = 100;
    // Initialize an empty array
    std::array<int, MAX_ARRAY_SIZE> listOfInt;
    // RANDOM SEED
    std::random_device seed;
    // MERSENNE TWISTER
    std::mt19937 mt(seed());
    // Distribution that will return a random number between
    // MIN_NUM AND MAX_NUM [INCLUSIVE] when called with the mersenne twister.
    std::uniform_int_distribution<int> GenerateRandNum(MIN_NUM, MAX_NUM);
    // Fill the list up with random numbers
    for (int index = 0; index < MAX_ARRAY_SIZE; index++) {
        // Generate a random integer between MIN_NUM AND MAX_NUM
        int randomNumber = GenerateRandNum(mt);
        // Place the random number inside the array
        listOfInt[index] = randomNumber;
        // Display the list operation
        printf("%i added to the list at position %i.\n", randomNumber, index);
    }

    // Call FindMaxValue()
    int biggestValue = FindMaxValue(listOfInt);
    // Display the max value
    printf("\nThe max value is %i\n", biggestValue);
}
