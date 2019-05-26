from sympy import *

ax, bx, cx, dx, ay, by, cy, dy, t = symbols('ax bx cx dx ay by cy dy t')
speed_t = diff((3*ax*t**2 + 2*bx*t + cx)**2 + (3*ay*t**2 + 2*by*t + cy)**2, t )
print('speed by t expression: ')
print(speed_t)
print('\n')

constant_speed_eq = integrate(abs(speed_t), (t, 0, 1))
print('constant speed equation: ')
print(constant_speed_eq)
print('\n')

# p0 => t = 0; p1 => t = 1
p0x, p0y, p1x, p1y, p0dx, p0dy, p1dy_to_dx = symbols('p0x p0y p1x p1y p0dx p0dy p1dy_to_dx')

point0_x_eq = dx - p0x
point0_y_eq = dy - p0y
point1_x_eq = ax + bx + cx + dx - p1x
point1_y_eq = ay + by + cy + dy - p1y

point0_dx_eq = cx - p0dx
point0_dy_eq = cy - p0dy

point1_dy_to_dx_eq = 3*ay + 2*by + cy - p1dy_to_dx*(3*ax + 2*bx + cx)

solution = solve([constant_speed_eq, point0_x_eq, point0_y_eq, point1_x_eq, point1_y_eq, point0_dx_eq, point0_dy_eq, point1_dy_to_dx_eq], (ax, bx, cx, dx, ay, by, cy, dy))

print('solution: ')
print(solution)
print('\n')
