#include <stdio.h>
#include <stdlib.h>
#include <分数.h>
#include <複素数.h>
struct complex fraction_to_complex(struct fraction parsed)
{
	if (parsed.denominator == 0) {
		fprintf(stderr, "%sの%d行目：引数の分母が０です。\n", __FILE__, __LINE__);
		exit(1);
	}
	return (struct complex){parsed, int_to_fraction(0)};
}
struct complex int_to_complex(int parsed)
{
	return fraction_to_complex(int_to_fraction(parsed));
}
struct complex complex_sum(struct complex complex1, struct complex complex2)
{
	return (struct complex){fraction_sum(complex1.re, complex2.re), fraction_sum(complex1.im, complex2.im)};
}
struct complex complex_substract(struct complex substracted, struct complex substracting)
{
	return complex_sum(substracted, complex_product(int_to_complex(-1), substracting));
}
struct complex complex_product(struct complex complex1, struct complex complex2)
{
	return (struct complex){
		fraction_substract(fraction_product(complex1.re, complex2.re), fraction_product(complex1.im, complex2.im)),
		fraction_sum(fraction_product(complex1.re, complex2.im), fraction_product(complex2.re, complex1.im))
	};
}
struct complex complex_divide(struct complex divided, struct complex dividing)
{
	if (!dividing.re && !dividing.im) {
		fprintf(stderr, "%sの%d行目：除数が０です。\n", __FILE__, __LINE__);
		exit(1);
	}
	int denomoinator = dividing.re * dividing.re + dividing.im * dividing.im;
	return complex_product(
		divided,
		(struct complex){
			(struct fraction){denominator, dividing.re},
			(struct fraction){denominator, -dividing.im}
		}
	);
}