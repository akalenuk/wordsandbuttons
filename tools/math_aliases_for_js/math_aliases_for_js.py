source = """
Properties

Math.E
    Euler's constant and the base of natural logarithms; approximately 2.718.
Math.LN2
    Natural logarithm of 2; approximately 0.693.
Math.LN10
    Natural logarithm of 10; approximately 2.303.
Math.LOG2E
    Base 2 logarithm of E; approximately 1.443.
Math.LOG10E
    Base 10 logarithm of E; approximately 0.434.
Math.PI
    Ratio of the a circle's circumference to its diameter; approximately 3.14159.
Math.SQRT1_2
    Square root of ½ (or equivalently, 1/√2); approximately 0.707.
Math.SQRT2
    Square root of 2; approximately 1.414.

Methods

Note that trigonometric functions (sin(), cos(), tan(), asin(), acos(), atan(), atan2()) expect (and return) angles in radians.

To convert radians to degrees, divide by (Math.PI / 180). Multiply by the same value to convert degrees to radians.

Note: Many Math functions have a precision that’s implementation-dependent. This means that different browsers can give a different result. Even the same JavaScript engine on a different OS or architecture can give different results!

Math.abs(x)
    Returns the absolute value of a number.
Math.acos(x)
    Returns the arccosine of a number.
Math.acosh(x)
    Returns the hyperbolic arccosine of a number.
Math.asin(x)
    Returns the arcsine of a number.
Math.asinh(x)
    Returns the hyperbolic arcsine of a number.
Math.atan(x)
    Returns the arctangent of a number.
Math.atanh(x)
    Returns the hyperbolic arctangent of a number.
Math.atan2(y, x)
    Returns the arctangent of the quotient of its arguments.
Math.cbrt(x)
    Returns the cube root of a number.
Math.ceil(x)
    Returns the smallest integer greater than or equal to a number.
Math.clz32(x)
    Returns the number of leading zeroes of a 32-bit integer.
Math.cos(x)
    Returns the cosine of a number.
Math.cosh(x)
    Returns the hyperbolic cosine of a number.
Math.exp(x)
    Returns Ex, where x is the argument, and E is Euler's constant (2.718…, the base of the natural logarithm).
Math.expm1(x)
    Returns subtracting 1 from exp(x).
Math.floor(x)
    Returns the largest integer less than or equal to a number.
Math.fround(x)
    Returns the nearest single precision float representation of a number.
Math.hypot([x[, y[, …]]])
    Returns the square root of the sum of squares of its arguments.
Math.imul(x, y)
    Returns the result of a 32-bit integer multiplication.
Math.log(x)
    Returns the natural logarithm (㏒e; also, ㏑) of a number.
Math.log1p(x)
    Returns the natural logarithm (㏒e; also ㏑) of 1 + x for a number.
Math.log10(x)
    Returns the base 10 logarithm of a number.
Math.log2(x)
    Returns the base 2 logarithm of a number.
Math.max([x[, y[, …]]])
    Returns the largest of zero or more numbers.
Math.min([x[, y[, …]]])
    Returns the smallest of zero or more numbers.
Math.pow(x, y)
    Returns base to the exponent power, that is, xy.
Math.random()
    Returns a pseudo-random number between 0 and 1.
Math.round(x)
    Returns the value of a number rounded to the nearest integer.
Math.sign(x)
    Returns the sign of the x, indicating whether x is positive, negative, or zero.
Math.sin(x)
    Returns the sine of a number.
Math.sinh(x)
    Returns the hyperbolic sine of a number.
Math.sqrt(x)
    Returns the positive square root of a number.
Math.tan(x)
    Returns the tangent of a number.
Math.tanh(x)
    Returns the hyperbolic tangent of a number.
Math.toSource()
    Returns the string "Math".
Math.trunc(x)
    Returns the integer part of the number x, removing any fractional digits. 
"""

print("// Math. aliases")
aliases = []
for line in source.split('\n'):
	if line.startswith('Math.'):
		entity = line[5:].split('(')[0]
		aliases += ["const " + entity + " = Math." + entity + ";"]

aliases.sort(key = lambda x : len(x))

# output
out = ""
for alias in aliases:
	if len(out) + len(alias) + (0 if out=="" else 1) < 80:
		out += ('' if out=="" else '\t') + alias
	else:
		print(out)
		out = ''
print(out)

