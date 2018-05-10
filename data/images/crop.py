from PIL import Image
import sys

if len(sys.argv) != 7:
    sys.exit()
    
img_name = sys.argv[1]
starting_point = (int(sys.argv[2]), int(sys.argv[3]))
ending_point = (int(sys.argv[4]), int(sys.argv[5]))
new_img_name = sys.argv[6]

img = Image.open(img_name)

index = 0
for char in img_name:
    if char == '.':
        img_name = img_name[:index]
        break
    index += 1

width = img.width
height = img.height

new_img = Image.new(img.mode, (ending_point[0] - starting_point[0], ending_point[1] - starting_point[1]))

for x in range(starting_point[0], ending_point[0]):
    for y in range(starting_point[1], ending_point[1]):
        pix = img.getpixel((x, y))
        new_img.putpixel((x - starting_point[0], y - starting_point[1]), pix)

new_img.save(new_img_name, "PNG")
