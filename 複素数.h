#pragma once
#include <分数.h>
struct complex {
	struct fraction re;
	struct fraction im;
};
struct complex fraction_to_complex(struct fraction);
struct complex int_to_complex(int);
struct complex complex_sum(struct complex, struct complex);
struct complex complex_substract(struct complex, struct complex);
struct complex complex_product(struct complex, struct complex);
struct complex complex_divide(struct complex, struct complex);