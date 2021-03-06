#include <stdio.h>

float calculate_tax(float taxable_inc);

int main(void)
{
    float taxable_inc, tax_amount;
    
    printf("Enter taxable income: ");
    scanf("%f", &taxable_inc);
    
    printf("Your tax due is $%f\n", calculate_tax(taxable_inc));
    
    return 0;
}

float calculate_tax(float taxable_inc)
{
    float tax_amount;
    
    if (taxable_inc < 750.0f)
        tax_amount = taxable_inc * 0.01f;
    else if (taxable_inc < 2250.0f)
        tax_amount = 7.50f + (taxable_inc - 750.0f) * 0.02f;
    else if (taxable_inc < 3750.0f)
        tax_amount = 37.50f + (taxable_inc - 2250.0f) * 0.03f;
    else if (taxable_inc < 5250.0f)
        tax_amount = 82.50f + (taxable_inc - 3750.0f) * 0.04f;
    else if (taxable_inc < 7000.0f)
        tax_amount = 142.50f + (taxable_inc - 5250.0f) * 0.05f;
    else
        tax_amount = 230.00f + (taxable_inc - 7000.0f) * 0.06f;
    
    return tax_amount;
}
