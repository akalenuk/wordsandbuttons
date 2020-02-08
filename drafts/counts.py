def comas(x):
  if len(x) > 3:
    return comas(x[:-3]) + ',' + x[-3:]
  return x

for i in range(5, 64+1):
  print("Then " + comas(str(pow(2, i-1))) + " on the " + str(i) + "th. ")

print(comas(str(pow(2, 64) - 1)))
