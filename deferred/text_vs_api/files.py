import os

def count_all_py_shell(path = '.'):
    return os.popen('ls -R "' + path +'" | grep ".py$" | wc -l').read()

def count_all_py(path = '.'):
    return len([1 for (_, _, files) in os.walk(path) for f in files if f.endswith('.py')])
    
print count_all_py()
