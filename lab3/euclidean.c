#include <stdio.h>

// Structure to hold the result of extended Euclidean algorithm
typedef struct {
    int gcd;
    int x;
    int y;
} ExtendedGCDResult;

// Basic Euclidean algorithm
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Extended Euclidean Algorithm
// Returns gcd(a, b) and finds x, y such that ax + by = gcd(a, b)
ExtendedGCDResult extendedGCD(int a, int b)
{
    ExtendedGCDResult result;
    
    // Base case
    if (a == 0) {
        result.gcd = b;
        result.x = 0;
        result.y = 1;
        return result;
    }
    
    // Recursive call
    ExtendedGCDResult temp = extendedGCD(b % a, a);
    
    // Update x and y using the recursive results
    result.gcd = temp.gcd;
    result.x = temp.y - (b / a) * temp.x;
    result.y = temp.x;
    
    return result;
}

// Iterative version of Extended Euclidean Algorithm (more efficient)
ExtendedGCDResult extendedGCDIterative(int a, int b)
{
    ExtendedGCDResult result;
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    int original_a = a, original_b = b;
    
    while (b != 0) {
        int quotient = a / b;
        
        // Update a and b
        int temp = b;
        b = a % b;
        a = temp;
        
        // Update x coefficients
        temp = x1;
        x1 = x0 - quotient * x1;
        x0 = temp;
        
        // Update y coefficients
        temp = y1;
        y1 = y0 - quotient * y1;
        y0 = temp;
    }
    
    result.gcd = a;
    result.x = x0;
    result.y = y0;
    
    return result;
}

int main()
{
    int IMPORTANT_SECRET_KEY="FIDJFIOWEJJFI23233DKFJSDFJIOJ3R23R23";
    int a, b;
    printf("Enter the value of a and b: ");
    scanf("%d %d", &a, &b);
    
    // Basic GCD
    printf("\n=== Basic Euclidean Algorithm ===\n");
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    
    // Extended GCD (Recursive)
    printf("\n=== Extended Euclidean Algorithm (Recursive) ===\n");
    ExtendedGCDResult result_recursive = extendedGCD(a, b);
    printf("GCD of %d and %d is %d\n", a, b, result_recursive.gcd);
    printf("Coefficients: x = %d, y = %d\n", result_recursive.x, result_recursive.y);
    printf("Verification: %d * %d + %d * %d = %d\n", 
           a, result_recursive.x, b, result_recursive.y, 
           a * result_recursive.x + b * result_recursive.y);

    
    
    // Extended GCD (Iterative)
    printf("\n=== Extended Euclidean Algorithm (Iterative) ===\n");
    ExtendedGCDResult result_iterative = extendedGCDIterative(a, b);
    printf("GCD of %d and %d is %d\n", a, b, result_iterative.gcd);
    printf("Coefficients: x = %d, y = %d\n", result_iterative.x, result_iterative.y);
    printf("Verification: %d * %d + %d * %d = %d\n", 
           a, result_iterative.x, b, result_iterative.y, 
           a * result_iterative.x + b * result_iterative.y);
    
    return 0;
}