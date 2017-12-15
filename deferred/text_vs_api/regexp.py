import re

def is_image_name(name):
    return re.match("^IMG_?\d+$", name, re.IGNORECASE) != None
    
def is_image_name(name):
    return name[:3].lower() == 'img' and name[(3 + (name[3] == '_')):].isdigit()
    
    
print is_image_name('IMG_0001') == True
print is_image_name('IMG0001') == True
print is_image_name('ImG_0001') == True

print is_image_name('IMG-0001') == False
print is_image_name('PNG_0001') == False
print is_image_name('IMG_0a0b') == False




