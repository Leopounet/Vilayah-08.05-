from PIL import Image
import sys

def is_in_list(sprite, img_list):
    found = True
    for img in img_list:
        for x in range(32):
            for y in range(32):
                pix = sprite.getpixel((x, y))
                pix2 = img.getpixel((x, y))
                if pix2 != pix:
                    found = False
                    continue
        if found == True:
            return True
        else:
            found = True
    return False

if len(sys.argv) != 3:
    sys.exit()
    
img_name = sys.argv[1]
new_img_name = sys.argv[2]
img = Image.open(img_name)

width = img.width
height = img.height

new_img = Image.new(img.mode, (width, height))

sprite = Image.new(img.mode, (32, 32))
sprite_list = []

for x in range(int(width / 32)):
    for y in range(int(height / 32)):
        for x2 in range(32):
            for y2 in range(32):
                pix = img.getpixel((x * 32 + x2, y * 32 + y2))
                sprite.putpixel((x2, y2), pix)
        if not is_in_list(sprite, sprite_list):
            sprite_list.append(sprite.copy())
    print("{}% done!".format(int(25 * (x+1) / (width / 64.0))))



x_count = 0
y_count = 0
percent = 0
for sprite in sprite_list:
    for x in range(32):
        for y in range(32):
            pix = sprite.getpixel((x, y))
            # print("x: {} y: {}".format(x + x_count * 32, y + y_count * 32))
            new_img.putpixel((x + x_count , y + y_count), pix)
    x_count += 32
    if x_count + 32 > width:
        x_count = 0
        y_count += 32
    percent += 1
    print("{}% done!".format(int(50 + 25 * percent / (len(sprite_list) / 2.0))))
            

new_img.save(new_img_name, "PNG")
