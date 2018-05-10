from PIL import Image
import sys

if len(sys.argv) != 3:
    sys.exit()
    
img_name = sys.argv[1]
new_img_name = sys.argv[2]
img = Image.open(img_name)

width = img.width
height = img.height

new_img = Image.new(img.mode, (2 * width, 2 * height))

for x in range(width):
    for y in range(height):
        pix = img.getpixel((x, y))
        new_img.putpixel((2 * x, 2* y), pix)
        new_img.putpixel((2 * x + 1, 2* y), pix)
        new_img.putpixel((2 * x, 2* y + 1), pix)
        new_img.putpixel((2 * x + 1, 2* y + 1), pix)

new_img.save(new_img_name, "PNG")
